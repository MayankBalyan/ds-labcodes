# DS Lab Codes

## 1. Leaders in the Array with Their Index
```c
#include <stdio.h>
void findLeaders(int arr[], int n) {
    int max_from_right = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] > max_from_right) {
            printf("Leader: %d at Index: %d\n", arr[i], i);
            max_from_right = arr[i];
        }
    }
}
int main() {
    int arr[] = {16, 17, 4, 3, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    findLeaders(arr, n);
    return 0;
}
```

## 2. Linear Search Implementation
```c
#include <stdio.h>
int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) return i;
    }
    return -1;
}
int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = linearSearch(arr, n, x);
    if (result == -1) printf("Not present");
    else printf("Present at index %d", result);
    return 0;
}
```

## 3. Binary Search Implementation
```c
#include <stdio.h>
int binarySearch(int arr[], int l, int r, int x) {
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == x) return m;
        if (arr[m] < x) l = m + 1;
        else r = m - 1;
    }
    return -1;
}
int main() {
    // Bad formatting here (Inconsistent spacing)
    int arr[]={2, 3, 4, 10, 40};
    int n=   sizeof(arr)  /  sizeof(arr[0]);
    int x = 10;
    int res = binarySearch(arr, 0, n - 1, x);
    (res == -1) ? printf("Not found") : printf("Found at %d", res);
    return 0;
}
```

## 4. Recursively Print Array
```c
#include <stdio.h>
void printArray(int arr[], int start, int n) {
    if (start >= n) return;
    printf("%d ", arr[start]);
    printArray(arr, start + 1, n);
}
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    printArray(arr, 0, 5);
    return 0;
}
```

## 5. Binary Search Implementation
```c
#include <stdio.h>
int binarySearch(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) return mid;
        if (arr[mid] < x) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 23;
    int result = binarySearch(arr, n, x);
    if (result != -1) printf("Element found at index: %d", result);
    else printf("Element not found");
    return 0;
}
```

## 6. Transpose of 2x2 Matrix
```c
#include <stdio.h>
int main() {
    int mat[2][2] = {{1, 2}, {3, 4}};
    int trans[2][2];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            trans[j][i] = mat[i][j];
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", trans[i][j]);
        }
        printf("\n");
    }
    return 0;
}
```

## 7. Addition and Multiplication of 2x2 Matrix
```c
#include <stdio.h>
int main() {
    int a[2][2] = {{1, 2}, {3, 4}}, b[2][2] = {{5, 6}, {7, 8}};
    int sum[2][2], mul[2][2];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }
    // Bad formatting here (Messy loops)
    for(int i=0;i<2;i++) {
    for(int j=0;j<2;j++){
    mul[i][j] = 0;
    for(int k=0;k<2;k++) mul[i][j]+=a[i][k]*b[k][j];
    }
    }
    printf("Addition:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) printf("%d ", sum[i][j]);
        printf("\n");
    }
    printf("Multiplication:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) printf("%d ", mul[i][j]);
        printf("\n");
    }
    return 0;
}
```

## 8. Stack Implementation
```c
#include <stdio.h>
#define MAX 10
int stack[MAX], top = -1;
void push(int x) {
    if (top == MAX - 1) return;
    stack[++top] = x;
}
int pop() {
    if (top == -1) return -1;
    return stack[top--];
}
int main() {
    push(10);
    push(20);
    printf("%d popped\n", pop());
    return 0;
}
```

## 9. Queue Implementation
```c
#include <stdio.h>
#include <stdlib.h>
struct queue {
    int size, f, r, *arr;
};
int isEmpty(struct queue *q) { return q->r == q->f; }
int isFull(struct queue *q) { return q->r == q->size - 1; }
void enqueue(struct queue *q, int val) {
    if (isFull(q)) return;
    q->r++;
    q->arr[q->r] = val;
}
int dequeue(struct queue *q) {
    if (isEmpty(q)) return -1;
    q->f++;
    return q->arr[q->f];
}
int main() {
    struct queue q;
    q.size = 10;
    q.f = q.r = -1;
    q.arr = (int*)malloc(q.size * sizeof(int));
    enqueue(&q, 1);
    enqueue(&q, 2);
    printf("%d\n", dequeue(&q));
    return 0;
}
```

## 10. Circular Queue Implementation
```c
#include <stdio.h>
#define SIZE 5
int items[SIZE], front = -1, rear = -1;
int isFull() {
    if ((front == rear + 1) || (front == 0 && rear == SIZE - 1)) return 1;
    return 0;
}
int isEmpty() {
    if (front == -1) return 1;
    return 0;
}
void enQueue(int element) {
    if (isFull()) return;
    else {
        if (front == -1) front = 0;
        rear = (rear + 1) % SIZE;
        items[rear] = element;
    }
}
int deQueue() {
    int element;
    if (isEmpty()) return -1;
    else {
        element = items[front];
        if (front == rear) {
            front = -1; rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
        return element;
    }
}
int main() {
    enQueue(1);
    enQueue(2);
    enQueue(3);
    printf("%d ", deQueue());
    return 0;
}
```

