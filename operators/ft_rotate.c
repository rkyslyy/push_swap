/*
***	Shifts up all elements of a linked list (last becomes first)
 */

#include "../swaplib.h"

void	ft_rotate(t_list **anchor)
{
	t_list *ptr;
	t_list *tmp;

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