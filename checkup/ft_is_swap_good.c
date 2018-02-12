#include "../swaplib.h"

// static int	ft_how_many(t_stack *anchor, int ft_get_max(anchor), int min)
// {
// 	t_stack *ptr;
// 	int		mem;
// 	int		ret;

// 	ptr = anchor;
// 	mem = ptr->value;
// 	ret = 0;
// 	if (mem == ft_get_max(anchor))
// 		while (ptr->value != min)
// 		{
// 			ptr = ptr->next;
// 			if (ptr->value == min)
// 				break ;
// 			ret += 1;
// 		}
// 	else
// 		while (ptr->value <= mem)
// 		{
// 			ptr = ptr->next;
// 			if (ptr->value > mem)
// 				break ;
// 			ret += 1;
// 		}
// 	return (ret);
// }

int	ft_is_swap_good(t_stack *anchor)
{
	int		big;
	int		little;

	big = anchor->value;
	little = anchor->next->value;
	if (big > little && big < anchor->next->next->value)
		return (1);
	int		last;
	t_stack	*ptr;
	ptr = anchor;
	while (ptr->next != NULL)
		ptr = ptr->next;
	last = ptr->value;
	big = anchor->value;
	little = anchor->next->value;
	if ((big == ft_get_max(anchor) &&
		(anchor->next->next->value == ft_get_min(anchor))) ||
		(big != ft_get_max(anchor) && (big < anchor->next->next->value)))
		if (little > last || (little == ft_get_min(anchor)
			&& last == ft_get_max(anchor)))
			return (1);
	return (0);
}