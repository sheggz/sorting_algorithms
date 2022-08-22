#include <stdio.h>
#include <stdlib.h>
#include "../sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {1,2,3,4,5,6,7,8};
    /*{19, 73, 48, 99, 19, 71, 13, 52, 96, 19, 73, 86, 7}*/
    int array2[] = {-92, 3, 2, -31, -76, -54, -52, -88, -7, -74, -6, -53, 4, -9, -78, -15, -83, -3, -23, -96};
    size_t n = sizeof(array) / sizeof(array[0]);
    size_t n2 = sizeof(array2) / sizeof(array2[0]);

    print_array(array, n);
    printf("\n");
    selection_sort(array, n);
    printf("\n");
    print_array(array, n);
    print_array(array2, n2);
    printf("\n");
    selection_sort(array2, n2);
    printf("\n");
    print_array(array2, n2);
    return (0);
}
