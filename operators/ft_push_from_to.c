/*
***	Moves first node from one linked list (parameter "from") to another (parameter "to")
 */

#include "../swaplib.h"

void	ft_push_from_to(t_list **from, t_list **to)
{
	t_list *tmp;
	t_list *ptr;

	if (*from != NULL)
	{
		tmp = *from;
		ptr = *from;
		*from = ptr->next;
		tmp->next = *to;
		*to = tmp;
	}
}
