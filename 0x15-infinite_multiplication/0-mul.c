#include "holberton.h"

/**
 * _print - moves a string
 * @str: string
 * @l: size
 * Return: none
 */
void _print(char *str, int l)
{
	int j, k;

	j = k = 0;
	while (j < l)
	{
		if (str[j] != '0')
			k = 1;
		if (k || j == l - 1)
			_putchar(str[j]);
		j++;
	}

	_putchar('\n');
	free(str);
}

/**
 * mul - multiplies a char
 * @n: char
 * @num: string
 * @num_index: last not NULL
 * @dest: destination
 * @dest_index: highest index to start addition
 * Return: pointer, NULL
 */
char *mul(char n, char *num, int num_index, char *dest, int dest_index)
{
	int j, k, mul, mulrem, add, addrem;

	mulrem = addrem = 0;
	for (j = num_index, k = dest_index; j >= 0; j--, k--)
	{
		mul = (n - '0') * (num[j] - '0') + mulrem;
		mulrem = mul / 10;
		add = (dest[k] - '0') + (mul % 10) + addrem;
		addrem = add / 10;
		dest[k] = add % 10 + '0';
	}
	for (addrem += mulrem; k >= 0 && addrem; k--)
	{
		add = (dest[k] - '0') + addrem;
		addrem = add / 10;
		dest[k] = add % 10 + '0';
	}
	if (addrem)
		return (NULL);
	return (dest);
}
/**
 * check_digits - validate if the arguments are digits
 * @av: double pointer arguments
 * Return: 0 if a digit, otherwise 1
 */
int check_digits(char **av)
{
	int i, j;

	for (i = 1; i < 3; i++)
		for (j = 0; av[i][j]; j++)
			if (av[i][j] < '0' || av[i][j] > '9')
				return (1);
	return (0);
}

/**
 * init - initializes a string
 * @str: sting to initialize
 * @l: length of string
 *
 * Return: void
 */
void init(char *str, int l)
{
	int i;

	for (i = 0; i < l; i++)
		str[i] = '0';
	str[i] = '\0';
}

/**
 * main - entry point for multiply two numbers
 * @argc: number of arguments
 * @argv: double pointer if arguments
 *
 * Return: 0 if success, 98 on error
 */
int main(int argc, char *argv[])
{
	int l1, l2, ln, ti, i;
	char *a;
	char *t;
	char e[] = "Error\n";

	if (argc != 3 || check_digits(argv))
	{
		for (ti = 0; e[ti]; ti++)
			_putchar(e[ti]);
		exit(98);
	}
	for (l1 = 0; argv[1][l1]; l1++)
		;
	for (l2 = 0; argv[2][l2]; l2++)
		;
	ln = l1 + l2 + 1;
	a = malloc(ln * sizeof(char));
	if (!a)
	{
		for (ti = 0; e[ti]; ti++)
			_putchar(e[ti]);
		exit(98);
	}
	init(a, ln - 1);
	for (ti = l2 - 1, i = 0; ti >= 0; ti--, i++)
	{
		t = mul(argv[2][ti], argv[1], l1 - 1, a, (ln - 2) - i);
		if (!t)
		{
			for (ti = 0; e[ti]; ti++)
				_putchar(e[ti]);
			free(a);
			exit(98);
		}
	}
	_print(a, ln - 1);
	return (0);
}
