#include "../swaplib.h"

int	ft_get_biggest(t_stack *b, int val)
{
	t_stack *ptr;
	int		ret;

	if (val < ft_get_min(b))
		return (ft_get_max(b));
	ptr = b;
	ret = ft_get_min(b);
	while (ptr != NULL)
	{
		if (ptr->value > ret && ptr->value < val)
			ret = ptr->value;
		ptr = ptr->next;
	}
	return (ret);
}