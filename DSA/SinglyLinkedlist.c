#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}link;

link *head;
link *addatend(link *ptr, int data);
void display(link *head);
void addatbeg(link **ptr, int data);
void addatpos(link *ptr, int data, int pos);

link *delbeg(link *head);
void delend(link *head);
void delatpos(link **head, int pos);

link *dellist(link *head);
link *revlist(link *head);

int main()
{
    head = NULL;

    head = (link*)malloc(sizeof(link));
    head->data = 50;
    head->next = NULL;

    link *ptr;
    ptr = head;
    ptr = addatend(ptr, 100);
    ptr = addatend(ptr, 200);
    ptr = addatend(ptr, 250);
    ptr = addatend(ptr, 350);
    ptr = addatend(ptr, 450);
    addatbeg(&head, 5);
    addatpos(head, 150, 4);

    head = delbeg(head);
    delend(head);
    delatpos(&head, 3);
    //head = dellist(head);

    head = revlist(head);

    if(head == NULL)
    {
        printf("List is empty\n");
    }

    display(head);
    return 0;

}

link *revlist(link *head){
    link *current = head;
    link *prev = NULL;

    while(head != NULL)
    {
        current = current->next;
        head->next = prev;
        prev = head;
        head = current;
    }
    head = prev;
    return head;
}

link *dellist(link *head){
    link *current = head;

    while(current != NULL)
    {
        current = current->next;
        free(head);
        head = current;
    }
    return head;
}

void delatpos(link **head, int pos){
    link *current = *head;
    link *prev = *head;

    while(pos != 1)
    {
        prev = current;
        current = current->next;
        --pos;
    }
    prev->next = current->next;
    free(current);
    current = NULL;
}

void delend(link *head){
    link *ptr = head;

    while(ptr->next->next  != NULL)
    {
        ptr = ptr->next;
    }
    free(ptr->next);
    ptr->next = NULL;

}

link *delbeg(link *head){
    link *temp = head;
    head = temp->next;
    free(temp);
    temp = NULL;
    return head;
}

void addatpos(link *ptr, int data, int pos){
    link *temp = ptr;
    link *temp2 = (link*)malloc(sizeof(link));
    temp2->data = data;
    temp2->next = NULL;

    --pos;
    while(pos != 1)
    {
        temp = temp->next;
        --pos;
    }
    temp2->next = temp->next;
    temp->next = temp2;
}

void addatbeg(link **ptr, int data){
    link *temp = (link*)malloc(sizeof(link));
    temp->data = data;
    temp->next = *ptr;

    *ptr = temp;
    return temp;
}

link *addatend(link *ptr, int data){
    link *temp = (link*)malloc(sizeof(link));
    temp->data = data;
    temp->next = NULL;
    ptr->next = temp;
    return temp;
}

void display(link *head){
    link *ptr = head;
    while (ptr != NULL)
    {
        printf("%d--->", ptr->data);
        ptr = ptr->next;
    }
}
