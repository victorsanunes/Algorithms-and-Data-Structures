#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 1000000

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

void insertionSort(int array[], int size){
	int i, j, aux;
	for(i = 1; i < size; i++){
		j = i - 1;
		while((array[j+1] < array[j]) && j >= 0){
			aux = array[j];
			array[j] = array[j+1];
			array[j+1] = aux;
			j--;
		}
	}
}

void generateRandomArray(int array[], int n){
	int i;
	for(i = 0; i < n; i++){
		array[i] = rand() % 1001;
	}
}

void printArray(int array[], int size){
	int i;
	for(i = 0; i < size; i++){
		printf("%d ", array[i]);
	}

}
void main(){
    clock_t ini_sort, fim_sort;
    double tempoSort, tempoBus;
    int length;
	//int array[n] = {5, 8, 12, 4, 3, 2, 21, 10, 16, 9};
	int *array = read_ints(&length, "pib_sem_plano_diretor-2010.txt");

    ini_sort = clock();
    insertionSort(array, length);
    fim_sort = clock();

    tempoSort = fim_sort-ini_sort;
    printf("Tempo para ordenacao: %.2f", tempoSort);
}
