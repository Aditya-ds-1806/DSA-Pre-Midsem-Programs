#include "dll.h"

void browseWebsite(int URL);
void showHistory();
void back();
void next();
void currentPage();

// points to the current page/website being browsed by user
struct Node *current;

int main()
{
    int operation;
    int URL;
    printf("------------------------------------------------------\n");
    printf("     Welcome to the world's most useless browser!\n");
    printf("------------------------------------------------------\n");
    printf("1: Browse a website\t 2: Show browser history\n");
    printf("3: Go to next page\t 4: Go to previous page\n");
    printf("5: Show current page\t 6: Close Browser\n");

    while (1)
    {
        printf("\nWhat would you like to do?\n");
        scanf("%d", &operation);
        switch (operation)
        {
        case 1:
            printf("Enter URL of website: ");
            scanf("%d", &URL);
            browseWebsite(URL);
            break;

        case 2:
            showHistory();
            break;

        case 3:
            next();
            break;

        case 4:
            back();
            break;

        case 5:
            currentPage();
            break;

        case 6:
            exit(0);
            break;

        default:
            printf("Unknown operand!!!\n");
            break;
        }
    }
}

// shows contents of a website
void printPage()
{
    for (int i = 0; i < 750; i++)
    {
        printf("%c", (rand() % 26) + 97);
        if (rand() % 4 == 0)
        {
            printf(" ");
        }
    }
    printf("\n");
}

// navigates to specified URL
void browseWebsite(int URL)
{
    current = insertAtStart(URL);
    printPage();
}

// displays current page
void currentPage()
{
    printf("Current Page is: %d\n", current->data);
}

// navigates to previous page in browser history
void back()
{
    if (current->next != NULL)
    {
        current = current->next;
        printf("Previous Page is: %d\n", current->data);
        printPage();
    }
    else
        printf("Can't go back!\n");
}

// navigates to next page in history
void next()
{
    if (current->prev != NULL)
    {
        current = current->prev;
        printf("Next Page is: %d\n", current->data);
        printPage();
    }
    else
        printf("Can't go to next page!\n");
}

// displays browser history
void showHistory()
{
    if (current != NULL)
    {
        printf("Sorted by recent: ");
        print();
        printf("\nSorted by beginning of time: ");
        printBackwards();
        printf("\n");
    }
    else
    {
        printf("Nothing to show!\n");
    }
}