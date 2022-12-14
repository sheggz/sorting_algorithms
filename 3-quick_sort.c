#include "sort.h"

void quick_sort_recur(int *array, int lo, int hi, size_t size);
/**
 * quick_sort - a function that implements the quick-sort algo on an array of
 * ints
 *
 * @array: a pointer to the array of ints to be sorted
 * @size: the size of the array to be sorted
 */

void quick_sort(int *array, size_t size)
{
	/* int lo = size - size, hi = size - 1; */
	/* check for valid entries */
	if (array == NULL || size < 2)
		return;
	quick_sort_recur(array, size - size, size - 1, size);
}

/**
 * quick_sort_recur - afunction that uses recursion to sort an array using
 * the quick sort algorithm
 *
 * @array: a pointer to the array to be sorted
 * @lo: the indexy of the first element in the array to be sorted
 * @hi: the index of the last element in the array to be sorted
 * @size: this is the size of the overal array.. it is only used to print
 * the entire array after the Pivot has been properlly placed
 *
 * Description: per call, we take the last element as pivot and, we place this
 * element in its ideal position in the sorted array, by placing all smaller
 * elements (smaller than pivot) to the left and all grater elements to the
 * right of pivot. we then execute same process on the elements to the right
 * and left of pivot recursively to sort those respective divisions until the
 * function is called on an array of 1 element which will cause lo and hi to
 * overlap (this is the base case)
 */
void quick_sort_recur(int *array, int lo, int hi, size_t size)
{
	size_t i, hi_idx, lo_idx, lower_than_pivot = lo - 1;
	int pivot, temp;
	/*
	 * initialize to non-zero value since
	 * we aint sure if idx 0 holds a num < than
	 * pivot
	 */
	if (lo >= hi) /* lo and hi overlaps if array size is 1 */
		return;
	hi_idx = hi;
	lo_idx = lo;
	pivot = array[hi_idx]; /* initialize pivot to last element */
	/* now partition LOMUTO style */
	for (i = lo_idx; i < hi_idx; i++)
	{
		/*
		 * if element is less than pivot, place it towards begining
		 * of the array
		 */
		if (array[i] < pivot)
		{
			lower_than_pivot++;
			/*
			 * if a number < pivot exists at position i=0, then we
			 * dont have to swap that num with itself. Also if all
			 * the numbers building up to the number in focus have
			 * been less than pivot then this number shouldnt be
			 * swapped if it is < pivot. Else we
			 * swap element lower than pivot with array[i] so that
			 * at the end we are sure tha all elements < pivot occupy
			 * positions 0-lower_than_pivot, then we put the Pivot
			 * after these
			 */
			if (i > 0 && array[i - 1] > pivot)
			{
				temp = array[lower_than_pivot];
				array[lower_than_pivot] = array[i];
				array[i] = temp;
				/* print the array after every swap */
				print_array(array, size);
			}
		}
	}
	/*
	 * now swap the pivot with array[lower_than_pivot + 1] so that the
	 * pivot is now in its ideal position
	 */

	/* if (lower_than_pivot < hi_idx - 1) */
	/*
	 *A number swapping with itself is wasteful. therefore we reduce
	 * wasteful swaps by checking if numbers that are > than the pivot
	 * exist before the pivot. if they do, they shoulf be just before the
	 * pivot since the array has been re-arranged to have all numbers <
	 * pivot towards the begining of the array.
	 */
	if (array[hi_idx - 1] > pivot)
	{
		array[hi_idx] = array[lower_than_pivot + 1];
		array[lower_than_pivot + 1] = pivot;
		print_array(array, size); /* print once pivot is in d right position */
	}
	/* sort left part */
	quick_sort_recur(array, lo_idx, lower_than_pivot, size);
	/*sort right part */
	quick_sort_recur(array, lower_than_pivot + 2, hi_idx, size);
}
