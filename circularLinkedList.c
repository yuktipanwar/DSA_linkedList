#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}; 

// Function for TRAVERSING
void linkedListTraversal(struct Node *head)
{
    struct Node * ptr = head;

    do{
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }while (ptr != head);
}

struct Node * insertAtFirst(struct Node *head, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr-> data =data;

    struct Node * p = head ->next;
    while(p->next !=head){
        p=p->next;
    }
    //At this point p points to the very last node of this cicular linked list.

    p-> next =ptr;
    ptr->next=head;
    head=ptr;
    return head;
}
int main(){

    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // DYNAMIC MEMORY ALLOCATION
    // Allocation of memonry for nodes of linked list in heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 4;
    head->next = second;

    // Link second and third nodes
    second->data = 3;
    second->next = third;

    // Link third and fouth nodes
    third->data = 6;
    third->next = fourth;

    // Link fouth and first nodes
    fourth->data = 1;
    fourth->next = head;

    printf("Circular Linked list before insertion\n");
    linkedListTraversal(head);

    printf("Circular Linked list after insertion\n");
    head = insertAtFirst(head, 54);
    // head = insertAtFirst(head, 58);
    // head = insertAtFirst(head, 59);
    linkedListTraversal(head);
    return 0;
}