#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shellSort(int arr[], int num){
    int i, j, k, tmp;
    for (i = num / 2; i > 0; i = i / 2){
        for (j = i; j < num; j++){
            for(k = j - i; k >= 0; k = k - i){
                if (arr[k+i] >= arr[k])
                    break;
                else{
                    tmp = arr[k];
                    arr[k] = arr[k+i];
                    arr[k+i] = tmp;
                }
            }
        }
    }
}

void generateRandomArray(int array[], int n){
	int i;
	for(i = 0; i < n; i++){
		array[i] = rand() % 1001;
	}
}

void printArray(int A[], int size){
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main(){
	srand(1);
	int N = 10;
	int vetor[N];
	//int array[n] = {5, 8, 12, 4, 3, 2, 21, 10, 16, 9};
	generateRandomArray(vetor, N);
	printf("Original array\n");
    printArray(vetor, N);
	shellSort(vetor, N);
	printf("\nSorted array is \n");
    printArray(vetor, N);
	return 0;
	}
