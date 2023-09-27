#include "sort.h"

/**
 * swp - swap two integers
 * @array: the array of integer
 * @size: the size of array
 * @x: adress of the 1 value
 * @y: adress of 2 value
 * Return: void
 */
void swp(int *array, size_t size, int *x, int *y)
{
	if (*x != *y)
	{
		*x = *x + *y;
		*y = *x - *y;
		*x = *x - *y;
		print_array((const int *)array, size);
	}
}
/**
 * partition_array - fct partition the array
 * @array: the array of integer
 * @size: the size of our array
 * @lw: low index in the range
 * @hg: high index in the range
 *
 * Return: size_t
 */
size_t partition_array(int *array, size_t size, ssize_t lw, ssize_t hg)
{
	int i, j, pvt = array[hg];

	for (i = j = lw; j < hg; j++)
		if (array[j] < pvt)
			swp(array, size, &array[j], &array[i++]);
	swp(array, size, &array[i], &array[hg]);
	return (i);
}
/**
 * sort_array - sort the array by the partitionarray shema
 * @array: the array of integer
 * @size: the size of array
 * @lw: low index in the range
 * @hg: high index in the range
 */
void sort_array(int *array, size_t size, ssize_t lw, ssize_t hg)
{
	if (lw < hg)
	{
		size_t pi = partition_array(array, size, lw, hg);

		sort_array(array, size, lw, pi - 1);
		sort_array(array, size, pi + 1, hg);
	}
}


/**
 * quick_sort - fct sort an array integers in ascending o
 * @array: array of integers
 * @size: size of array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	sort_array(array, size, 0, size - 1);
}

