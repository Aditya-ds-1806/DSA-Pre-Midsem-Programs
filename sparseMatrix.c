/* 
===========================================
                    NOTES
===========================================
1. The number of zero-valued elements divided by the total number of elements is called the sparsity of the matrix.
2. A matrix will be sparse when its sparsity is greater than 0.5.
3. Density = 1 - Sparsity of the matrix
*/

#include "sparsematrix.h"

int main()
{
    int rows, cols, nonzero, index, val;
    printf("Enter size of sparse matrix (rows x cols): ");
    scanf("%d%d", &rows, &cols);
    if (rows == 0 || cols == 0)
    {
        printf("Invalid Matrix dimensions\n");
        exit(0);
    }
    printf("Assume the following mapping: \n");
    printMatrix(rows, cols);
    printf("How many non-zero values? ");
    scanf("%d", &nonzero);
    if (nonzero > (rows * cols) / 2)
    {
        printf("Matrix has too many non-zero elements, making it a DENSE MATRIX.\n");
        exit(0);
    }

    for (int i = 0; i != nonzero; i++)
    {
        printf("Enter the location of non-zero value: ");
        scanf("%d", &index);
        if (index < 0 || index > rows * cols)
        {
            printf("Invalid index\n");
            i--;
            continue;
        }
        else
        {
            if (indexAlreadyFilled(index))
            {
                printf("Enter a different index, entered index is already filled!\n");
                i--;
                continue;
            }
        }
        printf("Enter value at index %d: ", index);
        scanf("%d", &val);
        if (val == 0)
        {
            printf("Please enter a non-zero value!\n");
            i--;
            continue;
        }
        createNonZeroEntry(val, index);
    }
    printSparseMatrix(rows, cols);
    printf("sparsity is roughly %d%%\n", 100 - (nonzero * 100) / (rows * cols));
}