#include "ticket.h"

int main()
{
    int capacity, rate, initialUserCount;
    printf("Enter number of ticket counters: ");
    scanf("%d", &counters);
    printf("Enter the max. capacity of each counter: ");
    scanf("%d", &capacity);
    printf("Enter the rate at which customers are served: ");
    scanf("%d", &rate);
    printf("Enter number of customers initially: ");
    scanf("%d", &initialUserCount);
    checkInitialConditions(capacity, rate, initialUserCount);

    struct Counter *counterQ[counters];
    createCounters(counterQ);
    initializeCounters(counterQ, initialUserCount, capacity);
    printCounterStatus(counterQ);
    printWaitList();
    while (counters > 0)
    {
        int newCustomersAreJoining;
        serveCustomers(counterQ, rate);
        getNewCustomers(counterQ, capacity);
        printCounterStatus(counterQ);
        printWaitList();
        printf("Any new customers joining the line (1/0)? ");
        scanf("%d", &newCustomersAreJoining);
        if (!newCustomersAreJoining)
            continue;
        else if (newCustomersAreJoining)
        {
            int newCustomers;
            printf("How many? ");
            scanf("%d", &newCustomers);
            while (newCustomers > 0)
            {
                if (waitlist == NULL)
                    waitlist = insertAtEnd(waitlist, token);
                else
                    insertAtEnd(waitlist, token);
                newCustomers--;
                token++;
            }
        }
        else
            printf("Invalid choice!\n");
    }
}