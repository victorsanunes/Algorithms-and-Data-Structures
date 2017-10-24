// C program to delete a node from AVL Tree
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define RED 1
#define BLACK 0

// An AVL tree node
struct Node{
    int key;
    struct Node *left;
    struct Node *right;
    struct Node *parent; 
    int color;
    int height;
};

int max(int a, int b);

// Funcao que calcula a altura da arvore
int height(struct Node *N){
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b){
    return (a > b)? a : b;
}

struct Node* newNode(int key){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key   = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;  // novo no eh adicionado como folha
    node->color = RED; 
    return(node);
}

void rightRotate(struct Node *&root, struct Node *&pt){
    struct Node *pt_left = pt->left;
 
    pt->left = pt_left->right;
 
    if (pt->left != NULL)
        pt->left->parent = pt;
 
    pt_left->parent = pt->parent;
 
    if (pt->parent == NULL)
        root = pt_left;
 
    else if (pt == pt->parent->left)
        pt->parent->left = pt_left;
 
    else
        pt->parent->right = pt_left;
 
    pt_left->right = pt;
    pt->parent = pt_left;
}


struct Node *leftRotate(struct Node *&root, struct Node *&pt){
    struct Node *pt_right = pt->right;
    
    pt->right = pt_right->left; 
    
    if(pt->right != NULL){
        pt->right->parent = pt;
    }
    
    pt_right->parent = pt->parent;
    
    if(pt->parent == NULL){
        root = pt_right; 
    }
    
    else if(pt == pt->parent->left){
        pt->parent->left = pt_right;
    }
    
    else{
        pt->parent->right = pt_right;
    }
    
    pt_right->left = pt;
    pt->parent = pt_right;

}

// Calcula o fator de balanceamento de um no
int getBalance(struct Node *N){
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// Insere balanceando na arvore
struct Node* binarySearchTreeInsertion(struct Node* node, struct Node *pt){

    if (node == NULL)
        return pt;

    if (pt->key < node->key){
        node->left  = binarySearchTreeInsertion(node->left, pt);
        node->left->parent = node; 
    }
    else if (pt->key > node->key){
        node->right = binarySearchTreeInsertion(node->right, pt);
        node->right->parent = node; 
    }
    return node;
}

struct Node* insert(struct Node* root, int key){
    struct Node *pt = newNode(key); 
    
    root = binarySearchTreeInsertion(root, pt);
    return root;

}

// Funcao que busca o menor valor da arvore.
struct Node * minValueNode(struct Node* node){
    struct Node* current = node;

    // Itera ate encontrar a folha mais a esquerda
    while (current->left != NULL)
        current = current->left;

    return current;
}

/*
// Funcao recursiva para remoca de um um no com chave key
// Retorna a raiz da subarvore modificada
struct Node* deleteNode(struct Node* root, int key){
    // STEP 1: PERFORM STANDARD BST DELETE

    if (root == NULL)
        return root;

    // If the key to be deleted is smaller than the
    // root's key, then it lies in left subtree
    if ( key < root->key )
        root->left = deleteNode(root->left, key);

    // If the key to be deleted is greater than the
    // root's key, then it lies in right subtree
    else if( key > root->key )
        root->right = deleteNode(root->right, key);

    // if key is same as root's key, then This is
    // the node to be deleted
    else{
        // node with only one child or no child
        if( (root->left == NULL) || (root->right == NULL) ){
            struct Node *temp = root->left ? root->left :
                                             root->right;

            // No child case
            if (temp == NULL){
                temp = root;
                root = NULL;
            }
            else // One child case
             *root = *temp; // Copy the contents of
                            // the non-empty child
            free(temp);
        }
        else{
            // node with two children: Get the inorder
            // successor (smallest in the right subtree)
            struct Node* temp = minValueNode(root->right);

            // Copy the inorder successor's data to this node
            root->key = temp->key;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->key);
        }
    }

    // If the tree had only one node then return
    if (root == NULL)
      return root;

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->height = 1 + max(height(root->left),
                           height(root->right));

    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to
    // check whether this node became unbalanced)
    int balance = getBalance(root);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0){
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}
* */

// Funcao que percorre a arvore em preordem
void preOrder(struct Node *root){
    if(root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(struct Node *root){
    if(root != NULL){
        
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

void posOrder(struct Node *root){
    if(root != NULL){
        
        posOrder(root->left);
        posOrder(root->right);
        printf("%d ", root->key);
    }
}

void generateRandomArray(int array[], int n){
    int i;
    for(i = 0; i < n; i++){
	    array[i] = rand() % 1001;
    }
}


void fixViolation(struct Node *&root, struct Node *&pt){
    struct Node *parent_pt = NULL;
    struct Node *grand_parent_pt = NULL; 
    int color_aux; 
    
    while((pt != root) && (pt->color != BLACK) && (pt->parent->color == RED)){
        parent_pt = pt->parent; 
        grand_parent_pt = pt->parent->parent; 
        
        // Caso A: pai de pt eh filho esquerdo do avo de pt
        if(parent_pt == grand_parent_pt->left){
            
            // Define quem eh o tio
            struct Node* uncle_pt = grand_parent_pt->right;
            
            // Caso 1: o tio eh vermelho. Entao soh precisa recolorir
            if(uncle_pt != NULL && uncle_pt->color == RED){
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt; 
            }
            
            else{
                
                // Caso 2: pt eh filho direito
                // Rotacao Esquerda
                if(pt == parent_pt->right){
                    leftRotate(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent; 
                }
                
                //Caso 3: pt eh filho esquerdo
                // Rotacao Direita
                
                rightRotate(root, parent_pt);
                color_aux = parent_pt->color;
                parent_pt->color = grand_parent_pt->color;
                grand_parent_pt->color = color_aux;
                pt = parent_pt; 
            
            }
        }
        
        // Caso B: o pai de pt eh filho direito do avo de pt
        else{
            struct Node* uncle_pt = grand_parent_pt->left;
            
            // Caso 1: o tio eh vermelho
            // Recolorir
            if((uncle_pt != NULL) && (uncle_pt->color == RED)){
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            }
            
            else{
                
                // Caso 2: pt eh filho esquerdo
                // Rotacao direita
                if(pt == parent_pt->left){
                    rightRotate(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent; 
                }
                
                // Caso 3: pt eh filho direito
                // Rotacao esquerda
                leftRotate(root, grand_parent_pt);
                color_aux = parent_pt->color;
                parent_pt->color = grand_parent_pt->color;
                grand_parent_pt->color = color_aux;
                pt = parent_pt; 
            }
        }
    }
    
    root->color = BLACK; 
}

int main(){
    srand(1);
    struct Node *root = NULL;
    int n = 12;
    int i;
    int array[n];
    generateRandomArray(array, n);
    for (i = 0; i < n; i++){
        printf("Inserindo %d\n", array[i]);
        root = insert(root, array[i]);
    }

    puts("Percurso Pre ordem:");
    preOrder(root);
    puts("");
    
    puts("Percurso Em ordem:");
    inOrder(root);
    puts("");
    
    puts("Percurso Pos ordem:");
    posOrder(root);
    puts("");

    return 0;
}
