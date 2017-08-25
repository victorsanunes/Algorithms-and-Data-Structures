#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
	srand(1);
	int n = 10;
	int array[n];
	//int array[n] = {5, 8, 12, 4, 3, 2, 21, 10, 16, 9};
	generateRandomArray(array, n);
	printf("Original array: ");
	printArray(array, n);
	insertionSort(array, n);
	printf("\n\nSorted array: ");
	printArray(array, n);

}
