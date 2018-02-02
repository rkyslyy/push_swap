#include "../swaplib.h"

int	ft_check_if_swap_good(t_stack *anchor, t_stack *node, int min, int max)
{
	int		mem;
	int		next;
	t_stack	*circle;

	mem = node->value;
	circle = node;
	if (node->next == NULL)
		next = anchor->value;
	else
		next = node->next->value;
	if (mem != max)
	{
		if (node->next != NULL)
			if (mem < node->next->value)
			{
				
			}
	}
}