#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 11

typedef struct words{
    char word [TAM];
} words;

void swap(char *x, char *y){
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void printCharMatrix(words *array, int n){
    int i;
    for(i = 0; i < n; i++){
	printf("%s\n", array[i].word);
    }
}

void sortString(char* inputString, char* outputArray){
    
    int counterArray[256] ={0};
    int length, counter, index;
    length = strlen(inputString);
    
    
    for(counter = 0; counter < length; counter++){
        counterArray[inputString[counter]]++;
    }
    
    for(counter = 0, index = 0; counter < 256; counter++){
        if(counterArray[counter] != 0){
            while(counterArray[counter] > 0){
                outputArray[index++] = counter;
                counterArray[counter]--;
            }
        }
    }
    outputArray[index] = '\0';
}

/*void permute(char *a, int l, int r){
    int i;
    if (l == r)
	printf("%s\n", a);
    else{
	for (i = l; i <= r; i++){
	    swap((a+l), (a+i));
	    permute(a, l+1, r);
	    swap((a+l), (a+i)); 
	}
    }
}*/

void permutate( char *str, int index ){
    int i = 0;
    static lastChar = 0;
    if( index == strlen(str) ){ 
        printf("%s\n", str);
        return;
    }
    
    permutate( str, index + 1 );
    lastChar = str[index];
    for( i = index + 1; i < strlen(str); i++ ){
        if( lastChar == str[i] ) {
            continue;
        } 
	else {
            lastChar = str[i];
        }
        swap( &str[index], &str[i] ); 
        permutate( str, index + 1 );
        swap( &str[index], &str[i] );
    }
}

int main(){
    int N, i, size = 0;
    scanf("%d", &N);
    words wordsArray[N];
    char *a;
    char b[TAM]; 
    
    for(i = 0; i < N; i++){
	do{
	    scanf("%s", wordsArray[i].word);
	}while(strlen(wordsArray[i].word) > 10);
    }     
    
    for(i = 0; i < N; i++){
	a = wordsArray[i].word; 
	sortString(a, b);
	//printf("Sorted: %s\n", b); 
	size = strlen(b);
	permutate(b, 0);
	printf("\n"); 	
    }    
}

