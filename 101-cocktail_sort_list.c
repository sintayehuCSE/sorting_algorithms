#include "sort.h"
/**
 * cocktail_sort_list - A function that sorts a doubly linked list of integers
 * in ascending order using cocktail shaker sort algorithm
 * @list: A pointer to the doubly linked list
 *
 * Return: Nothing
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start, *bwd;
	int swapped = 1;

	if (list && *list && (*list)->next)
	{
		start = *list;
		while (swapped)
		{
			swapped = 0;
			bwd = forward_move(list, start, &swapped);
			if (!swapped)
				break;
			swapped = 0;
			start = backward_move(list, bwd, &swapped);
		}
	}
}
/**
 * forward_move - Traverse the list in forward direction
 * @list: The head pointer of the list
 * @fwd: The starting point to traverse in forward direction
 * @swap: Loop controller for checking end of sort operation
 *
 * Return: A starting point for traversing in backward direction
 */
listint_t *forward_move(listint_t **list, listint_t *fwd, int *swap)
{
	listint_t *temp = NULL;

	while (fwd->next)/*Forward traverse through the listof data*/
	{
		if (fwd->n > fwd->next->n)
		{
			temp = fwd->next;
			fwd->next = temp->next;
			if (temp->next)
				temp->next->prev = fwd;
			temp->next = fwd;
			if (!fwd->prev)/*To Re-locate list header pointer*/
			{
				temp->prev = fwd->prev;
				fwd->prev = temp;
				*list = temp;
			}
			else
			{
				fwd->prev->next = temp;
				temp->prev = fwd->prev;
				fwd->prev = temp;
			}
			*swap = 1;
			print_list(*list);
		}
		else
		{
			fwd = fwd->next;
		}
	}
	return (temp);
}
/**
 * backward_move - Traverse the list in a backward direction
 * @list: The list to traverse
 * @bwd: Starting point for backward traversing the list
 * @swap: Loop controller for checking end of sort operation
 *
 * Return: A starting point for traversing in forward direction
 */
listint_t *backward_move(listint_t **list, listint_t *bwd, int *swap)
{
	listint_t *temp = NULL;

	while (bwd->prev)/*Backward traverse through the listof data*/
	{
		if (bwd->n < bwd->prev->n)
		{
			temp = bwd->prev;
			bwd->prev = temp->prev;
			if (temp->prev)
				temp->prev->next = bwd;
			temp->prev = bwd;
			bwd->next->prev = temp;
			temp->next = bwd->next;
			bwd->next = temp;
			if (!bwd->prev)/*Re-locate list header pointer*/
				*list = bwd;
			print_list(*list);
			*swap = 1;
		}
		else
		{
			bwd = bwd->prev;
		}
	}
	return (temp);
}
