#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 1000

typedef struct words{
    char word [TAM];
} words;

int isLetter(char c){
    if( c < 65 || (c > 90 && c < 97) || c > 122) 
	return 0;
    else
	return 1; 
}

void encryptMessage(char *originalMessage){
    int length, i, j;
    int aux; 
    length = strlen(originalMessage);
    //printf("%d\n", length);
    /*Primeira passada: desloca 3 posicoes na tabela ASCII dos caracteres
     * que forem letras*/
    for(i = 0; i <= length-1; i++){
	if(isLetter(originalMessage[i]))
	    originalMessage[i] += 3; 
    }
    //puts(originalMessage);
    /*Segunda passada: inverter os caracteres*/   
    for(i = 0, j = length - 1; i < j; i++, j--){
	aux = originalMessage[i];
	originalMessage[i] = originalMessage[j];
	originalMessage[j] = aux; 
    }
    //puts(originalMessage);
    /*Terceira passada: deslocar uma posicao a esquerda dos caracteres
     * a partir da segunda metade*/
    for(i = length/2; i <= length - 1; i++){
	originalMessage[i] -= 1;
    }
    puts(originalMessage);
}

int main(){
    int N, i;
    do{
	scanf("%d", &N);
    }while(N < 1 || N > 10000); 
    words wordsArray[N];
    
    for(i = 0; i < N; i++){
	fgets (wordsArray[i].word, TAM, stdin);
	do{
	    scanf("%[^\n]s", wordsArray[i].word);
	    
	}while(strlen(wordsArray[i].word) > TAM);

    }
    for(i = 0; i < N; i++){
	encryptMessage(wordsArray[i].word);
    }
    return 0;     
}
