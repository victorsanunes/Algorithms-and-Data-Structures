#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 7
#define initial 0
#define waiting 1
#define visited 2

typedef struct listCell{
	int dest;
	struct listCell *next;
}listCell;

typedef struct adjList{
	int lenght;
	listCell *firstCell;
}adjList;

typedef struct graph{
	int v;
	adjList *array;
}graph;

listCell *creatListCell(int dest){
	listCell *new = malloc(sizeof(listCell));
	new->dest = dest;
	new->next = NULL;
	return new;
}

graph *createGraph(int v){
	int i;
	graph *new_graph = malloc(sizeof(graph));
	new_graph->v = v;
	new_graph->array = malloc(v * sizeof(adjList));

	// Inicia todas as listas como vazias
	for(i = 0; i < v; i++){
		new_graph->array[i].firstCell = NULL;
	}

	return new_graph;
}

void addEdge(graph *g, int src, int dest){
	listCell *new_node = creatListCell(dest);
	new_node->next = g->array[src].firstCell;
	g->array[src].firstCell = new_node;

	// Como eh nao direcionado, adiciona a outra conexao
	//new_node = creatListCell(src);
	//new_node->next = g->array[dest].firstCell;
	//g->array[dest].firstCell = new_node;
}

void printGraph(graph *g){
	int i;
	for(i = 0; i < g->v; i++){
		listCell *aux = g->array[i].firstCell;
		printf("\n Adjacency list of vertex %d\n head ", i);
		while(aux){
			printf("-> %d", aux->dest);
			aux = aux->next;
		}
		printf("\n");
	}
}

void printCell(listCell *cell){
	printf("value=%d\n", cell->dest);
}

void insertQueue(int vertex, int *q, int *front, int *rear){
	// ================= CHECA SE ESTOUROU O LIMITE ====================
	if((*rear) == MAX-1){
		puts("Queue overflow");
	}
	else{
		if((*front) == -1){
			(*front) = 0;
		}
		(*rear) = (*rear) + 1;
		q[(*rear)] = vertex;
	}
}

int isEmpty(int *q, int front, int rear){
	if(front == -1 || front > rear)
		return 1;
	else
		return 0;
}

int removeQueue(int *q, int *front, int *rear){
	int deleted;
	if((*front) >= -1 && (*front) <= (*rear)){
		deleted = q[(*front)];
		(*front)++;
		return deleted;
	}

	else{
		puts("Stack underflow");
		return 0;
	}
}

void markVertexAsInitial(int *state, int numberOfVertex){
	int i;
	for(i = 0; i < numberOfVertex; i++){
		state[i] = initial;
	}
}

void DFS(graph *g, int startingVertex, int *state){
	int v;
	printf("Reaching %d\n ", startingVertex);
	v = startingVertex;
	state[v] = waiting;
	
	listCell *aux = g->array[v].firstCell;
	while(aux){
		//printf("Next: %d\n", aux->dest);
		if(state[aux->dest] == initial){
			DFS(g, aux->dest, state);
		}	
		aux = aux->next; 
	}
}


void printList(int *queue, int front, int rear){
	int i;
	puts("QUEUE");
	for(i = front; i <= rear; i++){
		printf("Vertex[%d] -> ", queue[i]);
	}
	printf("\n======================\n");
}

int main(int argc, char **argv){

	// ====================== CRIA A VETOR DE STATUS ===================
	int state[MAX];

	// ========================= CRIA GRAFO ============================
	graph *g1 = createGraph(MAX);
	
	addEdge(g1, 0, 1);
    addEdge(g1, 0, 2);
    addEdge(g1, 1, 2);
    addEdge(g1, 1, 3);
    addEdge(g1, 2, 4);
    addEdge(g1, 2, 5);
    addEdge(g1, 3, 6);
    addEdge(g1, 4, 3);
    addEdge(g1, 4, 5);
    addEdge(g1, 4, 6);
    addEdge(g1, 5, 6);
	
	
    //printGraph(g1);
    
	markVertexAsInitial(state, MAX); 
    DFS(g1, 0, state);

	return 0;
}
