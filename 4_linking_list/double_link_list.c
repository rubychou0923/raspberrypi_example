// C Program  to illustrate how to create a doubly linked 
// list 
#include <stdio.h> 
#include <stdlib.h> 
  
// doubly linked list node template 
struct node { 
    int data; 
    struct node* next; 
    struct node* prev; 
}; 
  
// creating a pointer to head and tail of the linked list 
struct node* head = NULL; 
struct node* tail = NULL; 
  
// create a new node with the given data and return a 
// pointer to it 
struct node* create_node(int data) 
{ 
    struct node* new_node 
        = (struct node*)malloc(sizeof(struct node)); 
    new_node->data = data; 
    new_node->next = NULL; 
    new_node->prev = NULL; 
    return new_node; 
} 
  
// insert a node at the beginning of the list 
void insert_at_head(int data) 
{ 
    struct node* new_node = create_node(data); 
    if (head == NULL) { 
        head = new_node; 
        tail = new_node; 
    } 
    else { 
        new_node->next = head; 
        head->prev = new_node; 
        head = new_node; 
    } 
} 
  
// insert a node at the end of the list 
void insert_at_tail(int data) 
{ 
    struct node* new_node = create_node(data); 
    if (tail == NULL) { 
        head = new_node; 
        tail = new_node; 
    } 
    else { 
        new_node->prev = tail; 
        tail->next = new_node; 
        tail = new_node; 
    } 
} 
  
// delete the node at the beginning of the list 
void delete_at_head() 
{ 
    if (head == NULL) { 
        return; 
    } 
    struct node* temp = head; 
    if (head == tail) { 
        head = NULL; 
        tail = NULL; 
    } 
    else { 
        head = head->next; 
        head->prev = NULL; 
    } 
    free(temp); 
} 
  
// delete the node at the end of the list 
void delete_at_tail() 
{ 
    if (tail == NULL) { 
        return; 
    } 
    struct node* temp = tail; 
    if (head == tail) { 
        head = NULL; 
        tail = NULL; 
    } 
    else { 
        tail = tail->prev; 
        tail->next = NULL; 
    } 
    free(temp); 
} 
  
// display the list in forward direction 
void display_forward() 
{ 
    struct node* current = head; 
    while (current != NULL) { 
        printf("%d ", current->data); 
        current = current->next; 
    } 
    printf("\n"); 
} 
  
// display the list in backward direction 
void display_backward() 
{ 
    struct node* current = tail; 
    while (current != NULL) { 
        printf("%d ", current->data); 
        current = current->prev; 
    } 
    printf("\n"); 
} 
  
// Driver code to test the doubly linked list 
int main() 
{ 
    insert_at_head(10); 
    insert_at_head(20); 
    insert_at_tail(30); 
    display_forward(); // expected output: 20 10 30 
    display_backward(); // expected output: 30 10 20 
    delete_at_head(); 
    delete_at_tail(); 
    display_forward(); // expected output: 10 
    display_backward(); // expected output: 10 
  
    return 0; 
}
