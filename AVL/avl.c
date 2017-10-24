// C program to delete a node from AVL Tree
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// An AVL tree node
struct Node{
    int key;
    struct Node *left;
    struct Node *right;
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
    return(node);
}

struct Node *rightRotate(struct Node *y){
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    // Executa a rotacao
    x->right = y;
    y->left = T2;

    // Atualiza alturas
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;

    // Retorna ponteiro inalterado
    return x;
}


struct Node *leftRotate(struct Node *x){
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    // Executa a rotacao
    y->left = x;
    x->right = T2;

    // Atualiza alturas
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    // Retorna nova raiz
    return y;
}

// Calcula o fator de balanceamento de um no
int getBalance(struct Node *N){
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// Insere balanceando na arvore
struct Node* insert(struct Node* node, int key){

    if (node == NULL)
        return(newNode(key));

    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Equal keys not allowed
        return node;

    // Atualiza a altura do ancestral, o pai.
    node->height = 1 + max(height(node->left),
                           height(node->right));

    // Calcula o fator de balanceamento do pai para ver se esta
    // desbalanceado
    int balance = getBalance(node);

    // Caso a arvore se desbalanceie, haverão 4 casos

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key){
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    //  Retorna o ponteiro inalterado
    return node;
}

// Funcao que busca o menor valor da arvore.
struct Node * minValueNode(struct Node* node){
    struct Node* current = node;

    // Itera ate encontrar a folha mais a esquerda
    while (current->left != NULL)
        current = current->left;

    return current;
}

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

// Funcao que percorre a arvore em preordem
void preOrder(struct Node *root){
    if(root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void generateRandomArray(int array[], int n){
    int i;
    for(i = 0; i < n; i++){
	    array[i] = rand() % 1001;
    }
}


int main(){
    srand(1);
    struct Node *root = NULL;
    int n = 12;
    int i;
    int array[n];
    generateRandomArray(array, n);
    for (i = 0; i < n; i++){
        root = insert(root, array[i]);
    }

    puts("Percurso Preordem:");
    preOrder(root);
    puts("");

    root = deleteNode(root, array[0]);
    printf("Percurso preordem apos remocao da chave %d\n", array[0]);
    preOrder(root);

    return 0;
}
