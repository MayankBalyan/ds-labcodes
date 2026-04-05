#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int val;
    struct Node* next;
}Node;

//Creation of Node
Node* createNode(int val){
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode==NULL){
        printf("Memory Allocation Failed");
        exit(1);
    }
    newNode->val=val;
    newNode->next=NULL;
    return newNode;
}

//Insertion At End
void insert_at_end(Node** head,int val){
    Node* newNode = createNode(val);

    if(*head == NULL){
        *head = newNode;
        return ;
    }
    Node* dummy = *head;
    while(dummy->next != NULL){
        dummy=dummy->next;
    }
    dummy->next=newNode;
}

//traversal of Linked List
void printList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        printf("%d -> ",temp->val);
        temp=temp->next;
    }
    printf("NULL\n");
}

//insert at the starting
void insert_at_starting(Node **head,int val){
    Node* newNode = createNode(val);
    newNode->next = (*head);
    (*head)=newNode;
}
void insert_after_index(Node **head, int val, int index){
    int i = 0;
    Node* dummy = *head;
    for(i;i<index;i++){
        dummy=dummy->next;
    }
    Node* newNode = createNode(val);
    newNode->next=dummy->next;
    dummy->next=newNode;
}
// void insert_before_index(Node **head, int val, int index){
//     int i = 0;
//     Node* dummy = *head;
//     for(i;i<index-1;i++){
//         dummy=dummy->next;
//     }
//     Node* newNode = createNode(val);
//     newNode->next=dummy->next;
//     dummy->next=newNode;
// }
void deletion_at_head(Node** head){
    if (*head == NULL) {
        printf("List is already empty.\n");
        return;
    }
    Node* dummy = *head;
    *head = (*head)->next;
    free(dummy);
}
void deletion_at_end(Node** head) {
    if (*head == NULL) {
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    Node* p = *head;
    Node* q = (*head)->next;
    
    while (q->next != NULL) {
        p = p->next;
        q = q->next;
    }
    
    p->next = NULL;
    free(q);
}
int linearSearch(Node* head, int target) {
    Node* current = head;
    
    while (current != NULL) {
        if (current->val == target) {
            return 1; 
        }
        current = current->next;
    }
    
    return 0; 
}

//binary search
Node* getMiddle(Node* start, Node* last) {
    if (start == NULL) {
        return NULL;
    }
    
    Node* slow = start;
    Node* fast = start->next;
    
    while (fast != last) {
        fast = fast->next;
        if (fast != last) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    
    return slow;
}

int binarySearch(Node* head, int target) {
    Node* start = head;
    Node* last = NULL;
    
    do {
        Node* mid = getMiddle(start, last);
        
        if (mid == NULL) {
            return 0;
        }
        
        if (mid->val == target) {
            return 1;
        } else if (mid->val < target) {
            start = mid->next;
        } else {
            last = mid;
        }
        
    } while (last == NULL || last != start);
    
    return 0;
}
void reverse_list(Node** head) {
    Node* prev = NULL;
    Node* current = *head;
    Node* next = NULL;
    
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    *head = prev;
}
int get_length(Node* head) {
    int count = 0;
    Node* temp = head;
    
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    
    return count;
}

int main()
{
    
    Node* head=NULL;
    insert_at_end(&head, 10);
    insert_at_end(&head, 20);
    insert_at_end(&head, 30);
    printList(head);

    insert_at_starting(&head,0);
    printList(head);

    insert_after_index(&head,15,1);
    printList(head);
    
    insert_before_index(&head,25,4);
    printList(head);

    deletion_at_head(&head);
    printList(head);

    deletion_at_end(&head);
    printList(head);

    
    reverse_list(&head);
    printList(head);

    printf("The length of the linked list is %d",get_length(head));
    
    
    return 0;
}