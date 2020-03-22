#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Counter
{
    int length;
    struct Node *head;
};

struct Node *waitlist;
int token = 1, counters = 0;

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
        return head;
    }
}

// prints elements in the linkedlist
void print(struct Node *head)
{
    struct Node *currentNode = head;
    if (currentNode == NULL)
    {
        printf("Empty\n");
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

void createCounters(struct Counter **counterQ)
{
    for (int i = 0; i < counters; i++)
    {
        counterQ[i] = (struct Counter *)malloc(sizeof(struct Counter));
        counterQ[i]->head = NULL;
        counterQ[i]->length = 0;
    }
}

void generateWaitlist(int initialUserCount)
{
    while (token <= initialUserCount)
    {
        if (waitlist == NULL)
            waitlist = insertAtEnd(waitlist, token);
        else
            insertAtEnd(waitlist, token);
        token++;
    }
}

void initializeCounters(struct Counter **counterQ, int initialUserCount, int capacity)
{
    for (int i = 0; i < counters; i++)
    {
        while (counterQ[i]->length < capacity && token <= initialUserCount)
        {
            if (counterQ[i]->head == NULL)
                counterQ[i]->head = insertAtEnd(counterQ[i]->head, token);
            else
                insertAtEnd(counterQ[i]->head, token);
            counterQ[i]->length = counterQ[i]->length + 1;
            token++;
        }
    }
    if (token < initialUserCount)
        generateWaitlist(initialUserCount);
}

void serveCustomers(struct Counter **counterQ, int rate)
{
    int counterClone = counters;
    for (int i = 0; i < counterClone; i++)
    {
        for (int j = 0; j < rate; j++)
        {
            struct Node *temp = counterQ[i]->head;
            counterQ[i]->head = counterQ[i]->head->next;
            counterQ[i]->length = counterQ[i]->length - 1;
            free(temp);
            if (counterQ[i]->length == 0)
            {
                printf("No customers, closing counter %d\n", i + 1);
                free(counterQ[i]);
                counterQ[i] = NULL;
                counters--;
                if (counters == 0)
                    exit(0);
            }
        }
    }
}

void getNewCustomers(struct Counter **counterQ, int capacity)
{
    for (int i = 0; i < counters; i++)
    {
        int newCustomer;
        struct Node *temp;
        while (counterQ[i]->length < capacity && waitlist != NULL)
        {
            temp = waitlist;
            newCustomer = waitlist->data;
            waitlist = waitlist->next;
            insertAtEnd(counterQ[i]->head, newCustomer);
            counterQ[i]->length = counterQ[i]->length + 1;
            free(temp);
        }
    }
}

void printWaitList()
{
    printf("waitlist: ");
    print(waitlist);
    printf("\n");
}

void printCounterStatus(struct Counter **counterQ)
{
    struct Node *temp;
    for (int i = 0; i < counters; i++)
    {
        temp = counterQ[i]->head;
        printf("counter %d: ", i + 1);
        print(temp);
    }
}

void checkInitialConditions(int capacity, int rate, int initialUserCount)
{
    if (counters <= 0 || capacity <= 0 || rate <= 0 || initialUserCount <= 0)
    {
        printf("Invalid entry/entries, please check your input\n");
        exit(0);
    }
    else if (rate > capacity)
    {
        printf("Invalid rate entered!\n");
        exit(0);
    }
    else
    {
        // remove unnecessary counters
        while ((counters - 1) * capacity > initialUserCount)
        {
            counters--;
        }
    }
}