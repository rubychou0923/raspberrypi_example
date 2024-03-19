#include <stdio.h>
#include <stdlib.h>
#define LIMIT 100 // Specifying the maximum limit of the queue

/* Global declaration of variables */

int queue[LIMIT]; // Array implementation of queue
int front, rear; // To insert and deletee the data elements in the queue respectively
int i; // To traverse the loop to while displaying the stack
int choice; // To choose either of the 3 stack operations

void insert(); // Function used to insert the element into the queue
void delete(); // Function used to deletee the elememt from the queue
void display(); // Function used to display all the elements in the queue according to FIFO rule

int main()
{

    printf("Welcome to DataFlair tutorials!\n\n");

    printf ("ARRAY IMPLEMENTATION OF QUEUES\n\n");
    front = rear = -1; // Initialzing front and rear to -1 indicates that it is empty
    do
    {

        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n\n");
        printf("Enter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Sorry, invalid choice!\n");
                break;
        }
    } while(choice!=4);
    return 0;
}

void insert()
{
    int element;
    if (rear == LIMIT - 1)
        printf("Queue Overflow\n");
    else
    {
        if (front == - 1)
            front = 0;
        printf("Enter the element to be inserted in the queue: ");
        scanf("%d", &element);
        rear++;
        queue[rear] = element;
    }
}

void delete()
{
    if (front == - 1 || front > rear)
    {
        printf("Queue Underflow \n");
    }
    else
    {
        printf("The deleteed element in the queue is: %d\n", queue[front]);
        front++;
    }
}

void display()
{
    int i;
    if (front == - 1)
    {
        printf("Queue underflow\n");
    }
    else
    {
        printf("The elements of the queue are:\n");
        for (i = front; i <= rear; i++)
            printf("%d\n", queue[i]);
    }
}
