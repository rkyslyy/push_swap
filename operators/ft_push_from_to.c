/*
***	Moves first node from one linked stack (parameter "from") to another (parameter "to")
 */

#include "../swaplib.h"

void	ft_push_from_to(t_stack **from, t_stack **to)
{
	t_stack *tmp;
	t_stack *ptr;

	if (*from != NULL)
	{
		tmp = *from;
		ptr = *from;
		*from = ptr->next;
		tmp->next = *to;
		*to = tmp;
	}
}