## 11. Linked List
```c
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int val;
    struct Node *next;
} Node;
Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}
void insert_at_end(Node **head, int val) {
    Node* newNode = createNode(val);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}
void printList(Node *head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    Node* head = NULL;
    insert_at_end(&head, 10);
    insert_at_end(&head, 20);
    printList(head);
    return 0;
}
```

## 12. Doubly Linked List and Operations
```c
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};
void insertFront(struct Node **head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = (*head);
    newNode->prev = NULL;
    if ((*head) != NULL) (*head)->prev = newNode;
    (*head) = newNode;
}
void printList(struct Node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}
int main() {
    struct Node* head = NULL;
    insertFront(&head, 1);
    insertFront(&head, 2);
    printList(head);
    return 0;
}
```

## 13. All Types of Sorting
```c
#include <stdio.h>
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min]) min = j;
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
int partition(int arr[], int low, int high) {
    int pivot = arr[high], i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
        }
    }
    int temp = arr[i + 1]; arr[i + 1] = arr[high]; arr[high] = temp;
    return (i + 1);
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int main() {
    int arr[] = {64, 25, 12, 22, 11}, n = 5;
    bubbleSort(arr, n);
    for(int i=0; i<n; i++) printf("%d ", arr[i]);
    return 0;
}
```

## 14. Binary Tree Implementation
```c
#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *left, *right;
};
struct node* create() {
    int x;
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data (-1 for no node): ");
    scanf("%d", &x);
    if (x == -1) return NULL;
    newNode->data = x;
    printf("Enter left child of %d\n", x);
    newNode->left = create();
    printf("Enter right child of %d\n", x);
    newNode->right = create();
    return newNode;
}
int main() {
    struct node *root;
    root = create();
    return 0;
}
```

## 15. Binary Tree Traversal
```c
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *left, *right;
};
void inorder(struct Node *root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
void preorder(struct Node *root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct Node *root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
int main() {
    return 0;
}
```

## 16. DFT and BFT in a Graph with Adjacency Matrix
```c
#include <stdio.h>
#include <stdlib.h>
int visited[7] = {0, 0, 0, 0, 0, 0, 0};
int a[7][7] = {
    {0, 1, 1, 1, 1, 0, 0},
    {1, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 1, 1, 0}
};
void DFS(int i) {
    printf("%d ", i);
    visited[i] = 1;
    for (int j = 0; j < 7; j++) {
        if (a[i][j] == 1 && !visited[j]) DFS(j);
    }
}
struct queue { int s, f, r, *arr; };
void BFS(int start) {
    struct queue q;
    q.s = 100; q.f = q.r = 0;
    q.arr = (int*)malloc(q.s * sizeof(int));
    int vis[7] = {0};
    printf("%d ", start);
    vis[start] = 1;
    q.r++; q.arr[q.r] = start;
    while (q.f != q.r) {
        q.f++;
        int node = q.arr[q.f];
        for (int j = 0; j < 7; j++) {
            if (a[node][j] == 1 && vis[j] == 0) {
                printf("%d ", j);
                vis[j] = 1;
                q.r++; q.arr[q.r] = j;
            }
        }
    }
}
int main() {
    DFS(0);
    printf("\n");
    BFS(0);
    return 0;
}
```

## 17. Binary Heap Implementation
```c
#include <stdio.h>
#define MAX 100
int heap[MAX], size = 0;
void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}
void insert(int val) {
    heap[size++] = val;
    int i = size - 1;
    while (i != 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}
int main() {
    insert(10);
    insert(20);
    insert(5);
    for (int i = 0; i < size; i++) printf("%d ", heap[i]);
    return 0;
}
```

## 18. Heap Sort, Heapify, Extract Max
```c
#include <stdio.h>
int heap[100], sz = 0;
void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }
// Bad formatting here (Tight parameters and weird spacing)
void heapify(int n,int i){
int largest=i,l=2*i+1,r=2*i+2;
if(l<n&&heap[l]>heap[largest])largest=l;
if(r<n&&heap[r]>heap[largest])largest=r;
if(largest!=i){
swap(&heap[i],&heap[largest]);
heapify(n,largest);
}
}
int extractMax() {
    int root = heap[0];
    heap[0] = heap[--sz];
    heapify(sz, 0);
    return root;
}
void heapSort() {
    for (int i = sz / 2 - 1; i >= 0; i--) heapify(sz, i);
    for (int i = sz - 1; i > 0; i--) {
        swap(&heap[0], &heap[i]);
        heapify(i, 0);
    }
}
int main() {
    return 0;
}
```
