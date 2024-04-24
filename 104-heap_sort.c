#include "sort.h"
/**
 * heap_sort - Sorts an array of integers in ascending order using
 * the heap sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 *
 * Description: Assume that the input array is a distorted heap tree data
 * structure then find the max node of this heap structure
 *
 * Return: Nothing
 */
void heap_sort(int *array, size_t size)
{
	int mid, i, temp;

	if (array && size > 1)
	{
		mid = (size / 2) - 1;
		for (i = mid; i >= 0; i--)
		{
			heapify(array, size, (int)size, i);
		}
		i = size - 1;
		while (i > 0)
		{
			temp = array[0];
			array[0] = array[i];
			array[i] = temp;
			print_array(array, size);
			heapify(array, size, i, 0);
			i--;
		}
	}
}
/**
 * heapify - Construct a heap data structure from the input array
 * @array: The input array
 * @size: The size of the array
 * @n: The size of the heap data structure which is part of the input array
 * @root: The index of an array as starting root node of a heap tree
 *
 * Description: This function will find the largest node in the array as the
 * root of the heap data strucutre recursively.
 *
 * Return: Nothing
 */
void heapify(int *array, size_t size, int n, int root)
{
	int left_node, right_node, root_node, temp;

	root_node = root;
	left_node = (root_node * 2) + 1;
	right_node = (root_node * 2) + 2;
	/*Check if root node is a left node*/
	if (left_node < n && array[root_node] < array[left_node])
		root_node = left_node;
	/*Check if the root node is not left but the right node*/
	if (right_node < n && array[root_node] < array[right_node])
		root_node = right_node;
	if (root_node != root)
	{
		temp = array[root];
		array[root] = array[root_node];
		array[root_node] = temp;
		print_array(array, size);
		/*Continue finding the largest node of the heap*/
		heapify(array, size, n, root_node);
	}
}
