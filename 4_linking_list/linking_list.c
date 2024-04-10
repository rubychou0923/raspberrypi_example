#include<stdio.h>

struct LinkedList{
    int data;
    struct LinkedList *next;
};
typedef struct LinkedList *node; //Define node as pointer of data type struct LinkedList


node head=NULL;
node createNode(){
    node temp; // declare a node
    temp = (node)malloc(sizeof(struct LinkedList)); // allocate memory using malloc()
    printf("[%s:%d] memory:0x%x\n",__func__,__LINE__,temp);
    temp->next = NULL;// make next point to NULL
    return temp;//return the new node
}


node addNode(node head, int value){
    node temp,p;// declare two nodes temp and p
    temp = createNode();//createNode will return a new node with data = value and next pointing to NULL.
    temp->data = value; // add element's value to data part of node
    if(head == NULL){
        printf("[%s:%d] value:%d\n",__func__,__LINE__,value);
        head = temp;     //when linked list is empty
    }
    else{
        p  = head;//assign head to p
        while(p->next != NULL){
            p = p->next;//traverse the list until p is the last node.The last node always points to NULL.
        }
        p->next = temp;//Point the previous last node to the new node created.
        printf("[%s:%d] value:%d\n",__func__,__LINE__,value);
    }
    return head;
}

void traverse()
{
    node p;
    p = head;
    while(p != NULL){
        printf("p->data:%d, p->next:0x%x\n",p->data,p->next);
        p = p->next;
    }
}



void main(int argc, char **argv)
{
    int button_pressed = 0;
    int index,value;

    if(argc<=1){
        printf("Usage: linking_list number1 number2 number3 number4 ......\n");
        printf("Example: linking_list 2 3 4 1\n");
		exit(0);
    }

    for(index=1;index<argc;index++)
    {
        value=atoi(argv[index]);
        head = addNode(head,value); 
    }

    traverse();
}
