#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int INPUT_SIZE = 20;
const int BUCKET_K = 1000;

void printArray(int *input, int size){
    for ( int i = 0; i < size; i++ )
        cout << input[i] << " ";
    cout << endl;
}

void countingsort(int* input, int size){
    int CountArr[BUCKET_K] = { 0 };

    for (int i=0;i<size;i++){
        CountArr[input[i]]++;
    }

    int outputindex=0;
    for (int j=0;j<BUCKET_K;j++){
        while (CountArr[j]--)
            input[outputindex++] = j;
    }
}

void generateRandomArray(int *array, int n){
	int i;
	for(i = 0; i < n; i++){
		array[i] = rand() % 1001;
	}
}


int main(){

    srand(1);
    int n = 10;
    int array[n];
    generateRandomArray(array, n);
    cout << "Original array: ";
    printArray(array, n);
    countingsort(array, n);
    cout << "Sorted array: ";
    printArray(array, n);
    return 0;
}
