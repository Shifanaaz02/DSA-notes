#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

struct Node * insertAtFirst(struct Node *head, int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

struct Node * insertAtIndex(struct Node * head, int data, int index){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    struct Node *p = head;
    int i=0;
    while(i!=index-1){
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;

    return head;
}

struct Node * insertAtEnd(struct Node * head, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    struct Node *p = head;
    while(p->next!=NULL){
        p = p->next;
    }
    ptr->data = data;
    p->next = ptr;
    ptr->next = NULL;

    return head;
}

struct Node * InsertAfterNode(struct Node * head, struct Node * prevNode, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;
}

void linkedListTraversal(struct Node* ptr){
    while(ptr != NULL){
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    //allocating memory in heap
    head = (struct Node *) malloc(sizeof(struct Node)); 
    second = (struct Node *) malloc(sizeof(struct Node)); 
    third = (struct Node *) malloc(sizeof(struct Node)); 
    fourth = (struct Node *) malloc(sizeof(struct Node)); 

    //linking first node with second
    
    head->data = 7;
    head->next = second;

    //linking second and third node
    second->data = 11;
    second->next = third;

    //Linking third and fourth Node
    third->data = 56;
    third->next = fourth;

    //Terminating list at fourth node
    fourth->data = 78;
    fourth->next = NULL;

    printf("Linked List Before insertion\n");
    linkedListTraversal(head);
    // head = insertAtFirst(head, 64);
    // head = insertAtIndex(head, 64,2);
    // head = insertAtEnd(head, 64);
    head = InsertAfterNode(head, second, 64);
    printf("Linked List After insertion\n");
    linkedListTraversal(head);

    return 0;
}