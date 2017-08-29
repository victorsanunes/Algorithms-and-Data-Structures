#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 2000001
#define MAX_CHARS 200
#define MAX_LINES 2

/*
//Funcao que realizara a troca de variaveis
void swap(char vetor[], int a, int b){
    int aux;
    aux = vetor[a];
    vetor[a] = vetor[b];
    vetor[b] = aux;
    }

void refaz(char vetor[], int i, int tam){
    //printf("\n\nRefaz...");
    //i eh o indice violado
    int filho = 2*i + 1;
    char aux, pos;
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

void printArray(int A[], int size){
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}*/

void replace( char *c ){

    if( c < 65 || (c > 90 && c < 97) || c > 122) 
	c = 32;
}

char **inputText(){
    int i = 0;
    int j = 0;
    char word[100], c;
    char text[MAX_LINES][MAX_CHARS + 1];
    while (scanf("%c", &c) != EOF){
	replace(&c);
	if( c != 32 ){
	    word[i++] = tolower(c);
	    word[i] = '\0';
	}
	text[j] = word; 
	j++;
    }
    return text; 
    
}

int main(){
    int i;
    char text = inputText();

    return 0;
}
