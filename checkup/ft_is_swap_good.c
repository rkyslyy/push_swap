#include "../swaplib.h"

// static int	ft_how_many(t_stack *anchor, int max, int min)
// {
// 	t_stack *ptr;
// 	int		mem;
// 	int		ret;

// 	ptr = anchor;
// 	mem = ptr->value;
// 	ret = 0;
// 	if (mem == max)
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
	if ((big == max && (anchor->next->next->value == min)) ||
		(big != max && (big < anchor->next->next->value)))
		if (little > last || (little == min && last == max))
			return (1);
	// if (ft_how_many(anchor, max, min) < 3)
	// 	return (1);
	return (0);
}