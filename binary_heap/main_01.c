#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int heap[MAX];
int size = 0;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] > heap[largest])
        largest = left;

    if (right < size && heap[right] > heap[largest])
        largest = right;

    if (largest != i)
    {
        swap(&heap[i], &heap[largest]);
        maxHeapify(largest);
    }
}
void insert(int val){
    if(size>=MAX){
        printf("Heap Overflow\n");
        return;
    }
    size++;
    int i=size-1;
    heap[i]=val;
    while(i!=0 && heap[(i-1) / 2] <heap[i]){
        swap(&heap[i],&heap[(i-1/2)]);
        i=(i-1)/2;
    }
}
int extractMax() {
    if (size <= 0) return -1;
    if (size == 1) {
        size--;
        return heap[0];
    }

    int root = heap[0];
    heap[0] = heap[size - 1];
    size--;
    maxHeapify(0);

    return root;
}
void printHeap() {
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}
int main() {
    insert(10);
    insert(4);
    insert(5);
    insert(3);
    insert(1);

    printf("Heap array after insertions: ");
    printHeap();

    printf("Extracted Max: %d\n", extractMax());
    
    printf("Heap array after extraction: ");
    printHeap();

    return 0;
}
