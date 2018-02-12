#include "../swaplib.h"

static t_stack	*ft_search(t_stack *ptr, t_stack *anchor, int *gotcha)
{
	while (ptr != NULL)
	{
		if (ptr->next != NULL && ptr->value > ptr->next->value
			&& !(ptr->value == ft_get_max(anchor)
				&& ptr->next->value == ft_get_min(anchor)))
			break ;
		if (ptr->next == NULL && ptr->value > anchor->value
			&& !(ptr->value == ft_get_max(anchor)
				&& anchor->value == ft_get_min(anchor)))
			break ;
		*gotcha += 1;
		ptr = ptr->next;
	}
	return (ptr);
}

int				ft_find_unsorted(t_stack *anchor, int min, int max, int *mem)
{
	t_stack *ptr;
	int		gotcha;
	int		size;

	gotcha = 1;
	size = 0;
	ptr = anchor;
	min = ptr->value;
	max = ft_get_max(anchor);
	while (ptr != NULL)
	{
		size += 1;
		if (ptr->value < min)
			min = ptr->value;
		ptr = ptr->next;
	}
	ptr = anchor;
	ptr = ft_search(ptr, anchor, &gotcha);
	*mem = ptr->value;
	if (size - gotcha < size / 2)
		return (2);
	return (1);
}