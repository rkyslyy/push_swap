#include "../swaplib.h"

int	ft_get_max(t_stack *anchor)
{
	t_stack *ptr;
	int		max;

	ptr = anchor;
	max = ptr->value;
	while (ptr != NULL)
	{
		if (ptr->value > max)
			max = ptr->value;
		ptr = ptr->next;
	}
	return (max);
}