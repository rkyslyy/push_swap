#include "../swaplib.h"

int	ft_check_if_one_unsorted(t_stack *anchor, t_stack *node, int min, int max)
{
	t_stack *ptr;
	int		mem;
	int		count;

	ptr = node;
	count = 0;
	mem = ptr->value;
	if (mem != max)
	{
		while (ptr->value <= mem)
		{
			count += 1;
			ptr = ptr->next;
			if (ptr == NULL)
				ptr = anchor;
		}
	}
	else
	{
		while (ptr->value != min)
		{
			count += 1;
			ptr = ptr->next;
			if (ptr == NULL)
				ptr = anchor;
		}
	}
	if (count == 1)
		return (1);
	return (0);
}