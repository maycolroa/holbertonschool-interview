#include "substring.h"

/**
 * not_in - return 1 if 'q' not in array 'arr'
 * @arr: array
 * @len: array
 * @q: value
 * Return: 1, 0
 */
int not_in(int *arr, int len, int q)
{
	int i = 0;

	for (i = 0; i < len; i++)
	{
		if (arr[i] == q)
			return (0);
	}
	return (1);
}

/**
 * str_match - match word as a substring of str
 * @str: string
 * @word: array
 * Return: 1, 0
 */
int str_match(char const *str, char const *word)
{
	int i = 0;

	for (i = 0; *(word + i) != '\0'; i++)
	{
		if (*(str + i) != *(word + i))
			return (0);
	}
	return (1);
}

/**
 * full_match - find if a substring match occurs at a single location
 * @s: string
 * @words: array
 * @nb_words: number
 * @word_len: length of each word
 * Return: 1, otherwise
 */
int full_match(char const *s, char const **words, int nb_words, int word_len)
{
	int *done;
	int done_len = 0;
	int found = 0;
	int match = 1;
	int j, k, l;
	int aint;

	done = malloc(sizeof(int) * nb_words);

	for (l = 0; l < nb_words; l++)
		done[l] = -1;

	for (j = 0; j < nb_words; j++)
	{
		found = 0;
		for (k = 0; k < nb_words; k++)
		{
			aint = not_in(done, done_len, k);
			if (aint && str_match((s + (j * word_len)), words[k]))
			{
				done[done_len] = k;
				done_len++;
				found = 1;
				break;
			}
		}
		if (found == 0)
		{
			match = 0;
			break;
		}
	}
	free(done);
	return (match);
}

/**
 * find_substring -  finds all the possible substrings containing a list
 * @s: string
 * @words: array
 * @nb_words: number
 * @n: hold
 * Return: an array of starting indices of found substrings
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int *result;
	int str_len = 0;
	int word_len = 0;
	int i;

	*n = 0;
	if (s == NULL || words == NULL || *words == NULL || nb_words == 0)
		return (NULL);

	for (i = 0; s[i] != '\0'; i++)
		str_len++;
	for (i = 0; words[0][i] != '\0'; i++)
		word_len++;

	result = malloc(sizeof(int) * str_len);
	if (result == NULL)
		return (NULL);

	for (i = 0; *(s + i) != '\0'; i++)
	{
		if (full_match(s + i, words, nb_words, word_len))
		{
			result[*n] = i;
			*n = *n + 1;
		}
	}

	if (*n == 0)
	{
		free(result);
		return (NULL);
	}

	return (result);
}
