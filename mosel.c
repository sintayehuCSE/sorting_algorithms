#include "sort.h"
/**
 * modselect - A modified selection sort algorithm
 * @a: The array to be sorted
 * @n: The size of the array
 *
 * Return: Nothing
 */
void modselect(int *a, size_t n)
{
	size_t i = 0, j, sm;
	int temp;

	for (; i < n; i++)
	{
		sm = i;
		for (j = i + 1; j < n; j++)
		{
			if (a[j] < a[sm])
				sm = j;
		}
		if (sm != i)
		{
			temp = a[sm];
			a[sm] = a[i];
			a[i] = temp;
			print_array(a, n);
		}
	}
}
