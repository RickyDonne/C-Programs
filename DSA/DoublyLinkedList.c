#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} link;

void append(link **head, int data);
void push(link **head, int data);
void print_list(link *head);

int main()
{
    link *head = NULL;
    
    append(&head, 8);
    append(&head, 16);
    push(&head, 2);
    
    print_list(head);
    return 0;
}

void append(link **head, int data)
{
    link *new_node = (link*)malloc(sizeof(link));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL)
    {
        new_node->prev = NULL;
        *head = new_node;
        return;
    }
    link *last = *head;
    while(last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;
    new_node->prev = last;
}

void push(link **head, int data)
{
    link *new_node = (link*)malloc(sizeof(link));
    new_node->data = data;
    new_node->next = *head;
    new_node->prev = NULL;

    if (*head != NULL)
        (*head)->prev = new_node;
    *head = new_node;
}

void print_list(link *head)
{
    link *current = head;
    link *last;

    printf("DLL forward print\n");
    while(current != NULL)
    {
        printf("%d ", current->data);
        last = current;
        current = current->next;
    }

    printf("\nDLL reversed print\n");
    while(last != NULL)
    {
        printf("%d ", last->data);
        last = last->prev;
    }
}
