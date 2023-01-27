#include "lists.h"

/**
* find_listint_loop - function that finds the loop in a linked list.
* @head: pointer
* Return: The address of the node where the loop starts,
* or NULL if there is no loop
**/
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *j = head;
	listint_t *k = head;

	if (!head)
		return (NULL);
	while (j->next && k->next->next)
	{
		j = j->next;
		k = k->next->next;
		if (j == k)
		{
			j = head;
			while (j != k)
			{
				j = j->next;
				k = k->next;
			}
			return (k);
		}
	}
	return (NULL);
}
