/*
***	Checks which rotating is preferable: reverse (last becomes first) or regular one (first becomes last)
 */

#include "../swaplib.h"

int	ft_pick_rotate(t_stack *anchor)
{
	t_stack	*ptr;
	int		size;
	int		gotcha;
	int		max;

	gotcha = 1;
	max = ft_get_max(anchor);
	size = ft_get_size(anchor);
	ptr = anchor;
	while (ptr != NULL)
	{
		if (ptr->value == max)
			break ;
		gotcha += 1;
		ptr = ptr->next;
	}
	if (size - gotcha < size / 2)
		return (2);
	else
		return (1);
}
