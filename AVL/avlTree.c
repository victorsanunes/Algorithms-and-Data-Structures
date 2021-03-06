#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct element{
    int key;
    int balanceFactor;
    struct element *left, *right, *father;
}element;

typedef struct tree{
    int height, numberOfElements;
    element *root;
}tree;

void printNode(element *e){
    if(e != NULL){
	printf("key=%d\n", e->key);
	//printf("value=%d\n", e->value);
    }
}

/*
void rightRotation(){}

void leftRotation(){}

void doubleRightRotation(){}

void doubleLeftRotation(){}
*/

void generateRandomArray(int array[], int n){
    int i;
    for(i = 0; i < n; i++){
	array[i] = rand() % 1001;
    }
}

int getTreeHeight(element **r){
    element *aux = *r;
    int leftHeight, rightHeight;
    if(aux == NULL){
	return -1;
    }

    leftHeight = getTreeHeight(&(aux)->left);
    rightHeight = getTreeHeight(&(aux)->right);

    if(leftHeight > rightHeight){
	return leftHeight + 1;
    }
    else{
	return rightHeight + 1;
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
	// puts("direita");
	insertNode(&((*r)->right), key);
    }
    else if(key < (*r)->key){
	// puts("esquerda");
	insertNode(&((*r)->left), key);
    }

    else{
	return;
    }
}

element *searchNode(element **father, element *r, int key){
    element *aux = r;
    if( aux != NULL){

	//puts("Arvore nao nula");
	if( key > aux->key){
	    (*father) = aux;
	    //puts("chave maior");

	    return searchNode(father, aux->right, key);
	}
	else if( key < aux->key){
	    //puts("chave menor");
	    (*father) = aux;
	    return searchNode(father, aux->left, key);
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

void copyElement(element *origin, element *destiny){
    destiny->key = origin->key;
    destiny->left = origin->left;
    destiny->right = origin->right;
}

// Busca menor elemento da subarvore direita
element *getGreatestSuccessor(element *rightTree){
    element *aux = rightTree;

    while(aux->left != NULL){
		aux = aux->left;
    }

    return aux;
}

element *removeNode(element *root, int key){
	if(root == NULL ){
		return root;
	}
	if(key < root->key){
		root->left = removeNode(root->left, key);
	}
	else if(key > root->key){
		root->right = removeNode(root->right, key);
	}
	else{
		if(root->left == NULL){
			element *aux = root->right;
			free(root);
			return aux;
		}
		else if(root->right == NULL){
			element *aux = root->left;
			free(root);
			return aux;
		}

		element *aux = getGreatestSuccessor(root->right);
		root->key = aux->key;
		root->right = removeNode(root->right, aux->key);
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

int getSmallestElement(element **r){
    element *aux = *r;
    int smallest;
    while (aux != NULL){
	//printNode(aux);
	smallest = aux->key;
	aux = aux->left;
    }

    return smallest;
}

element *getGreatestElement(element **r){
    //int greatest;
    element *aux = *r;
    element *aux2 = NULL;
    while (aux != NULL){
	//printNode(aux);
	//greatest = aux->key;
	aux2 = aux;
	aux = aux->right;
    }

    return aux2;
}


void main(){
    srand(1);
    clock_t inicioBuscaMenor, inicioBuscaMaior, fimBuscaMenor, fimBuscaMaior;
    double tempoBuscaMaior, tempoBuscaMenor;
    int n = 12;
    int i;
    int array[n];

    element *t = malloc(sizeof(element));
    element *e1 = NULL;
    element *e2 = NULL;
    element **father;
    t = NULL;

    generateRandomArray(array, n);
    printf("Elements to be inserted: ");
    printArray(array, n);
    puts("");

    for(i = 0; i < n; i++){
	insertNode(&t, array[i]);
    }

    puts("Arvore gerada");
    printTree(t);
    puts("");

    /*inicioBuscaMenor = clock();
    i = getSmallestElement(&t);
    printf("\n\nmenor=%d", i);
    fimBuscaMenor = clock();
    tempoBuscaMenor = fimBuscaMenor - inicioBuscaMenor;
    printf("\nTempo de busca do menor: %.6f\n", tempoBuscaMenor);

    inicioBuscaMaior = clock();
    i = getGreatestElement(&t);
    printf("\n\nmaior=%d", i);
    fimBuscaMaior = clock();
    tempoBuscaMaior = fimBuscaMaior - inicioBuscaMaior;
    printf("\nTempo de busca do menor: %.6f\n", tempoBuscaMaior);

    i = getTreeHeight(&t);
    printf("\nAltura da arvore: %d", i);
    */
    father = &t;
    t = removeNode(t, array[0]);
    t = removeNode(t, array[1]);
    t = removeNode(t, array[2]);
    puts("\nArvore apos a remocao");
    printTree(t);


}
