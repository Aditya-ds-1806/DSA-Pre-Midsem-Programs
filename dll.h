#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;
struct Node *prev = NULL;

// returns a new node
struct Node *getNewNode()
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    return newNode;
}

// Inserts a new node at beginning of list
struct Node *insertAtStart(int num)
{
    struct Node *newNode = getNewNode();
    newNode->data = num;
    newNode->next = head;
    newNode->prev = NULL;
    if (head != NULL)
    {
        head->prev = newNode;
    }
    head = newNode;
    return newNode;
}

// Prints elements in the linkedlist forwards
void print()
{
    struct Node *currentNode = head;
    while (currentNode != NULL)
    {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
}

// Prints elements in linkedlist backwards
void printBackwards()
{
    struct Node *currentNode = head;
    while (currentNode->next != NULL)
    {
        currentNode = currentNode->next;
    }
    while (currentNode != NULL)
    {
        printf("%d ", currentNode->data);
        currentNode = currentNode->prev;
    }
    printf("\n");
}