#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

// Function for TRAVERSING
void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

//Case 1: DELETING THE FIRST ELEMENT 
struct Node * deleteFirst(struct Node * head){
    struct Node * ptr = head;
    head = head ->next;
    free(ptr);
    return head;
}

//Case 2: DELETING AN ELEMENT IN BETWEEN THE LINKED LIST
struct Node* deleteAtIndex(struct Node * head, int index){
    struct Node * p = head;
    struct Node * q = head-> next;

    for(int i=0; i<index-1; i++){                          //we are assuming that the value of index doen't start with 0 and starts with 1, as we have already written a code for deletion of index 0 in the previous function.
        p = p-> next;
        q= q->next;
    }

    p->next= q->next;
    free (q);

    return head;
}

//Case 3: DELETING THE LAST ELEMENT 
struct Node * deleteLast(struct Node * head){
    struct Node * p = head;
    struct Node * q = head-> next;
    
    while(q->next != NULL){
        p = p-> next;
        q= q->next;
    }

    p->next=NULL;
    free(q);
    return head;
}

//Case 4: DELETING THE FIRST NODE WITH A GIVEN VALUE.
struct Node * deleteAtValue(struct Node * head, int value){
    struct Node * p = head;
    struct Node * q = head->next;

    while(q->data!=value && q->next!=NULL){
        p= p->next;
        q= q->next; 
    }

    if(q->data==value){
        p->next= q->next;
        free(q);
    }
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
    third->data = 8;
    third->next = fourth;

    // Terminating the list at fourth node
    fourth->data = 1;
    fourth->next = NULL;

    printf("Linked list before deletion\n");
    linkedListTraversal(head);

    printf("Linked list after deletion\n");

    // //DELETING THE FIRST ELEMENT 
    // head= deleteFirst(head);

    // //DELETING AN ELEMENT IN BETWEEN THE LINKED LIST
    // head=deleteAtIndex(head, 2);

    // //DELETING THE LAST ELEMENT
    // head=deleteLast(head); 

    //DELETING THE FIRST NODE WITH A GIVEN VALUE.
    head= deleteAtValue(head, 3);
    linkedListTraversal(head);

    return 0;

}