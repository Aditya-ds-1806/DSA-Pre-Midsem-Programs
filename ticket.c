#include "ll.h"

void printWaitlist(struct Node *, int, int, int);
void printCounters(int, struct Node **);
void init(int counters, int, int, struct Node *, struct Node **);

int main()
{
    int counters, capacity, rate, initialUserCount;
    struct Node *waitlist;
    printf("Enter number of ticket counters: ");
    scanf("%d", &counters);
    printf("Enter the max. capacity of each counter: ");
    scanf("%d", &capacity);
    printf("Enter the rate at which customers are served: ");
    scanf("%d", &rate);
    printf("Enter number of customers initially: ");
    scanf("%d", &initialUserCount);
    struct Node *counterQ[counters];

    printf("Initial Configuration");
    // remove unnecessary initial counters
    while ((counters - 1) * capacity > initialUserCount)
    {
        counters--;
    }
    // initial scenario
    init(counters, capacity, initialUserCount, waitlist, counterQ);
}

void init(int counters, int capacity, int initialUserCount, struct Node *waitlist, struct Node **counterQ)
{
    for (int i = 0; i < counters; i++)
    {
        if (counters * capacity < initialUserCount)
        {
            waitlist = insertAtEnd(NULL, counters * capacity + 1);
            for (int j = counters * capacity + 2; j <= initialUserCount; j++)
            {

                insertAtEnd(waitlist, j);
            }
        }
        counterQ[i] = insertAtEnd(NULL, 1 + i * capacity);
        for (int j = 0; j < capacity - 1; j++)
        {
            if (2 + i * capacity + j <= initialUserCount)
                insertAtEnd(counterQ[i], 2 + i * capacity + j);
        }
    }
    printCounters(counters, counterQ);
    printWaitlist(waitlist, counters, capacity, initialUserCount);
}

void printCounters(int counters, struct Node **counterQ)
{

    for (int i = 0; i < counters; i++)
    {
        if (counterQ[i] == NULL)
        {
            continue;
        }
        else
        {
            struct Node *head = counterQ[i];
            printf("\ncounter %d: ", i + 1);
            for (; head != NULL; head = head->next)
            {
                printf("%d ", head->data);
            }
        }
    }
}

void printWaitlist(struct Node *waitlist, int counters, int capacity, int users)
{
    printf("\nwaitlist: ");
    // waitlist = insertAtEnd(NULL, counters * capacity + 1);
    if (counters * capacity < users)
    {
        struct Node *temp = waitlist;
        for (; temp != NULL; temp = temp->next)
        {
            printf("%d ", temp->data);
        }
    }
}