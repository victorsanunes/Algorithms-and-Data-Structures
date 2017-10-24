#include <stdio.h>
#include <stdlib.h>

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
	new_node = creatListCell(src);
	new_node->next = g->array[dest].firstCell;
	g->array[dest].firstCell = new_node;
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

void insertQueue(int *q, int front, int rear, int vertex){
	if(rear == MAX-1){
		puts("Queue overflow");
	}
	else{
		if(front == -1){
			front = 0;
		}
		rear = rear + 1;
		q[rear] = vertex;
	}
}

void removeQueue(int *q, int front, int rear, int vertex){

}

int main(int argc, char **argv){
	int queue[5];
	int front, rear;
	front = -1;
	rear = -1;

	graph *g1 = createGraph(5);
	addEdge(g1, 0, 1);
    addEdge(g1, 0, 4);
    addEdge(g1, 1, 2);
    addEdge(g1, 1, 3);
    addEdge(g1, 1, 4);
    addEdge(g1, 2, 3);
    addEdge(g1, 3, 4);

    printGraph(g1);
	return 0;
}
