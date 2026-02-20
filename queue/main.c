#include<stdio.h>
int queue[100], front = -1, rear = -1, size = 100;
void enqueue(int value)
{
    if (rear == size - 1)
    {
        printf("Queue is full\n");
        return -1;
    }
    if (front == -1)
        front = 0;
    else
    {
        rear++;
        queue[rear] = value;
    }
       
}
int dequeue()
{
    if (front == -1 )
    {
        printf("queue is empty\n");
        return -1;
    }
    if(front == rear)
    {
        front = rear = -1;
    }
    int value = queue[front];
    front++;
    return value;
}
int main()
{
    while(1)
    {
        int choice, value;
        printf("1. enqueue\n2. dequeue\n3. Exit\n");
        printf(" enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                value = dequeue();
                if (value != -1)
                    printf(" dequeued value: %d\n", value);
                break;
            case 3:
                exit(0);
            default:
                printf(" invalid choice\n");
        }
    }
    
    
    return 0;
}