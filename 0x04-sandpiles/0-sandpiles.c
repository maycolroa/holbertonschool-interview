#include <stdlib.h>
#include <stdio.h>
#include "sandpiles.h"

/**
 * grid_print - Print 3x3
 * @grid: 3x3 grid
 * Return: void
 */

void grid_print(int grid[3][3])
{
	int i = 0;
	int j = 0;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * sandpiles_addition - Function sum
 * @grid1: Left
 * @grid2: Right
 * Return: void
 */

void sandpiles_addition(int grid1[3][3], int grid2[3][3])
{
	int i = 0;
	int j = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
		}
	}
}

/**
 * sandpiles_topple - Function that topples a sandpile
 * @grid1: 3x3
 * Return: void
 */

void sandpiles_topple(int grid1[3][3])
{
	int i = 0;
	int j = 0;
	int gridtmp[3][3];

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			gridtmp[i][j] = 0;
		}
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] >= 4)
			{
				if (i - 1 >= 0)
				{
					gridtmp[i - 1][j] += 1;
				}
				if (i + 1 < 3)
				{
					gridtmp[i + 1][j] += 1;
				}
				if (j - 1 >= 0)
				{
					gridtmp[i][j - 1] += 1;
				}
				if (j + 1 < 3)
				{
					gridtmp[i][j + 1] += 1;
				}
				grid1[i][j] -= 4;
			}
		}
	}
	sandpiles_addition(grid1, gridtmp);
}

/**
 * when_to_print - Function that print
 * @grid1: 3x3
 * Return: void
 */

int when_to_print(int grid1[3][3])
{
	int i = 0;
	int j = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] >= 4)
				return (0);
		}
	}
	return (1);
}

/**
 * sandpiles_sum - Function that sum 
 * @grid1: Left 3x3
 * @grid2: Right 3x3
 * Return: void
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	sandpiles_addition(grid1, grid2);
	while (!when_to_print(grid1))
	{
		grid_print(grid1);
		sandpiles_topple(grid1);
	}
}
