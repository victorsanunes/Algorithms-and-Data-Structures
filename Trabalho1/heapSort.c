//HeapSort
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
//Funcao que realizara a troca de variaveis
void swap(int vetor[], int a, int b){
    int aux;
    aux = vetor[a];
    vetor[a] = vetor[b];
    vetor[b] = aux;
    }

void refaz(int vetor[], int i, int tam){
    //printf("\n\nRefaz...");
    //i eh o indice violado
    int filho = 2*i + 1;
    int aux, pos;
    //O procedimento eh chamado ate que atinja uma folha ou a condicao de heap seja confirmada
    if ( (filho <= tam - 1) || (filho + 1 <= tam - 1) && (vetor[i] < vetor[filho] || vetor[i] < vetor[filho + 1]) ){
        //Checagem da existencia do filho a direita
        if (filho + 1 <= tam - 1 ){
            //Checa se o da esquerda eh o maior
            if ( (vetor[filho] >= vetor[filho + 1]) && (vetor[filho] >= vetor[i]) ){
                pos = filho;
                aux = vetor[i];
                vetor[i] = vetor[filho];
                vetor[filho] = aux;
                refaz(vetor, pos, tam);
            }
            //Filho da direita eh o maior
            else if ( (vetor[filho + 1] >= vetor[filho]) && (vetor[filho + 1] >= vetor[i]) ){
                pos = filho + 1;
                aux = vetor[i];
                vetor[i] = vetor[filho + 1];
                vetor[filho + 1] = aux;
                refaz(vetor, pos, tam);
            }
        }
        //Caso o filho da direita nao exista
        else {
            //Checa se o filho da esquerda eh maior que o pai
            if (vetor[filho] >= vetor[i]) {
                pos = filho;
                refaz(vetor, pos, tam);
                aux = vetor[i];
                vetor[i] = vetor[filho];
                vetor[filho] = aux;
                //i = filho;

            }
        }
    }
}

void constroi (int vetor[], int tam){
    //printf("\nConstroi");
    int esq = (tam - 1)/2 ;
    while (esq >= 0){
        //printf("\nesq = %d", vetor[esq]);
        refaz(vetor, esq, tam);
        esq--;
    }
}

void heapSort(int vetor[], int tam){
    int i = tam-1, aux;
    constroi(vetor, tam);
    while (i > 0){
        //swap(vetor, 0, i);
        aux = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = aux;
        //Chama o refaz() do comeco do vetor ate o ultimo elemento nao ordenado
        refaz(vetor, 0, i );
        i--;
    }
}

void printArray(int A[], int size){
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void generateRandomArray(int array[], int n){
	int i;
	for(i = 0; i < n; i++){
		array[i] = rand() % 1001;
	}
}

int *read_ints(int *size, char *input_file){
    //FILE *file = fopen("POPULACAO_INICIAL - FORMATADA.txt", "r");
    FILE *file = fopen(input_file, "r");
    //Conjunto de dados a ser lido
    int *dataset = malloc(MAX_SIZE * sizeof(int));
    int i = 0;

    //Variavel com a quantidade de numeros lidos
    *size = 0;
    //Realiza leitura do arquivo file e armazena o valor na posicao i do dataset
    fscanf(file, "%d", &dataset[i]);

    //feof(filename) eh uma funcao que verifica o fim do arquivo
    while(!feof(file)){
        //printf("%d ", dataset[i]);
        i++;
        fscanf(file, "%d", &dataset[i]);

        (*size)++;
    }
    fclose(file);
    return dataset;
}

void main(){
    clock_t ini_sort, fim_sort;
    double tempoSort, tempoBus;
    int length; 
	//int array[n] = {5, 8, 12, 4, 3, 2, 21, 10, 16, 9};
	int *array = read_ints(&length, "populacao_sem_plano_diretor-2010.txt");
    
    ini_sort = clock();
    heapSort(array, length);
    fim_sort = clock(); 
    
    tempoSort = fim_sort-ini_sort;
    printf("Tempo para ordenacao: %.2f", tempoSort);
}
