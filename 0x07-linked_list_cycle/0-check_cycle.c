#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * check_cycle - check list
 * @list: pointer list
 * return: 0, 1
 */
int check_cycle(listint_t *list)
{
	listint_t *l = list, *t = list;
	if (t == NULL)
		return (0);
	if (t->next == NULL)
		return (0);
	l = l->next;
	if (l ->next == NULL)
		return (0);
	l = l->next;
	while (l != t)
	{
		t = t->next;
		l = l->next;
		if (l->next == NULL)
			return (0);
		l = l->next;
		if (l->next == NULL)
			return (0);
	}
	return (1);
}
