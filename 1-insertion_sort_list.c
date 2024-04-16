#include "sort.h"
/**
 * insertion_sort_list - An insertion sort algorithm
 * @list: The list to sort
 *
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *traverse, *insert, *temp;

	if (list && *list && (*list)->next)
	{
		traverse = *list;
		while (traverse)
		{
			insert = traverse;
			traverse = traverse->next;
			while (insert->prev)
			{
				if (insert->n < insert->prev->n)
				{
					/*Swap and print*/
					temp = insert->prev;
					temp->next = insert->next;
					insert->next->prev = temp;
					insert->next = temp;
					if (temp->prev)
					{
						insert->prev = temp->prev;
						temp->prev->next = insert;
						temp->prev = insert;
					}
					else
					{
						insert->prev = temp->prev;
						temp->prev = insert;
						*list = insert;
					}
					print_list(*list);
				}
				else
				{
					break;
				}
			}
		}
	}
}
