#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gnomeSort(int array[], int size){
    int i, aux;
    i = 1;
    while(i < size){
        if(array[i] >= array[i-1]){
            i++;
        }
        else{
            aux = array[i];
            array[i] = array[i-1];
            array[i-1] = aux;
            i--;
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
	gnomeSort(array, n);
	printf("\n\nSorted array: ");
	printArray(array, n);

}
