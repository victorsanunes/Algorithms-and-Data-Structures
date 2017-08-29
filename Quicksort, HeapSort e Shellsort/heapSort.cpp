#include <iostream>

using namespace std;

void constroi (int vetor[], int tam){
    //printf("\nConstroi");
    int esq = (tam - 1)/2 ;
    while (esq >= 0){
        //printf("\nesq = %d", vetor[esq]);
        refaz(vetor, esq, tam);
        esq--; 
    }
}

//Funcao que realizara a troca de variaveis
void swap(int vetor[], int a, int b){
    int aux;
    aux = vetor[a];
    vetor[a] = vetor[b];
    vetor[b] = aux;
    }
