ALGORITHM BFS(G)
//Implements a breadth-first search traversal of a given graph
//Input: Graph G = V, E
//Output: Graph G with its vertices marked with consecutive integers
// in the order they are visited by the BFS traversal
mark each vertex in V with 0 as a mark of being “unvisited”
count ←0
for each vertex v in V do
     if v is marked with 0
         bfs(v)


bfs(v)
//visits all the unvisited vertices connected to vertex v
//by a path and numbers them in the order they are visited
//via global variable count
count ←count + 1; mark v with count and initialize a queue with v
while the queue is not empty do
     for each vertex w in V adjacent to the front vertex do
          if w is marked with 0
               count ←count + 1;
mark w with count
	add w to the queue
		remove the front vertex from the queue

#include <stdio.h>
#include <stdlib.h>

typedef struct adjacency_list {
	int data;
	int visit;
	struct adjacency_list *right;
} adjacency_list;

adjacency_list *createNode(int data) {
	adjacency_list *temp = (adjacency_list *)malloc(sizeof(adjacency_list));
	temp->data = data;
	temp->visit = 0;
	temp->right = NULL;
	return temp;
}

void display_adjacency_list(adjacency_list **list, int v) {
	for (int i = 0; i < v; i++) {
		printf("%d -> ", i);
		adjacency_list *a = list[i]->right;
		int j = 10;
		while (a != NULL && j--) {
			printf("%d -> ", a->data);
			a = a->right;
		}
		printf("\n");
	}
}

adjacency_list **createGraphAdjacencyList(int v, int e, int arr[][2]) {
	adjacency_list **node = (adjacency_list *)malloc(sizeof(adjacency_list) * v);

	for (int i = 0; i < v; i++) {
		node[i] = createNode(i);
	}

	for (int i = 0; i < e; i++) {
		int j = 0;
		adjacency_list **temp = node;

		while (j < v) {
			if (temp[j]->data == arr[i][0]) {
				adjacency_list *temp1 = createNode(arr[i][1]);
				temp1->right = temp[j]->right;
				temp[j]->right = temp1;
				temp1 = createNode(arr[i][0]);
				temp1->right = temp[arr[i][1]]->right;
				temp[arr[i][1]]->right = temp1;
				break;
			} else {
				j++;
			}
		}
	}

	return node;
}

void breadthFirstSearch(adjacency_list **list, int v) {
	adjacency_list *current = list[0];
	current->visit = 1;
	printf("%d\n", current->data);
	int count = 1;
	int q[v];
	int front = -1;
	int rear = -1;
	q[++front] = current->data;
	while (front != rear) {
		current = list[q[front]];
		rear++;
		while (current != NULL) {
			current = current->right;
			if (current == NULL) {
				break;
			}

			if (list[current->data]->visit != 0) {
				continue;
			}
			list[current->data]->visit = ++count;
			printf("%d\n", current->data);
			q[++front] = current->data;
		}
	}
}

int main()
{
	int v, e;
	scanf("%d %d", &v, &e);
	int arr[e][2];
	
	for (int i = 0; i < e; i++) {
		scanf("%d %d", &arr[i][0], &arr[i][1]);
	}

	adjacency_list **list = createGraphAdjacencyList(v, e, arr);
	display_adjacency_list(list, v);
	breadthFirstSearch(list, v);
	return 0;
}