#include <stdio.h>
#include <stdlib.h>

struct SparseEntry
{
    int index, data;
    struct SparseEntry *next;
};

struct SparseEntry *head = NULL;

void printSparseMatrix(int rows, int cols)
{
    printf("The sparse matrix is: \n");
    for (int i = 0; i < rows * cols; i++)
    {
        struct SparseEntry *temp = head;
        int nonzeroentry = 0;
        if ((i + 1) % cols == 1)
        {
            printf("[\t");
        }
        while (temp != NULL)
        {
            nonzeroentry = 0;
            if (temp->index == i)
            {
                nonzeroentry = 1;
                printf("%d\t", temp->data);
                break;
            }
            temp = temp->next;
        }
        if (nonzeroentry == 0)
        {
            printf("0\t");
        }
        if ((i + 1) % cols == 0)
        {
            printf("]\n");
        }
    }
}

int indexAlreadyFilled(int index)
{
    struct SparseEntry *temp = head;
    while (temp != NULL)
    {
        if (temp->index == index)
        {
            return 1;
        }
        temp = temp->next;
    }
}

void printMatrix(int rows, int cols)
{
    for (int i = 0; i < rows * cols; i++)
    {
        if ((i + 1) % cols == 1)
        {
            printf("[\t");
        }
        printf("%d\t", i);
        if ((i + 1) % cols == 0)
        {
            printf("]\n");
        }
    }
}

struct SparseEntry *createNonZeroEntry(int data, int index)
{
    struct SparseEntry *entry = (struct SparseEntry *)malloc(sizeof(struct SparseEntry));
    entry->data = data;
    entry->index = index;
    entry->next = NULL;
    if (head == NULL)
    {
        head = entry;
    }
    else
    {
        struct SparseEntry *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = entry;
    }
    return entry;
}