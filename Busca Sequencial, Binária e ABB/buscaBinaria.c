#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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

int binarySearch(int array[], int length, int element){
    int i, result = -1;
    int l, r;
    l = 0;
    r = length-1;
    i = (r+l)/2;
    while(i >= 0 && i < length && l <= r){
	if(element > array[i]){
	    l = i+1;
	    i = (r+l)/2; 
	}
	else if(element < array[i]){
	    r = i-1;
	    i = (r+l)/2; 
	}
	else if(element == array[i]){
	    i = length;
	    result = 1; 
	}
	
	/*else if(i < 0 || i > length){
	    result = -1;
	}*/
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


void main(){
    srand(1);
    clock_t inicioBusca, fimBusca;
    double tempoBusca;
    int n = 1000;
    int i;
    int array[n];
    generateRandomArray(array, n);
    heapSort(array, n);
     
    inicioBusca = clock();
    i = binarySearch(array, n, array[0]);
    fimBusca = clock();
    tempoBusca = fimBusca - inicioBusca; 
    printf("Tempo de busca do menor: %.6f\n", tempoBusca);
    
    inicioBusca = clock();
    i = binarySearch(array, n, array[n-1]);
    fimBusca = clock();
    tempoBusca = fimBusca - inicioBusca; 
    printf("Tempo de busca do menor: %.6f\n", tempoBusca);

}

