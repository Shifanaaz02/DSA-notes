#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

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

    //allocating memory in heap
    head = (struct Node *) malloc(sizeof(struct Node)); 
    second = (struct Node *) malloc(sizeof(struct Node)); 
    third = (struct Node *) malloc(sizeof(struct Node)); 

    //linking first node with second
    
    head->data = 7;
    head->next = second;

    //linking second and third node
    second->data = 11;
    second->next = third;

    //Terminating list at third node
    third->data = 78;
    third->next = NULL;

    linkedListTraversal(head);

    return 0;
}