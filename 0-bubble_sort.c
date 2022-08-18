#include "sort.h"

/**
 * bubble_sort - implement the bubble sort algo in sorting and array of ints
 * in ascendng order. 
 * @array: pointer to a memory location storing an integer
 * @size: the size of the integer
 * Return: nothing
 * 
 * Description: this algo can be used to sort in reverse too;
 * by changing the comparison from > to <
 * 
 * the worstcase complexity of this algo is O(n)
 * becase if we're given a completely reverse array to sort, we have
 * to pass through the array n times, if we bubble only 1 digit at a go.
 *
 * bestcase is O(1): if we are given a sorted array, we only loop through
 * once and if no swap is made, swap counter remains 0 and loop is broken
 */
void bubble_sort(int *array, size_t size)
{
	/* set swap counter to a non zero value */
	unsigned int i, temp_size, swap_counter = -1;
	int temp;

	if (array == NULL || size == 0)
		return;

	temp_size = size;
	/* we set swap counter to -1 to start the process */
	while (swap_counter != 0)
	{
		/* set swap counter to 0 */
		swap_counter = 0;
		/* make a pass through the array to bubble larges number */
		/* temp_size - 1 because we consider 2 elements in a loop */
		for (i = 0; i < temp_size - 1; i++)
		{
			/* if a > b we swap*/
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				/* if a swap occurs increment swap counter */
				swap_counter++;
				/* PRINT ARRAY AFTER EVERY SWAP */
				print_array(array, size);
			}
		}
		/*
		 * if the unsorted array size is 2 we make one pass (i=0)
		 * on which we compare the last pair since we compare 2
		 * elements in one pass
		 * if the array size is > 2g, then we reduce the size per pass
		 * indicating that 1 element has been set and the unsorted par
		 * which we need to loop through has been reduced by one
		 */
		if (temp_size > 2)
			temp_size--;
	}
}
