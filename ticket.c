#include "ll.h"

struct Node *init(int, int, int, struct Node **);
void printWaitlist(struct Node *, int, int, int);
void printCounters(int, struct Node **);
void serveCustomer(int, int, struct Node **);
struct Node *getNewCustomers(int, int, struct Node **, struct Node *);

int main()
{
    int counters, capacity, rate, initialUserCount;
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
    struct Node *waitlist = init(counters, capacity, initialUserCount, counterQ);
    serveCustomer(counters, rate, counterQ);
    waitlist = getNewCustomers(counters, rate, counterQ, waitlist);

    printCounters(counters, counterQ);
    printWaitlist(waitlist, counters, capacity, initialUserCount);

    // while (1)
    // {
    // char newCustomers;
    // printf("Any new customers joining the line (Y/N)?");
    // scanf("%c", &newCustomers);
    // if (newCustomers == 'Y' || newCustomers == 'y')
    // {
    //     newCustomerCount;
    //     printf("How many? ");
    //     scanf("%d", &newCustomerCount);
    //     for (int i = 0; i < counters; i++)
    //     {
    //         while (length(counterQ[i]) != capacity)
    //         {
    //             insertAtEnd(counterQ[i], );
    //         }
    //     }
    // }
    // else
    // {
    // }
    // }
    // }
}

// dequeue people from counter
void serveCustomer(int counters, int rate, struct Node **counterQ)
{
    for (int i = 0; i < counters; i++)
    {
        for (int j = 0; j < rate; j++)
        {
            struct Node *temp = counterQ[i]->next;
            deleteAtStart(counterQ[i]);
            counterQ[i] = temp;
        }
        if (counterQ[i] == NULL)
        {
            printf("No customers in counter %d. Closing counter %d", i + 1, i + 1);
        }
    }
}

// enqueue customers dequeued from waitlist
struct Node *getNewCustomers(int counters, int rate, struct Node **counterQ, struct Node *waitlist)
{
    for (int i = 0; i < counters; i++)
    {
        if (counterQ[i] != NULL)
        {
            for (int j = 0; j < rate; j++)
            {
                struct Node *temp = waitlist->next;
                insertAtEnd(counterQ[i], deleteAtStart(waitlist));
                waitlist = waitlist->next;
            }
        }
    }
    return waitlist;
}

struct Node *init(int counters, int capacity, int initialUserCount, struct Node **counterQ)
{
    struct Node *waitlist;
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
    return waitlist;
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