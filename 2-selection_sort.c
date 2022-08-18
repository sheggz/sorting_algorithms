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
	/* set
	 * ;ik swap counter to a non zero value */
	size_t i, unsorted_start_idx, smallest_num_idx;
	int smallest_num;

	if (array == NULL || size < 2)
		return;
	/* keep track of the beginning idx of the unsorted part of d array */
	unsorted_start_idx = 0;
	/* assume the smallest number is the first in the array */
	smallest_num = array[unsorted_start_idx];
	/*
	 * WHEN start idx of the unsorted part of the array is size-1
	 * then only 1 element (LAST element of the array) is unsorted. and
	 * that element is in its right position
	 */
	/*
	 * we pass though the entire "unsorted" array from 0 - (size - 2).
	 * the size of the unsorted part of the array reduces per pass
	 * since one element is placed in its right position on each pass
	 * on each pass
	 * we compare the elemwnt we are on, with all other elements after it
	 * searching for any element smaller than the one we are on
	 */
	while (unsorted_start_idx < size - 1)
	{
		/*
		 * on each pass we compare the element we are on, with all
		 * other elements AFTER the one in focus.
		 */
		for (i = unsorted_start_idx + 1; i < size; i++)
		{
			/* check for a possible "new smallest number" */
			if (array[i] < smallest_num)
			{
				/* if we find a new smallest num,store its */
				/* val and note its idx */
				smallest_num = array[i];
				smallest_num_idx = i;
			}
		}
		/**
		 * if a new smallest number is found, we swap this number with
		 * the one initially assumed
		 */
		if (array[unsorted_start_idx] != smallest_num)
		{
			array[smallest_num_idx] = array[unsorted_start_idx];
			array[unsorted_start_idx] = smallest_num;
			print_array(array, size);
		}
		smallest_num = array[++unsorted_start_idx];
	}
}
