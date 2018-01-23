/*
***	Shifts up all elements of a linked list (first becomes last)
 */

#include "../swaplib.h"

void	ft_reverse_rotate(t_list **anchor)
{
	t_list	*prelast;
	t_list	*ptr;
	t_list	*last;

	ptr = *anchor;
	if (ptr != NULL && ptr->next != NULL)
	{
		prelast = ptr;
		while (prelast->next->next != NULL)
			prelast = prelast->next;
		last = ptr;
		while (last->next != NULL)
			last = last->next;
		last->next = *anchor;
		*anchor = last;
		prelast->next = NULL;
	}
}