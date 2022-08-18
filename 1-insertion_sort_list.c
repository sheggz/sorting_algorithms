#include "sort.h"
/**
 * insertion_sort_list - a function that sorts a doubly linked list using
 * insertion sort algorithm.
 * @list: holds the address of the list head
 *
 * Description:  we can assume (inductively) that the first n–1 elements are
 * already sorted and insert element n in the right place. mongst the sorted
 * n-1 elements. This makes us start looping from node 1 (assuming node 0 is
 * sorted
 *
 * Time Complexity: O(n^2) on worst case, o(n) on best case since the swap loop
 * never executes if elements are in the right position with respect to the
 * sorted n-1 elements before the node in focus
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *nodeB = NULL, *nodeA = NULL, *temp = NULL;
	/*
	 * since we'd be comparing backwards for the right position in the
	 * "sorted" elements, nodeB is the node to be compared, while nodeA
	 * is the node preceeding nodeB that we'll be comparing nodeB with
	 */
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return; /* if we have only 1 node, there's nothing to sort */

	/* assume node 0 is sorted, move to node 1 and start */
	nodeB = (*list)->next;
	/* outer while loop moves forward through the list until we jam NULL */
	while (nodeB)
	{
		/*
		 * temprarily store the address of the next node
		 * while we look for the right position for this node
		 * NB: this is redundant tho, because by swapping positions, we
		 * are not changing the address stored in nodeB.
		 * so nodeB = nodeB->next at the end will suffice
		 */
		temp = nodeB->next;
		/* this inner loop places nodeB in the right position */
		/*
		 * since all nodes before this are sorted,
		 * move this node backwards until its data i.e 'n' is >
		 * than the data 'n' in the node before it {PROVIDED WE ARE
		 * NOT AT THE BEGINNING OF THE LIST}
		 */
		while (nodeB->prev != NULL && nodeB->prev->n > nodeB->n)
		{
			/* printf("%p\n", (void *)nodeB); */
			nodeA = nodeB->prev;
			/* swap process
			 * Note that if we are swapping at either extremes of
			 * the list, we'd be affecting 5 links and 3 nodes,
			 * elsewhere in the list, 6 links and 4 nodes.
			 *
			 * NB: the order of this process is important, try to
			 * visualize with a 6 node DLL. the last 2 lines MUST
			 * BE LAST!!!
			 */
			if (nodeB->next)
				nodeB->next->prev = nodeA;
			if (nodeA->prev)
				nodeA->prev->next = nodeB;
			nodeA->next = nodeB->next;
			nodeB->prev = nodeA->prev;
			nodeA->prev = nodeB;
			nodeB->next = nodeA;
			/*
			 * after swapping, now our node is in a new position
			 * if this node is now the first node
			 * of the list then we have to change the address in d
			 * header to the address of this node
			 */
			if (!(nodeB->prev))
				*list = nodeB;
			/* printf("%p\n", (void *)nodeB); */

			print_list(*list);
		}
		nodeB = temp; /* move to next unsorted node */
	}
}
/* NEVER ATTEMPT TO SWAP WITH JUST A POINTER TO THE NODE IN FOCUS LIKE I FIRST
 * DID BELOW.. BECAUSE IT WILL LEAD TO AN INFINITE LOOP SINCE ONE OF THE 6
 * AFFECTED LINKS TO BE MANIPULATED WILL BE LOST
 */
		/*
		 * node->prev->next = node->next;
		 * node->prev = node->prev->prev;
		 * if (node->next)
		 * 	node->next->prev = node->prev;
		 * node->next = node->prev;
		 * if (node->prev->prev != NULL)
		 * node->prev->prev->next = node;
		 * node->prev->prev = node;
		 */
