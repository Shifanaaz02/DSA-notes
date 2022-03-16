#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node * DeleteFirstNode(struct Node * head){
    struct Node * ptr = head;
    head = head ->next;
    free(ptr);
    return head;
}

struct Node * DeleteNodeBetween(struct Node * head, int index){
    struct Node *p = head;
    int i=0;
    while(i!=(index-1)){
        p = p->next;
        i++;
    }
    struct Node * q = p->next;
    p->next = q->next;
    free(q);
    return head;
}

struct Node * DeleteLastNode(struct Node * head){
    struct Node *p = head;
    struct Node *q = p->next;
    int i=0;
    while(q->next != NULL){
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = NULL;
    free(q);
    return head;
}

struct Node * DeleteNodevalue(struct Node * head, int value){
    struct Node *p = head;
    struct Node *q = p->next;
    while(q->data != value){
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
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
    struct Node *fifth;

    //allocating memory in heap
    head = (struct Node *) malloc(sizeof(struct Node)); 
    second = (struct Node *) malloc(sizeof(struct Node)); 
    third = (struct Node *) malloc(sizeof(struct Node)); 
    fourth = (struct Node *) malloc(sizeof(struct Node)); 
    fifth = (struct Node *) malloc(sizeof(struct Node)); 

    //linking first node with second
    
    head->data = 7;
    head->next = second;

    //linking second and third node
    second->data = 11;
    second->next = third;

    //linking second and third node
    third->data = 78;
    third->next = fourth;

    //linking fourth and third node
    fourth->data = 64;
    fourth->next = fifth;

    //Terminating list at fifth node
    fifth->data = 88;
    fifth->next = NULL;

    printf("Elements Before deletion \n");
    linkedListTraversal(head);
    // head = DeleteFirstNode(head);
    // head = DeleteNodeBetween(head,3);
    head = DeleteNodevalue(head,78);
    printf("Elements After deletion \n");
    linkedListTraversal(head);

    return 0;
}