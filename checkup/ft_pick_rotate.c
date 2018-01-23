/*
***	Checks which rotating is preferable: reverse (last becomes first) or regular one (first becomes last)
 */

#include "../swaplib.h"

int	ft_pick_rotate(t_list *anchor)
{
	t_list	*ptr;
	int		size;
	int		min;
	int		gotcha;

	ptr = anchor;
	min = ptr->value;
	size = 1;
	while (ptr != NULL)
	{
		if (ptr->value < min)
			gotcha = size;
		size += 1;
		ptr = ptr->next;
	}
	if (size - gotcha < size / 2)
		return (1);
	else
		return (2);
}
