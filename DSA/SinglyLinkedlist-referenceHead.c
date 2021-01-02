#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node  *next;
} link;

void append (link **head_ref, int data); //Adding to the end of the list
void push (link **head, int data); //Pushes a node at the beginning of the list
void addatpos (link **head_ref, int data, int pos); //adds a node at a particular position
void delatpos (link **head, int pos); // deletes a node from a position
void revi(link **head); //reverses a node using iteration
void recursiveprint (link *p); //prints the list in reverse order without modifying links
void print_list (link *head); //prints list
int main()
{
    link *head = NULL;
    append(&head, 8); //list is: 8
    append(&head, 16); //list is: 8, 16
    push(&head, 2); //list is: 2, 8, 16
    push(&head, -20); //list is: -20. 2, 8, 16
    addatpos(&head, 0, 3); //list is: -20, 2, 0, 8, 16
    addatpos(&head, 6, 4); //list is: -20, 2, 0, 6, 8, 16
    delatpos(&head, 3); //list is: -20, 2, 6, 8, 16
    print_list(head);
    revi(&head); //list is: 16, 8, 6, 2, -20
    print_list(head);
    
    printf("Linked list with recursive print: ");
    recursiveprint(head);
    printf("NULL\n");
    
    return 0;
}
void append(link **head_ref, int data)
{
    link *new_node = (link*)malloc(sizeof (link));
    new_node->data = data;

    if (*head_ref == NULL) //if list is empty
    {
        *head_ref = new_node;
        return;
    }
    link*prev = *head_ref;
    while (prev->next != NULL)
    {
        prev = prev->next;
    }
    prev->next = new_node;
}

void push (link **head, int data)
{
    link *new_node = (link*)malloc(sizeof(link));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void addatpos(link **head_ref, int data, int pos)
{
    link *new_node = (link*)malloc(sizeof(link));
    new_node->data = data;

    if (pos == 1) //adding to the beginning cause it will save the iteration
    {
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }
    link *prev = *head_ref;
    --pos;
    while (pos != 1)
    {
        prev = prev->next;
        --pos;
    }
    new_node->next = prev->next;
    prev->next = new_node;
}

void revi(link **head)
{
    link *current = *head;
    link *prev = NULL;
    link *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void delatpos (link **head, int pos)
{
   link *current = *head;
   if (pos == 1) //deleting the first node
   {
       *head = current->next;
       free(current);
       return;
   }

   link *prev = *head;
   while (pos != 1)
   {
       prev = current;
       current = current->next;
       --pos;
   }
   prev->next = current->next;
   free(current);
}

void recursiveprint (link *p)
{
    if (p == NULL) return;
    recursiveprint(p->next);
    printf("%d->", p->data);
}

void print_list(link *head)
{
    printf("Linked List is: ");
    link *temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

