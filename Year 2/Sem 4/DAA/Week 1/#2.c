#include <stdio.h>
#include <stdlib.h>

static int edges = -1;
int** edgeArr = NULL;

struct AdjListNode
{
 int dest;
 struct AdjListNode* next;
};

struct AdjList
{
 struct AdjListNode *head;
};

struct Graph
{
 int V;
 struct AdjList* array;
 int** AdjMat;
};

struct AdjListNode* newAdjListNode(int dest)
{
 struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
 newNode->dest = dest;
 newNode->next = NULL;
 return newNode;
}

void createAdjMatrix(struct Graph* graph, int** edgeArr)
{
 int** AdjMatTemp = (int** )calloc(100, sizeof(int*));
 for (int i = 0; i < graph->V + 1; i++) {
 AdjMatTemp[i] = (int* )calloc(graph->V + 1, sizeof(int));
 for (int j = 0; j < graph->V + 1; j++) {
 AdjMatTemp[i][j] = 0;
 }
 }

 for (int i = 0; i < edges + 1; i++) {

 int x = edgeArr[i][0];
 int y = edgeArr[i][1];
 AdjMatTemp[x][y] = 1;
 AdjMatTemp[y][x] = 1;
 }
 graph->AdjMat = AdjMatTemp;
}

struct Graph* createGraph(int V)
{
 struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
 graph->V = V;
 graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));
 edgeArr = (int **)calloc(100, sizeof(int*));
 graph->AdjMat = (int**)calloc(100, sizeof(int*));
 int i;
 for (i = 0; i < V; ++i)
 graph->array[i].head = NULL;
 return graph;
}

void addEdge(struct Graph* graph, int src, int dest)
{
 struct AdjListNode* newNode = newAdjListNode(dest);
 newNode->next = graph->array[src].head;
 graph->array[src].head = newNode;
 newNode = newAdjListNode(src);
 newNode->next = graph->array[dest].head;
 graph->array[dest].head = newNode;
 edges++;
 edgeArr[edges] = (int *)calloc(2, sizeof(int));
 edgeArr[edges][0] = src;
 edgeArr[edges][1] = dest;
}

void printAdjList(struct Graph* graph)
{
 int v;
 for (v = 0; v < graph->V; ++v)
 {
 struct AdjListNode* pCrawl = graph->array[v].head;
 printf("\n Adjacency list of vertex %d\n head ", v);
 while (pCrawl)
 {
 printf("-> %d", pCrawl->dest);
 pCrawl = pCrawl->next;
 }
 printf("\n");
 }
}

void printAdjMatrix(struct Graph* graph)
{
 int** AdjMat = graph->AdjMat;
 for (int i = 1; i < graph->V + 1; i++) {
 for (int j = 1; j < graph->V + 1; j++) {
 printf("%d ", AdjMat[i][j]);
 }
 printf("\n");
 }
}

int main()
{
 int ch = 100;
 int V;
 printf("How many vertices(Max 100): ");
 scanf("%d", &V);
 struct Graph* graph = createGraph(V);
 printf ("\n-------Menu--------");
 printf ("\n1- Add Edge");
 printf ("\n2- View Adjaceny List");
 printf ("\n3- View Adjacency Matrix");
 printf ("\n4- Quit");
 printf ("\n--------------------");
 while(ch != 4) {
 printf("\nChoice: ");
 scanf("%d", &ch);
 switch(ch) {
 case 1: {
 int src;
 int dest;
 printf("Source Destination:");
 scanf("%d %d", &src, &dest);
 addEdge(graph, src, dest);
 createAdjMatrix(graph, edgeArr);
 break;
 }
 case 2: {
 printAdjList(graph);
 break;
 }
 case 3: {
 printAdjMatrix(graph);
 break;
 }
 case 4: {
 printf("Goodbye!\n");
 break;
 }
 default: {
 printf("Invalid Choice. Quitting\n");
 ch = 4;
 }
 }
 }
 return 0;
}
