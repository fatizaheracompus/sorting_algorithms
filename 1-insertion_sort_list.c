#include "sort.h"

/**
 * swps - function that swap two node in doubl linked liste
 * @x: adress of 1 node
 * @y: adress of 2 NODE
 *
 * Return: void
 */
void swps(listint_t *x, listint_t *y)
{
	if (x->prev)
		x->prev->next = y;
	if (y->next)
		y->next->prev = x;
	x->next = y->next;
	y->prev = x->prev;
	x->prev = y;
	y->next = x;
}
/**
 * insertion_sort_list - function that sorted dl list use inser s
 * @list: adress of pointer
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *a, *b;

	if (list == NULL || *list == NULL || !(*list)->next)
		return;
	a = (*list)->next;
	while (a != 0)
	{
		b = a;
		a = a->next;
		while (b && b->prev)
		{
			if (b->prev->n > b->n)
			{
				swps(b->prev, b);
				if (!b->prev)
					*list = b;
				print_list((const listint_t *)*list);
			}
			else
				b = b->prev;
		}
	}
}
