#include "../swaplib.h"

int	ft_find_some(t_stack *b, int min, int max, t_stack *a)
{
	t_stack *ptr;

	ptr = b;
	while (ptr != NULL)
	{
		if ((ptr->value > min && ptr->value < max) ||
			(min == ft_get_min(a) && max == ft_get_max(a) &&
				ptr->value > max))
			return (1);
		ptr = ptr->next;
	}
	return (0);
}