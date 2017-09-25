#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct element{
    int key;
    //int value; 
    struct element *left, *right;
}element;

typedef struct tree{
    element *root; 
}tree;

void printNode(element *e){
    if(e != NULL){
	printf("key=%d\n", e->key);
	//printf("value=%d\n", e->value);
    }
}

void generateRandomArray(int array[], int n){
    int i;
    for(i = 0; i < n; i++){
	array[i] = rand() % 1001;
    }
}

void checkIfElementExists(element *flag){
    if(flag != NULL){
	printf("Element %d found\n", flag->key);
    }
    else{
	printf("Element not found\n");
    }
}

element *createNode(int key){
    element *node = malloc(sizeof(element));
    node->key = key;
    //node->value = value;
    node->left = NULL;
    node->right = NULL; 
    return node; 
}

tree *createTree(){
    tree *t = malloc(sizeof(tree));
    t->root = NULL; 
    return t; 
}

void insertNode(element **r, int key){
    element *aux; 
    if( (*r) == NULL){
	//puts("chegou");
	aux = createNode(key);
	(*r) = aux; 
	return; 
    }
    
    if(key > (*r)->key){
	//puts("direita");
	insertNode(&((*r)->right), key);
    }
    else if(key < (*r)->key){
	//puts("esquerda");
	insertNode(&((*r)->left), key);
    }
    
    else{
	return;
    }
}

element *searchNode(element *r, int key){
    element *aux = r; 
    if( aux != NULL){

	//puts("Arvore nao nula");
	if( key > aux->key){
	    //puts("chave maior");
	    return searchNode(aux->right, key);
	}
	else if( key < aux->key){
	    //puts("chave menor");
	    return searchNode(aux->left, key);
	}
	else if( key == aux->key){
	    //printf("Encontrou %d\n\n", aux->key);
	    return aux; 
	}
    }
    
    if( aux == NULL){
	return NULL; 
    }
}

// Busca menor elemento da subarvore direita
element *getGreaterSuccessor(element *rightTree){
    element *aux = rightTree->left; 
    while(aux->left != NULL){
	aux = aux->left; 
    }
    return aux; 
}

void removeNode(element **r, int key){
    element *elementToBeRemoved, *aux, *aux2;
    elementToBeRemoved = searchNode((*r), key); 
    if(elementToBeRemoved != NULL){
	// Checa se o no tem filho direito
	if(elementToBeRemoved->right != NULL){
	    //Checa se nao tem filho esquerdo
	    if(elementToBeRemoved->left == NULL){
		puts("Caso 1");
		
		aux = elementToBeRemoved->right;
		free(elementToBeRemoved);
		elementToBeRemoved = aux; 
		
		aux = NULL;
	    }
	    // Caso em que tem os dois filhos
	    else{
		puts("Caso 2");
		aux = getGreaterSuccessor(elementToBeRemoved->right); 
		
		// Elemento sucessor tem filho direito
		if(aux->right != NULL){
		    puts("Caso 3");
		    aux2 = aux->right; 
		    free(elementToBeRemoved);
		    elementToBeRemoved = NULL;
		    elementToBeRemoved = aux; 
		    aux = aux2; 
		    aux2 = NULL; 
	
		}
		
		// Elemento sucessor nao tem nenhum filho
		else{
		    puts("Caso 4");
		    free(elementToBeRemoved);
		    elementToBeRemoved = NULL;
		    elementToBeRemoved = aux;
		    aux = NULL;  
		}
	    }
	}
	
	// Caso em que so tem o filho a esquerda
	else if(elementToBeRemoved->left != NULL){
	    puts("Caso 5");
	    printNode(elementToBeRemoved->left);
	    aux = elementToBeRemoved->left;
	    free(elementToBeRemoved);
	    elementToBeRemoved = aux; 
	    aux = NULL;
	}
	
	//Caso em que nao tem nenhum filho
	else{
	    puts("Caso 6");
	    free(elementToBeRemoved);
	    elementToBeRemoved = NULL; 
	}
	
    }
    else{
	return; 
    }
}

void printArray(int array[], int size){
	int i;
	for(i = 0; i < size; i++){
		printf("%d ", array[i]);
	}
	printf("\n"); 

}


void printTree(element *r){
    element *aux = r;
    if(aux == NULL){
	return; 
    }
    printTree(aux->left);
    printNode(aux);
    printTree(aux->right); 
}

void main(){
    srand(1);
    int n;
    int i;
    element *t = malloc(sizeof(element));
    element *e = NULL;
    t = NULL; 
    
    do{
    
	scanf("%d", &n);
    }while(n < 2 || n > 10000); 
    for(i = 0; i < 2*n-1; i++){
	insertNode(&t, array[i]);
    }
    //printTree(t);
    
    e = searchNode(t, 220);
    checkIfElementExists(e); 
    e = searchNode(t, 5000);
    checkIfElementExists(e);
    
    //removeNode(&t, array[0]);
    removeNode(&t, array[1]);
    printTree(t);
    //e = searchNode(t, 220);
    //checkIfElementExists(e);  
}
