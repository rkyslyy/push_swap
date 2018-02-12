/*
***	Checks if the stack is sorted by ascending order of it`s values
 */

#include "../swaplib.h"

int	ft_is_sorted(t_stack *anchor)
{
	t_stack *ptr;
	int		min;

	ptr = anchor;
	min = ptr->value;
	while (ptr != NULL)
	{
		if (ptr->value < min)
			min = ptr->value;
		ptr = ptr->next;
	}
	ptr = anchor;
	while (ptr != NULL)
	{
		if (ptr->next != NULL && ptr->value > ptr->next->value
			&& ptr->next->value != min)
			return (0);
		if (ptr->next == NULL && 
			ptr->value > anchor->value && anchor->value != min)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}
