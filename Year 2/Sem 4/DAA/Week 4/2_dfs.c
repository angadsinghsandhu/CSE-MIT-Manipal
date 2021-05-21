ALGORITHM DFS(G)
//Implements a depth-first search traversal of a given graph
//Input: Graph G = V, E
//Output: Graph G with its vertices marked with consecutive integers
// in the order they are first encountered by the DFS traversal
mark each vertex in V with 0 as a mark of being “unvisited”
count ←0
for each vertex v in V do
      if v is marked with 0
          dfs(v)

dfs(v)
//visits recursively all the unvisited vertices connected to vertex v
//by a path and numbers them in the order they are encountered
//via global variable count
count ←count + 1; mark v with count
for each vertex w in V adjacent to v do
      if w is marked with 0
          dfs(w)

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int top = -1, stack[MAX];

void push(int val)
{
    if (top == MAX - 1)
    {
        printf("\nStack is full!!");
    }
    else
    {
        top = top + 1;
        stack[top] = val;
        printf("Pushed %d.\n", stack[top]);
    }
}

int pop()
{
    if (top == -1)
    {
        printf("\nStack is empty!!");
    }
    else
    {
        printf("Popped %d.\n", stack[top]);
        top = top - 1;
        return stack[top + 1];
    }
}

typedef struct listNode ListNode;

struct listNode
{
    ListNode *next;
    int data;
};

ListNode *createNode(int x)
{
    ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
    temp->data = x;
    temp->next = NULL;
    return temp;
}

ListNode *insert(ListNode *head, int x)
{
    if (head == NULL)
    {
        head = createNode(x);
        return head;
    }
    ListNode *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = createNode(x);
    return head;
}

void print(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        printf("%d --> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void dfs(ListNode **adjList, int visited[],int DFS[], int v)
{
    int idx=0;
    push(v);
    while (top != -1)
    {
        v = pop();
        if (visited[v])
        {
            continue;
        }
        visited[v] = 1;
        DFS[idx++]=v;
        ListNode *temp = adjList[v];
        while (temp != NULL)
        {
            if (!visited[temp->data])
                push(temp->data);
            temp = temp->next;
        }
    }
}

int main()
{
    int v, e, i, j;
    printf("Enter the number of vertices : ");
    scanf("%d", &v);

    ListNode **adjList = malloc(v * sizeof(ListNode *));
    for (i = 0; i < v; i++)
        adjList[i] = NULL;

    printf("Enter the number of edges : ");
    scanf("%d", &e);
    int start, end, visited[v],DFS[v];
    for (i = 0; i < v; i++)
        visited[i] = 0;
    for (i = 0; i < e; i++)
    {
        printf("Enter start and end vertex of edge %d : ",i+1);
        scanf("%d%d", &start,&end);
        adjList[start] = insert(adjList[start], end);
        adjList[end] = insert(adjList[end], start);
    }

    printf("\nAdjacency List : \n");
    for (i = 0; i < v; i++)
    {
        printf("%d : ", i);
        print(adjList[i]);
    }
    printf("\n");
    dfs(adjList, visited,DFS, 0);

    printf("\nDFS : ");
    for (i = 0; i < v; i++)
    {
        printf("%d  ", DFS[i]);
    }
    printf("\n");
}