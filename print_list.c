#include <stdio.h>
#include "sort.h"

/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *list)
{
    int r;

    r = 0;
    while (list)
    {
        if (r > 0)
            printf(", ");
        printf("%d", list->n);
        ++r;
        list = list->next;
    }
    printf("\n");
}
