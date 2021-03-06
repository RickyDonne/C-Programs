#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}; //we could use typedef and shorten struct node but I don't want to replace them again now.

struct Node *addToEmpty(struct Node *last, int data); //use when list is empty
struct Node *addBegin(struct Node *last, int data); //adds a node to the beginning of a list
struct Node *addEnd(struct Node *last, int data); //adds a node to the end of the list
struct Node *addAfter(struct Node *last, int data, int item); //adds a node after a specific data/key
void traverse(struct Node *last); //traversal of a circular linked list

int main()
{
    struct Node *last = NULL;

    last = addToEmpty(last, 18);
    last = addBegin(last, 9);
    last = addBegin(last, 2);
    last = addEnd(last, 36);
    last = addEnd(last, 64);
    last = addAfter(last, 42, 36); //last node, data to be placed, key after which we have to place the data

    traverse(last);

    return 0;
}

struct Node *addToEmpty(struct Node *last, int data)
{
    if (last != NULL)
      return last;

    struct Node *temp =(struct Node*)malloc(sizeof(struct Node));
    temp -> data = data;
    last = temp;
    last -> next = last;
    return last;
}

struct Node *addBegin(struct Node *last, int data)
{
    if (last == NULL)
        return addToEmpty(last, data);

    struct Node *temp =(struct Node *)malloc(sizeof(struct Node));

    temp -> data = data;
    temp -> next = last -> next;
    last -> next = temp;
    return last;
}

struct Node *addEnd(struct Node *last, int data)
{
    if (last == NULL)
        return addToEmpty(last, data);

    struct Node *temp =(struct Node *)malloc(sizeof(struct Node));
    temp -> data = data;
    temp -> next = last -> next;
    last -> next = temp;
    last = temp;
    return last;
}

struct Node *addAfter(struct Node *last, int data, int item)
{
    if (last == NULL)
        return NULL;

    struct Node *temp, *p;
    p = last -> next;
    do
    {
        if (p ->data == item)
        {
            temp = (struct Node *)malloc(sizeof(struct Node));
            temp -> data = data;
            temp -> next = p -> next;
            p -> next = temp;

            if (p == last)
                last = temp;
            return last;
        }
        p = p -> next;
    }  while(p != last -> next);

    printf(" not present in the list." );
    return last;

}

void traverse(struct Node *last) //for printing of the list
{
    struct Node *p;

    if (last == NULL)
    {
        printf("List is empty.");
        return;
    }

    p = last -> next;
    do
    {
        printf("%d->", p->data);
        p = p -> next;

    }
    while(p != last->next);
    printf("NULL\n");
}

