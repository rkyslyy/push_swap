#include "../swaplib.h"

int	ft_is_swap_good(t_stack *anchor, int min, int max)
{
	int		big;
	int		little;
	int		last;
	t_stack	*ptr;
	

	ptr = anchor;
	while (ptr->next != NULL)
		ptr = ptr->next;
	last = ptr->value;
	big = anchor->value;
	little = anchor->next->value;
	if ((big == max && anchor->next->next->value == min) ||
		(big != max && big < anchor->next->next->value))
		if (little > last || (little == min && last == max))
			return (1);
	return (0);
}