#include "include/ex3.h"
#include <string.h>

void decode(char *cmd)
{
    int size = strlen(cmd);
    int sqr = sqrt(size);
    int flag = 0;

    // Check if input string is a perfect square
    for (int check = 2; check <= size / 2; check++)
    {
        if (size == check * check)
        {
            flag = 1;
            break;
        }
    }

    char **matrix = (char **)malloc(sqr * sizeof(char *));

    // Allocate memory for matrix
    for (int i = 0; i < sqr; i++)
    {
        matrix[i] = (char *)malloc(sqr * sizeof(char));
    }

    // Return INVALID if not perfect sqr
    if (flag == 0)
    {
        printf("INVALID\n");
    }

    else
    {
        // Convert string to NxN matrix in column-major order
        for (int i = 0; i < sqr; i++)
        {
            for (int j = 0; j < sqr; j++)
            {
                matrix[i][j] = cmd[i * sqr + j];
            }
        }
        // Print elements in row major order
        for (int j = 0; j < sqr; j++)
        {
            for (int i = 0; i < sqr; i++)
            {
                printf("%c", matrix[i][j]);
            }
        }
        printf("\n");
    }

    // Free allocated memory
    free(matrix);
}

int main(void)
{
    // Tests Variables
    char cmd[MAX_CHARS];

    // Test 1
    strcpy(cmd, "WE OUE OUT LNGSAO H RWDN!");
    decode(cmd); // Expected: WE ARE LOW ON DOUGHNUTS !
    memset(cmd, 0, MAX_CHARS);

    // Test 2
    strcpy(cmd, "S EFEM FNOCEDROE");
    decode(cmd); // Expected: SEND MORE COFFEE
    memset(cmd, 0, MAX_CHARS);

    // Test 3
    strcpy(cmd, "CSERULES");
    decode(cmd); // Expected: INVALID
    memset(cmd, 0, MAX_CHARS);

    return 0;
}