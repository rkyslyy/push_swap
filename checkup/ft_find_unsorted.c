#include "../swaplib.h"

// static int	ft_how_many_after(t_stack *anchor, t_stack *node)
// {
// 	t_stack *ptr;
// 	int		ret;

// 	ptr = node;
// 	ret = 0;
// 	while (ptr->value <= node->value)
// 	{
// 		ptr = ptr->next;
// 		if (ptr == NULL)
// 			ptr = anchor;
// 		if (ptr->value > node->value)
// 			break ;
// 		ret += 1;
// 	}
// 	return (ret);
// }

int			ft_find_unsorted(t_stack *anchor, int min, int max, int *mem)
{
	t_stack *ptr;
	int		gotcha;
	int		size;

	gotcha = 1;
	size = 0;
	ptr = anchor;
	min = ptr->value;
	while (ptr != NULL)
	{
		size += 1;
		if (ptr->value < min)
			min = ptr->value;
		ptr = ptr->next;
	}
	ptr = anchor;
	while (ptr != NULL)
	{
		if (ptr->next != NULL && ptr->value > ptr->next->value && !(ptr->value == max && ptr->next->value == min))
			break ;
		if (ptr->next == NULL && ptr->value > anchor->value && !(ptr->value == max && anchor->value == min))
			break ;
		gotcha += 1;
		ptr = ptr->next;
	}
	*mem = ptr->value;
	if (size - gotcha < size / 2)
		return (2);
	return (1);
}