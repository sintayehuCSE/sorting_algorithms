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
	int swapped = 1;
	listint_t *start, *temp, *fwd, *bwd;

	if (!list || *list || (*list)->next)
		return;
	start = *list;
	while (swapped)
	{
		swapped = 0;
		fwd = start;
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
				swapped = 1;
				print_list(*list);
			}
			else
			{
				fwd = fwd->next;
			}
		}
		if (!swapped)/*The input is already sorted*/
			break;
		swapped = 0;
		bwd = temp;/*Limit the backward search start point*/
		swapped = 0;
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
				swapped = 1;
			}
			else
			{
				bwd = bwd->prev;
			}
		}
		start = temp;/*Limit the forward search start point*/
	}
}
