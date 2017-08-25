//QuickSort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandomArray(int array[], int n){
	int i;
	for(i = 0; i < n; i++){
		array[i] = rand() % 1001;
	}
}

void lerDados(int vetor[], int tam){
    int i; 
    for (i = 0; i < tam; i++){
        scanf("%d", &vetor[i]);
    }
}

//Funcao que realizara a troca de variaveis
void swap(int vetor[], int a, int b){
    int aux;
    aux = vetor[a];
    vetor[a] = vetor[b];
    vetor[b] = aux;
    }

void printArray(int A[], int size){
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
//retorna a posicao do pivo escolhido
//pivo eh escolhido como a mediana entre 3 elementos
/*int escolhePivo(int vetor[], int ini, int tam){
    int n1 = (tam - 1 - ini)/2;
    int maior;
    if (vetor[ini] >= vetor[n1] && (vetor[ini] >= vetor[tam-1]) ){
        if (vetor[n1] > vetor[tam -1] ){
            return n1;
            }
            else return tam - 1;
        }
    else if(vetor[tam - 1] >= vetor[n1] && (vetor[tam - 1] >= vetor[ini]) ) {
        if (vetor[n1] >= vetor[ini]){
            return n1; 
            }
            else return ini; 
        }
    else if(vetor[n1] >= vetor[ini] && (vetor[n1] >= vetor[tam - 1]) ) {
        if (vetor[ini] >= vetor[tam - 1]){
            return ini; 
            }
            else return tam - 1; 
        }
    
    
}*/

//Retorna a posicao correta do pivo 
int partition (int arr[], int l, int h){
	//x eh o pivo do vetor
    int x = arr[h - 1];
    int i = (l - 1);
    int j, aux;
 
    for (j = l; j < h - 1; j++){
        if (arr[j] <= x){
            /*i++;
            swap (&arr[i], &arr[j]);*/
            i++;
            aux = arr[i]; 
            arr[i] = arr[j];
            arr[j] = aux; 
        }
    }
    //Coloca o pivo na posicao certa
    //swap (&arr[i + 1], &arr[h - 1]);
            i++; 
            aux = arr[i]; 
            arr[i] = arr[h - 1];
            arr[h - 1] = aux;
    return (i) ;
}
 
/* A[] --> vetor a ser ordenado, 
  l  --> Indice do inicio, 
  h  --> Indice do fim */
 
void quickSort_ordena(int A[], int l, int h){
    if (l < h - 1){        
        //Indice de particao 
        int p = partition(A, l, h); 
        //printf("\nparticao() = %d\n", A[p]);
        quickSort_ordena(A, l, p );  
        quickSort_ordena(A, p+1, h);
    }
}
 
void quickSort(int vetor[], int tam) {
	quickSort_ordena(vetor, 0, tam); 
	}

  
int main(){
	// int N; 
	// scanf("%d", &N);
	// int vetor[N];
	// int *vetor = (int*)malloc(sizeof(int)*N); 
	// lerDados(vetor, N);
	srand(1);
	int N = 10; 
	int vetor[N]; 
	//int array[n] = {5, 8, 12, 4, 3, 2, 21, 10, 16, 9};
	generateRandomArray(vetor, N);
	partition(vetor, 0, N);
	printArray(vetor, N);
	quickSort(vetor, N);
	printArray(vetor, N);  
	return 0; 
	}
//11 25 40 55 20 44 35 38 99 10 65 50


