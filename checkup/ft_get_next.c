#include "../swaplib.h"

int ft_get_next(t_stack *node, int mem, int pivot)
{
	t_stack *ptr;

	ptr = node;
	while (ptr->value != mem)
	{
		if (ptr->value < pivot)
			break ;
		ptr = ptr->next;
	}
	return (ptr->value);
}