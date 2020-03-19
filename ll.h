#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// delete node at the beginning
int deleteAtStart(struct Node *head)
{
    if (head == NULL)
    {
        printf("\nNothing to delete!\n");
        return 0;
    }

    struct Node *deletedNode = head;
    int deletedData = deletedNode->data;
    head = head->next;
    free(deletedNode);
    // printf("\nDeleted entry = %d\n", deletedData);
    return deletedData;
}

// Insert node at end of list
struct Node *insertAtEnd(struct Node *head, int num)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = num;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
        return head;
    }
    else
    {
        struct Node *currentNode = head;
        while (currentNode->next != NULL)
        {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }
}

// prints elements in the linkedlist
void print(struct Node *head)
{
    struct Node *currentNode = head;
    if (currentNode == NULL)
    {
        printf("Nothing to print!\n");
    }
    else
    {
        while (currentNode != NULL)
        {
            printf("%d ", currentNode->data);
            currentNode = currentNode->next;
        }
        printf("\n");
    }
}

int length(struct Node *head)
{
    struct Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}