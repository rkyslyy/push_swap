/*
***	Shifts up all elements of a linked stack (first becomes last)
 */

#include "../swaplib.h"

void	ft_rotate(t_stack **anchor)
{
	t_stack *ptr;
	t_stack *tmp;

	ptr = *anchor;
	if (ptr != NULL && ptr->next != NULL)
	{
		tmp = *anchor;
		*anchor = ptr->next;
		ptr = *anchor;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = tmp;
		tmp->next = NULL;
	}
}