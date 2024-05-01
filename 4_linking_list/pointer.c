#include<stdio.h>

struct LinkedList{
    int data;
    struct LinkedList *next;
};
typedef struct LinkedList *node; //Define node as pointer of data type struct LinkedList

void main(void)
{
    int value0;
    int *value1;

    char value2;
    char *value3;

    struct LinkedList node_static;
    struct LinkedList *node_ptr;

    printf("[%d] sizeof(value0):%d\n",__LINE__,sizeof(value0));
    printf("[%d] sizeof(value1):%d\n",__LINE__,sizeof(value1));
    
    printf("[%d] sizeof(value2):%d\n",__LINE__,sizeof(value2));
    printf("[%d] sizeof(value3):%d\n",__LINE__,sizeof(value3));
    
    printf("[%d] sizeof(node_static):%d\n",__LINE__,sizeof(node_static));
    printf("[%d] sizeof(node_ptr):%d\n",__LINE__,sizeof(node_ptr));


    printf("\n");
    printf("[%d] &node_static:0x%x\n",__LINE__,&node_static);
    printf("[%d] &node_ptr:0x%x, node_ptr:0x%x\n",__LINE__,&node_ptr,node_ptr);

    printf("[%d] &node_static.data=0x%x, node_static.data:%d\n",__LINE__,&node_static.data,node_static.data); 
    printf("[%d] &node_static.next=0x%x, node_static.next:0x%x\n",__LINE__,&node_static.next,node_static.next); 

    node_ptr=&node_static;
    printf("\n");
    printf("[%d] &node_ptr:0x%x, node_ptr:0x%x\n",__LINE__,&node_ptr,node_ptr);
    printf("[%d] &node_ptr->data=0x%x, node_ptr->data:%d\n",__LINE__,&node_ptr->data,node_ptr->data); 
    printf("[%d] &node_ptr->next=0x%x, node_ptr->next:0x%x\n",__LINE__,&node_ptr->next,node_ptr->next); 

    node_ptr->data=555;
    printf("\n");
    printf("[%d] &node_static.data=0x%x, node_static.data:%d\n",__LINE__,&node_static.data,node_static.data); 
    printf("[%d] &node_static.next=0x%x, node_static.next:0x%x\n",__LINE__,&node_static.next,node_static.next); 

    node_static.data=666;
    printf("\n");
    printf("[%d] &node_ptr->data=0x%x, node_ptr->data:%d\n",__LINE__,&node_ptr->data,node_ptr->data); 
    printf("[%d] &node_ptr->next=0x%x, node_ptr->next:0x%x\n",__LINE__,&node_ptr->next,node_ptr->next); 
}
