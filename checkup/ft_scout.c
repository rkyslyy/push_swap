#include "../swaplib.h"

int	ft_scout(t_stack *node, int mem, int pivot)
{
	t_stack *ptr;

	ptr = node;
	while (ptr != NULL && ptr->value != mem)
	{
		if (ptr->value < pivot)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}