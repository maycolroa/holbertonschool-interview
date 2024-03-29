#include "sort.h"

/**
 * power - calculates power of 10
 * @power: power to calculate
 * Return: 10**power
 */
int power(int power)
{
	int i, result = 1;

	for (i = 0; i < power; i++)
		result *= 10;

	return (result);
}

/**
 * sorting_matrix - sort by one digit in a matrix
 * @array: array
 * @tmp: matrix
 * @size: arrray
 * @level: digit to apply sortting
 * Return: 0 if the digit is the mostright digit, otherwise 1
 */
int sorting_matrix(int *array, int **tmp, size_t size, int level)
{
	int n, k, max = 0;
	int index[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i, j;

	for (i = 0; i < size; i++)
	{
		n = (array[i] % power(level)) / power(level - 1);
		tmp[n][index[n]++] = array[i];
		if (array[i] > max)
			max = array[i];
	}

	k = 0;
	j = 0;

	for (i = 0; i < 10; i++)
	{
		while (index[i] != 0 && k < index[i])
		{
			array[j + k] = tmp[i][k];
			k++;
		}
		j += k;
		k = 0;
	}
	print_array(array, size);

	if (max / power(level) == 0)
		return (0);
	return (1);
}

/**
 * gridfree - Free a double pointer
 * @grid: double pointer
 * Return: None
 */
void gridfree(int **grid)
{
	int i;

	for (i = 0; i < 10; i++)
		free(grid[i]);
	free(grid);
}

/**
 * radix_sort - Sorts an array of integers using the Radix sort algorithm
 *
 * @array: array
 * @size: array
 * Return: None
 */
void radix_sort(int *array, size_t size)
{
	int **tmp, aux = 1, level = 1;
	size_t i;

	if (!array || size < 2)
		return;
	tmp = malloc(sizeof(int *) * 10);
	for (i = 0; i < 10; i++)
		tmp[i] = malloc(sizeof(int) * size);
	while (aux)
		aux = sorting_matrix(array, tmp, size, level++);
	gridfree(tmp);
}
