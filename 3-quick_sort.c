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
	int i, pivot, hi_idx, lo_idx, temp, lower_than_pivot = lo - 1;
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
			 * swap element lower than pivot with array[i] so that
			 * at the end we are sure tha all elements < pivot occupy
			 * positions 0-lower_than_pivot, then we put the Pivot
			 * after these
			 */
			temp = array[lower_than_pivot];
			array[lower_than_pivot] = array[i];
			array[i] = temp;
		}
	}
	/*
	 * now swap the pivot with array[lower_than_pivot + 1] so that the
	 * pivot is now in its ideal position
	 */
	temp = array[hi_idx];
	array[hi_idx] = array[lower_than_pivot + 1];
	array[lower_than_pivot + 1] = temp;
	print_array(array, size); /* print once pivot is in d right position */
	/* sort left part */
	quick_sort_recur(array, lo_idx, lower_than_pivot, size);
	/*sort right part */
	quick_sort_recur(array, lower_than_pivot + 2, hi_idx, size);
}
