#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TAM 50
#define MAX_SIZE 1000000

typedef struct name{
	char word [TAM];
} name;

//Funcao que realizara a troca de variaveis
void swap(char *a, char *b){
    char *aux = (char*)malloc(TAM * sizeof(char));
    //aux = vetor[a].word;
    strcpy(aux, a);
    
    //vetor[a].word = vetor[b].word;
    strcpy(a, b);
    
    //vetor[b].word = aux;
    strcpy(b, aux);
    free(aux);
}

name *read_string(int *size, char *input_file){
    
    FILE *file = fopen(input_file, "r");
    
    //Conjunto de dados a ser lido
    name *dataset = malloc(MAX_SIZE * sizeof(name));
    int i = 0;
    char buffer[TAM];
    
    //Variavel com a quantidade de numeros lidos
    (*size) = 0;
    
    //Realiza leitura do arquivo file e armazena o valor na posicao i do dataset
  
    fscanf(file, "%s", &buffer);
    buffer[strlen(buffer)] = '\0'; 
    strcpy(dataset[i].word, buffer); 

    //feof(filename) eh uma funcao que verifica o fim do arquivo
    while((*size) < MAX_SIZE){
        //printf("%d ", dataset[i]);
        i++;
        if( fscanf(file, "%s", &buffer) != 1){
	    break; 
	}
        buffer[strlen(buffer)] = '\0'; 
        strcpy(dataset[i].word, buffer); 
        (*size)++;
    }
    fclose(file);
    return dataset;
}


void insertionSort(name array[], int size){
    int i, j, k;
    for(i = 1; i < size; i++){
	j = i - 1;
	k = strcmp(array[j+1].word, array[j].word); 
	while( (k < 0) && (j >= 0) ){
	    swap(array[j].word, array[j+1].word);
	    j--;
	    k = strcmp(array[j+1].word, array[j].word); 
	}
    }
    
}

void printStringArray(name A[], int size){
    int i;
    for (i=0; i < size; i++)
        puts(A[i].word);
}

void main(){
    clock_t ini_sort, fim_sort;
    double tempoSort, tempoBus;
    int length; 
    name *array = read_string(&length, "nomes.txt");
    printStringArray(array, length); 
    insertionSort(array, length);
    
    /*ini_sort = clock();
    
    fim_sort = clock(); 
    
    tempoSort = fim_sort-ini_sort;
    printf("Tempo para ordenacao: %.2f", tempoSort);
*/
}
