//HeapSort
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAM 50
#define MAX_SIZE 1000000

typedef struct name{
	char word [TAM];
} name;


//Funcao que realizara a troca de variaveis
void swap(name vetor[], int a, int b){
    char *aux = malloc(TAM * sizeof(char));
    //aux = vetor[a].word;
    strcpy(aux, vetor[a].word);
    
    //vetor[a].word = vetor[b].word;
    strcpy(vetor[a].word, vetor[b].word);
    
    //vetor[b].word = aux;
    strcpy(vetor[b].word, aux);
    free(aux);
}

void refaz(name vetor[], int i, int tam){
    //printf("\n\nRefaz...");
    //i eh o indice violado
    int filho = 2*i + 1;
    int aux, pos;
    //O procedimento eh chamado ate que atinja uma folha ou a condicao de heap seja confirmada
    if ( ((filho <= tam - 1) || (filho + 1 <= tam - 1) ) && ( strcmp(vetor[i].word, vetor[filho].word) < 0 || strcmp(vetor[i].word, vetor[filho + 1].word) < 0) ){
        //Checagem da existencia do filho a direita
        if (filho + 1 <= tam - 1 ){
            //Checa se o da esquerda eh o maior
            if ( (strcmp(vetor[filho].word, vetor[filho + 1].word) >= 0) && (strcmp(vetor[filho].word, vetor[i].word) >= 0) ){
                pos = filho;
                swap(vetor, i, filho);
                /*aux = vetor[i].word;
                vetor[i].word = vetor[filho].word;
                vetor[filho].word = aux;*/
                refaz(vetor, pos, tam);
            }
            //Filho da direita eh o maior
            else if ( (strcmp(vetor[filho+1].word, vetor[filho].word) >= 0) && (strcmp(vetor[filho+1].word, vetor[i].word) >= 0) ){
                pos = filho + 1;
                swap(vetor, filho+1, i);
                /*aux = vetor[i].word;
                vetor[i].word = vetor[filho + 1].word;
                vetor[filho + 1].word = aux;*/
                refaz(vetor, pos, tam);
            }
        }
        //Caso o filho da direita nao exista
        else {
            //Checa se o filho da esquerda eh maior que o pai
            if (strcmp(vetor[filho].word, vetor[i].word) >= 0) {
                pos = filho;
                refaz(vetor, pos, tam);
                /*aux = vetor[i].word;
                vetor[i].word = vetor[filho].word;
                vetor[filho].word = aux;*/
                swap(vetor, i, filho);
                //i = filho;

            }
        }
    }
}

void constroi (name vetor[], int tam){
    //printf("\nConstroi");
    int esq = (tam - 1)/2 ;
    while (esq >= 0){
        //printf("\nesq = %d", vetor[esq]);
        refaz(vetor, esq, tam);
        esq--;
    }
}

void heapSort(name vetor[], int tam){
    int i = tam-1;
    char *aux;
    constroi(vetor, tam);
    while (i > 0){
        swap(vetor, 0, i);
        /*aux = vetor[0].word;
        vetor[0].word = vetor[i].word;
        vetor[i].word = aux;*/
        //Chama o refaz() do comeco do vetor ate o ultimo elemento nao ordenado
        refaz(vetor, 0, i );
        i--;
    }
}

void printStringArray(name A[], int size){
    int i;
    for (i=0; i < size; i++)
        printf("%s ", A[i].word);
    printf("\n");
}

void generateRandomArray(int array[], int n){
	int i;
	for(i = 0; i < n; i++){
		array[i] = rand() % 1001;
	}
}

name *read_string(int *size, char *input_file){
    
    FILE *file = fopen(input_file, "r");
    
    //Conjunto de dados a ser lido
    name *dataset = malloc(MAX_SIZE * sizeof(name));
    int i = 0;
    char buffer[TAM];
    
    //Variavel com a quantidade de numeros lidos
    *size = 0;
    
    //Realiza leitura do arquivo file e armazena o valor na posicao i do dataset
  
    fscanf(file, "%s", &dataset[i].word);
    buffer[strlen(buffer)] = '\0'; 
    strcpy(buffer, dataset[i].word); 
    

    //feof(filename) eh uma funcao que verifica o fim do arquivo
    while(!feof(file)){
        //printf("%d ", dataset[i]);
        i++;
        fscanf(file, "%s", &dataset[i].word);
        buffer[strlen(buffer)] = '\0'; 
        strcpy(buffer, dataset[i].word); 
        (*size)++;
    }
    fclose(file);
    return dataset;
}

void main(){
    clock_t ini_sort, fim_sort;
    double tempoSort, tempoBus;
    int length; 
	name *array = read_string(&length, "nomes_dos_municipios.txt");
        
    ini_sort = clock();
    heapSort(array, length);
    fim_sort = clock(); 
    
    tempoSort = fim_sort-ini_sort;
    printf("Tempo para ordenacao: %.2f", tempoSort);
}
