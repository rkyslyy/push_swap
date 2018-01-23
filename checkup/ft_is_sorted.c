/*
***	Checks if the list is sorted by ascending order of it`s values
 */

#include "../swaplib.h"

int	ft_is_sorted(t_list *anchor)
{
	t_list *ptr;

	ptr = anchor;
	while (ptr != NULL)
	{
		if (ptr->next != NULL && ptr->value > ptr->next->value)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}
