/*
***	Checks which rotating is preferable: reverse (last becomes first) or regular one (first becomes last)
 */

#include "../swaplib.h"

int	ft_pick_rotate(t_stack *anchor, int min)
{
	t_stack	*ptr;
	int		size;
	int		gotcha;

	ptr = anchor;
	size = 1;
	gotcha = 1;
	while (ptr != NULL)
	{
		size += 1;
		ptr = ptr->next;
	}
	ptr = anchor;
	while (ptr != NULL)
	{
		if (ptr->value == min)
			break ;
		gotcha += 1;
		ptr = ptr->next;
	}
	if (size - gotcha < size / 2)
		return (2);
	else
		return (1);
}
