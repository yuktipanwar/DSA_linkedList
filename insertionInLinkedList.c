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

//Case 1: INSERTION AT THE BEGINNING 
struct Node * insertAtFirst(struct Node *head, int data){
    struct Node* ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data; 
    return ptr;
}

//Case 2: INSERTION IN BETWEEN
struct Node * insertinBetween(struct Node *head, int data, int index){ 
    struct Node* ptr = (struct Node *) malloc(sizeof(struct Node));

    struct Node* p = head;
    int i=0;

    while(i!=index-1){
        p= p->next;
        i++;
    }

    ptr->data= data;
    ptr->next = p ->next;
    p->next = ptr;

    return head;
}

//Case 3: INSERTION AT THE END
struct Node * insertAtEnd(struct Node *head, int data){
    struct Node* ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data= data;
    struct Node * p = head;
     
    while(p->next!=NULL){
        p=p->next;
    }
    p->next = ptr ;
    ptr->next = NULL; 
    return head;
}

//Case 4: INSERTION AFTER A NODE
struct Node * insertAfterNode(struct Node * head, struct Node * prevNode, int data){
    struct Node* ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data= data;

    ptr->next= prevNode->next; 
    prevNode->next=ptr;

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
    head->data = 7;
    head->next = second;

    // Link second and third nodes
    second->data = 11;
    second->next = third;

    // Link third and fouth nodes
    third->data = 66;
    third->next = fourth;

    // Terminating the list at fourth node
    fourth->data = 78;
    fourth->next = NULL;

    printf("Linked list before insertion\n");
    linkedListTraversal(head);

    printf("Linked list after insertion\n");

    // //INSERTION AT THE BEGINNING 
    // head = insertAtFirst(head, 56);
    // linkedListTraversal(head);

    // //INSERTION IN BETWEEN
    // head = insertinBetween(head, 56, 1);
    // linkedListTraversal(head);

    // //INSERTION AT THE END
    // head = insertAtEnd(head, 56);
    // linkedListTraversal(head);

    //INSERTION AFTER A NODE
    head= insertAfterNode(head, second, 56);
    linkedListTraversal(head);



    return 0;
    
}
