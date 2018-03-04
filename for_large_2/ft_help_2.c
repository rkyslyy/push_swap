#include "../swaplib.h"

int		ft_min(t_stack *a)
{
	int ret;
	int	count;
	t_stack *ptr;

	ret = a->value;
	count = 0;
	ptr = a;
	while (count < 3)
	{
		if (ptr->value < ret)
			ret = ptr->value;
		ptr = ptr->next;
		count += 1;
	}
	return (ret);
}

int		ft_max(t_stack *a)
{
	int ret;
	int	count;
	t_stack *ptr;

	ret = a->value;
	count = 0;
	ptr = a;
	while (count < 3)
	{
		if (ptr->value > ret)
			ret = ptr->value;
		ptr = ptr->next;
		count += 1;
	}
	return (ret);
}

int		ft_is_left(t_stack *stack, int end, int pivot, int mem)
{
	t_stack *ptr;

	ptr = stack;
	if (mem <= pivot && mem > end)
		return (1);
	while (ptr->value >= end)
	{
		if (ptr->value >= pivot)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

int		ft_is_left_a(t_stack *stack, int end, int pivot)
{
	t_stack *ptr;

	ptr = stack;
	while (ptr->value <= end)
	{
		if (ptr->value <= pivot)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}