/*
***	Swaps two first nodes of a linked stack
 */

#include "../swaplib.h"

void	ft_swap_first_two(t_stack **anchor)
{
	t_stack *ptr;
	t_stack *tmp;

	ptr = *anchor;
	if (ptr != NULL && ptr->next != NULL)
	{
		tmp = *anchor;
		*anchor = ptr->next;
		tmp->next = tmp->next->next;
		ptr = *anchor;
		ptr->next = tmp;
	}
}