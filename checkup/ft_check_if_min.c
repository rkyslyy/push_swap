/*
*** Checks if value in first node of the stack is the smallest one
 */

#include "../swaplib.h"

int	ft_check_if_min(t_stack *anchor)
{
	t_stack	*ptr;
	int		first;

	ptr = anchor;
	if (ptr != NULL)
	{
		first = ptr->value;
		ptr = ptr->next;
		while (ptr != NULL)
		{
			if (ptr->value < first)
				return (0);
			ptr = ptr->next;
		}
		return (1);
	}
	return (0);
}
