#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// A priority queue is an abstract data type in which each data has a priority
// associated with it. If the data shares  same  priority,  then  whichever  comes  
// first  in  queue  is  served  first.  Write  a C  programfor implementing  a  priority 
//  queue  (in  the  increasing  order  of  their  value)  using  transform  and  conquer 
//  technique andimplement the same using C language.Modify the programsuch that we can remove
//   any given data at any given point of time.You have to execute the program first and then 
//   write the executing program on a plain A4 sized paper and upload it.

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

struct priorityQueue
{
    int size;
    int *heap;
};

struct priorityQueue *createQueue()
{
    struct priorityQueue *queue = (struct priorityQueue *)malloc(sizeof(struct priorityQueue));
    queue->heap = (int *)malloc(MAX * sizeof(int));
    queue->size = 0;
    return queue;
}

int isEmpty(struct priorityQueue *queue)
{
    return (queue->size == 0);
}

void heapify_bottom_up(int arr[], int n, int i)
{
    int parent = (i - 1) / 2;
    if (arr[parent] > 0)
    {
        if (arr[i] > arr[parent])
        {
            swap(&arr[i], &arr[parent]);
            heapify_bottom_up(arr, n, parent);
        }
    }
}

void heapify_top_down(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify_top_down(arr, n, largest);
    }
}

void enqueue(struct priorityQueue *queue, int Key)
{
    queue->size++;
    queue->heap[queue->size -1] = Key;
    heapify_bottom_up(queue->heap, queue->size, queue->size - 1);
}

void dequeue(struct priorityQueue *queue)
{
    if(isEmpty(queue))
    {
        printf("Queue is empty.\n");
        return;
    }
    int lastElement = queue->heap[queue->size - 1];
    printf("%d Dequeued.\n", queue->heap[0]);
    queue->heap[0] = lastElement;
    queue->size--;
    heapify_top_down(queue->heap, queue->size, 0);
}

void printQueue(struct priorityQueue *queue)
{
    printf("Queue : ");
    for (int i = 0; i < queue->size; i++)
        printf("%3d", queue->heap[i]);
    printf("\n");
}

void removeAll(struct priorityQueue *queue, int x)
{
    int lastElement = queue->heap[queue->size - 1];
    for (int i = 0; i < queue->size; i++)
    {
        if(queue->heap[i]==x)
        {
            queue->heap[i] = lastElement;
            queue->size--;
            heapify_top_down(queue->heap, queue->size, i);
        }
    }
}

int main()
{
    int n, x, ch, i;
    struct priorityQueue *queue = createQueue(100);
    printf("-----------Menu-----------\n");
    printf(" 1. Enqueue\n 2. Dequeue\n 3. Print\n 4. Remove\n 5. Exit\n");
    while (1)
    {
        printf("Enter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter value : ");
            scanf("%d", &x);
            enqueue(queue, x);
            break;
        case 2:
            dequeue(queue);
            break;
        case 3:
            printQueue(queue);
            break;
        case 4:
            printf("Enter value : ");
            scanf("%d", &x);
            removeAll(queue, x);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid Choice\n");
        }
    }
}