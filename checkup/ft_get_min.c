#include "../swaplib.h"

int	ft_get_min(t_stack *anchor)
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
	return (min);
}