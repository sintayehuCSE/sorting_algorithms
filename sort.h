#ifndef SORTING_ALGORITHM
#define SORTING_ALGORITHM

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
*/
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;
/*............Function Protype...............*/
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void modselect(int *a, size_t n);
void quick_sort(int *array, size_t size);
void quickly_sort(int *array, int low, int high, size_t size);
size_t partition_array(int *array, int low, int high, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
listint_t *forward_move(listint_t **list, listint_t *fwd, int *swap);
listint_t *backward_move(listint_t **list, listint_t *bwd, int *swap);


/*......Alternative solutions to a quick sort algorithm/copied though......*/
void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);

#endif /* SORTING_ALGORITHM */
