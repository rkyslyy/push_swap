#include "../swaplib.h"

void	ft_swap_first_two(t_list **anchor)
{
	t_list *ptr;
	t_list *tmp;

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