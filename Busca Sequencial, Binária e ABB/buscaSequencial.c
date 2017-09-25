#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sequentialSearch(int array[], int length, int element){
    int i, result = -1;
    i = 0;
    for(i = 0; i < length; i++){
        if(array[i] == element){
            result = 1;
            i = length;
        }
    }
    return result;
}

void generateRandomArray(int array[], int n){
	int i;
	for(i = 0; i < n; i++){
		array[i] = rand() % 10001;
	}
}

void printArray(int array[], int size){
	int i;
	for(i = 0; i < size; i++){
		printf("%d ", array[i]);
	}
	printf("\n"); 

}

void checkIfElementExists(int flag){
    if(flag == 1){
	printf("Element found\n");
    }
    else{
	printf("Element not found\n");
    }
}

int findSmallestElement(int array[], int length){
    int smallest;
    int i;
    smallest = array[0];
    i = 1;
    while(i < length){
	if(array[i] < smallest){
	    smallest = array[i]; 
	}
	i++;
    }
    return smallest; 
}

int findGreatestElement(int array[], int length){
    int greatest;
    int i;
    greatest = array[0];
    i = 1;
    while(i < length){
	if(array[i] > greatest){
	    greatest = array[i]; 
	}
	i++;
    }
    return greatest; 
}

void main(){
    srand(1);
    clock_t inicioBusca, fimBusca;
    double tempoBusca;
    int n = 1000;
    int i;
    int array[n];

    generateRandomArray(array, n);
    //printf("Original array: ");
    //printArray(array, n);
    
    inicioBusca = clock();
    i = findSmallestElement(array, n);
    fimBusca = clock();
    tempoBusca = fimBusca - inicioBusca; 
    printf("Tempo de busca do menor: %.6f\n", tempoBusca);
    
    inicioBusca = clock();
    i = findGreatestElement(array, n);
    fimBusca = clock();
    tempoBusca = fimBusca - inicioBusca; 
    printf("Tempo de busca do maior: %.6f\n", tempoBusca);
}
