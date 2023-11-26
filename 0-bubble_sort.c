#include "sort.h"

/**
 *bubble_sort - Function that sorte an array of integers
 *@array: array of integer
 *@size: the size of our arraye
 *return: void.
 */
void bubble_sort(int *array, size_t size)
{
int tmp;
size_t x = 0, y;

if (array == NULL || !size)
return;
	while (x < size)
	{
		for (y = 0; y < size - 1; y++)
		{
			if (array[y] > array[y + 1])
			{
				tmp = array[y];
				array[y] = array[y + 1];
				array[y + 1] = tmp;
				print_array(array, size);
			}
		}
		x++;
	}
}



