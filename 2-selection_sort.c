#include "sort.h"

/**
 * selection_sort - implement selection sort algo in sorting an array of ints
 * in ascendng order.
 * @array: pointer to a memory location storing an integer
 * @size: the size of the integer
 * Return: nothing
 *
 * Description: this algo will assume the number at the begining of d unsorted
 * part of the array is the smallest. on each pass we compare this num against
 * other elements to get the smallest num in the unsorted array. we then swap
 * the num with the num at the first index of the unsorted part of the array.
 * This sorts the array from L-R. we can also sort from R-L by looking for the
 * biggest number on each pass and swapping with the INDEX[n-1] of the unsorted
 * part array
 *
 * This algo can be used to sort in reverse too by searching for d biggest num
 * on each pass and swapping it with idx[0] or smalles num and swapping with
 * idx[n]
 *
 * NOTE: that the size of the unsorted part of the array reduces per pass
 *
 * the worstcase complexity of this algo is O(n)
 * becase if we're given a completely reverse array to sort, we have
 * to pass through the array n times, if we bubble only 1 digit at a go.
 *
 * bestcase is O(n): if we are given a sorted array, both loops will still be
 * executed since there is no way of knowing that a number is in the right
 * position without
 */
void selection_sort(int *array, size_t size)
{
	/* set swap counter to a non zero value */
	unsigned int i, unsorted_start_idx, smallest_num_idx = 0;
	int smallest_num;

	if (array == NULL || size < 2)
		return;
	/* keep track of the beginning idx of the unsorted part of d array */
	unsorted_start_idx = 0;
	/* assume the smallest number is the first in the array */
	smallest_num = array[unsorted_start_idx];
	/*
	 * if start idx of the unsorted part of the array is size-1
	 * then only 1 element is unsorted. and that element is in its right
	 * position
	 */

	while (unsorted_start_idx < size - 1)
	{
		/*
		 * once we have some elements unsorted, we pass through the
		 * array sorting the array from the left - one element at
		 * a time
		 * d size of d unsorted part of d array reduces per pass
		 * as unsorted_start_idx increases per pass
		 */
		for (i = unsorted_start_idx; i < size; i++)
		{
			if (array[i] < smallest_num)
			{
				/* store smallest val and note d idx */
				smallest_num = array[i];
				smallest_num_idx = i;
			}
		}
		/**
		 *  AFTER EACH PASS, WE SWAP smallest digit found in unsorted
		 * array with the digit at the first element of the "unsorted"
		 * part of the array
		 */

		array[smallest_num_idx] = array[unsorted_start_idx];
		/* increment unsorted_start_idx per swap */
		array[unsorted_start_idx] = smallest_num;
		smallest_num = array[++unsorted_start_idx];
		print_array(array, size);
	}
}
