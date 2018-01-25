/*
***	Shifts up all elements of a linked stack (last becomes first)
 */

#include "../swaplib.h"

void	ft_reverse_rotate(t_stack **anchor)
{
	t_stack	*prelast;
	t_stack	*ptr;
	t_stack	*last;

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