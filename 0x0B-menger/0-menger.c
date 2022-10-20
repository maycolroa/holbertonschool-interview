#include <stddef.h>
#include <math.h>
#include "menger.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * menger - Function that draws a 2D Menger Sponge
 * @level:  Level
 * Return: none
 */
void menger(int level)
{
    int col, row, size;

    if (level >= 0)
    {
        size = pow(3, level);
        for (col = 0; col < size; col++)
        {
            for (row = 0; row < size; row++)
                printf("%c", printer(col, row));
            printf("\n");
        }
    }
}
/**
 * printer - Checks wheter"
 * @col: Column
 * @row: Row
 * Return: # or " "
 */
char printer(int col, int row)
{
    for (; col && row; col /= 3, row /= 3)
        if (col % 3 == 1 && row % 3 == 1)
            return (' ');
    return ('#');
}
