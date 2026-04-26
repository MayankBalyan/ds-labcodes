#include <stdio.h>    // Include standard input/output library for printing (printf)
#include <stdlib.h>   // Include standard library for memory allocation (malloc, calloc, free)

// ==========================================
// Data Structures
// ==========================================

// Define the structure for an adjacency list node
struct Node {
    int dest;             // Store the destination vertex number
    struct Node* next;    // Pointer to the next node in the linked list
};

// Define the structure for a single adjacency list
struct List {
    struct Node* head;    // Pointer to the first node (head) of the linked list
};

// Define the structure for the complete graph
struct Graph {
    int V;                // Store the total number of vertices in the graph
    struct List* array;   // Pointer to an array of adjacency lists
};

// ==========================================
// Initialization Functions
// ==========================================

// Function to create a new adjacency list node
struct Node* createNode(int dest) {
    // Allocate memory on the heap for the new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = dest;     // Assign the destination vertex to the node
    newNode->next = NULL;     // Initialize the next pointer to NULL (end of list)
    return newNode;           // Return the pointer to the newly created node
}

// Function to create a graph with V vertices
struct Graph* createGraph(int V) {
    // Allocate memory for the main graph structure
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;             // Set the number of vertices in the graph
    
    // Allocate memory for an array of V adjacency lists
    graph->array = (struct List*)malloc(V * sizeof(struct List));
    
    // Loop through all vertices to initialize their adjacency lists
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;  // Set the head of each list to NULL (initially empty)
        
    return graph;             // Return the pointer to the fully initialized graph
}

// Function to add an undirected edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // --- Add an edge from src to dest ---
    struct Node* newNode = createNode(dest);    // Create a new node for the destination
    newNode->next = graph->array[src].head;     // Point new node's next to the current head of src's list
    graph->array[src].head = newNode;           // Update the head of src's list to be the new node

    // --- Add an edge from dest to src (because the graph is undirected) ---
    newNode = createNode(src);                  // Create a new node for the source
    newNode->next = graph->array[dest].head;    // Point new node's next to the current head of dest's list
    graph->array[dest].head = newNode;          // Update the head of dest's list to be the new node
}

// ==========================================
// Traversal Algorithms
// ==========================================

// Function to perform Breadth-First Search (BFS)
void BFS(struct Graph* graph, int startVertex) {
    // Allocate and initialize the visited array with 0s (calloc does this automatically)
    int* visited = (int*)calloc(graph->V, sizeof(int));
    
    // Allocate memory for a queue to keep track of vertices to visit next
    int* queue = (int*)malloc(graph->V * sizeof(int));
    int front = 0, rear = 0;  // Initialize front and rear pointers for the queue

    visited[startVertex] = 1;    // Mark the starting vertex as visited (1 means true)
    queue[rear++] = startVertex; // Enqueue the starting vertex and increment rear

    printf("BFS Traversal: ");   // Print starting message for the output
    
    // Loop until the queue is empty (when front catches up to rear)
    while (front < rear) {
        int currentVertex = queue[front++]; // Dequeue the front vertex and increment front pointer
        printf("%d ", currentVertex);       // Print the vertex we are currently visiting

        // Get the head of the adjacency list for the current vertex
        struct Node* temp = graph->array[currentVertex].head;
        
        // Traverse all adjacent vertices connected to the current vertex
        while (temp) {
            int adjVertex = temp->dest;     // Extract the adjacent vertex number
            
            // If this adjacent vertex has not been visited yet
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;     // Mark it as visited immediately
                queue[rear++] = adjVertex;  // Enqueue it to explore its neighbors later
            }
            temp = temp->next;              // Move to the next adjacent vertex in the linked list
        }
    }
    printf("\n");   // Print a newline after traversal finishes to keep output clean
    free(visited);  // Free the dynamically allocated memory for visited array to prevent leaks
    free(queue);    // Free the dynamically allocated memory for the queue
}

// Recursive helper function for Depth-First Search (DFS)
void DFSUtil(struct Graph* graph, int vertex, int* visited) {
    visited[vertex] = 1;      // Mark the current vertex as visited
    printf("%d ", vertex);    // Print the vertex we just visited

    // Get the head of the adjacency list for the current vertex
    struct Node* temp = graph->array[vertex].head;//build heap
//heapify
//extract_max
#include<stdio.h>


struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode *createNode(int val)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//swap the values
void swap(int* a, int* b){
    int temp =*a;
    *a=*b;
    *b=temp;
}

int main()
{
    
    return 0;
}
    
    // Traverse all adjacent vertices connected to the current vertex
    while (temp) {
        int adjVertex = temp->dest;     // Extract the adjacent vertex number
        
        // If the adjacent vertex hasn't been visited yet
        if (!visited[adjVertex]) {
            DFSUtil(graph, adjVertex, visited); // Recursively dive deep into the unvisited neighbor
        }
        temp = temp->next;              // Move to the next adjacent vertex in the linked list (backtracking)
    }
}

// Main wrapper function for DFS
void DFS(struct Graph* graph, int startVertex) {
    // Allocate and initialize the visited array with 0s (unvisited)
    int* visited = (int*)calloc(graph->V, sizeof(int));
    
    printf("DFS Traversal: ");              // Print starting message for the output
    DFSUtil(graph, startVertex, visited);   // Call the recursive helper function to do the actual work
    printf("\n");                           // Print a newline after traversal finishes
    
    free(visited);                          // Free the dynamically allocated memory for visited array
}

// ==========================================
// Main Function
// ==========================================

int main() {
    int vertices = 6;                                // Define the total number of vertices (numbered 0 to 5)
    struct Graph* graph = createGraph(vertices);     // Initialize the graph structure in memory

    // Add undirected edges to build the graph connections
    addEdge(graph, 0, 1);    // Connect vertex 0 to 1
    addEdge(graph, 0, 2);    // Connect vertex 0 to 2
    addEdge(graph, 1, 3);    // Connect vertex 1 to 3
    addEdge(graph, 1, 4);    // Connect vertex 1 to 4
    addEdge(graph, 2, 4);    // Connect vertex 2 to 4
    addEdge(graph, 3, 4);    // Connect vertex 3 to 4
    addEdge(graph, 3, 5);    // Connect vertex 3 to 5
    addEdge(graph, 4, 5);    // Connect vertex 4 to 5

    printf("Starting traversal from vertex 0:\n");   // Print context for the output
    
    BFS(graph, 0);           // Execute and print Breadth-First Search starting from vertex 0
    DFS(graph, 0);           // Execute and print Depth-First Search starting from vertex 0

    return 0;                // Return 0 to the operating system indicating successful execution
}