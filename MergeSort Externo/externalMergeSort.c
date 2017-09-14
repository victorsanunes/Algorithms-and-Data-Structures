#include <stdio.h>
#include <stdlib.h>
#define INPUT_FILE "input.txt"

int *readNumbersFromFile(char *filename){
    //FILE *file = fopen("POPULACAO_INICIAL - FORMATADA.txt", "r");
    FILE *file = fopen(filename, "r");
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
void writeNumbersInFile(char *filename, int array)

void main(){

    srand(1);
	int N = 10;
	int array[N];
	//int array[n] = {5, 8, 12, 4, 3, 2, 21, 10, 16, 9};
	generateRandomArray(array, N);
	printf("Original array\n");
    printArray(array, N);
    heapSort(array, N);

    printf("\nSorted array is \n");
    printArray(array, N);
}
