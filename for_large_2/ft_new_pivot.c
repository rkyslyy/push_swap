#include "../swaplib.h"

static int ft_part_size(t_stack *a, int tail)
{
	int		ret;
	t_stack	*ptr;

	ret = 0;
	ptr = a;
	while (ptr->value != tail)
	{
		ret += 1;
		ptr = ptr->next;
	}
	return (ret);
}

static int	ft_part_min(t_stack *a, int tail)
{
	int		ret;
	t_stack	*ptr;

	ptr = a;
	ret = ptr->value;
	while (ptr->value != tail)
	{
		if (ptr->value < ret)
			ret = ptr->value;
		ptr = ptr->next;
	}
	return (ret);
}

static int	ft_part_max(t_stack *a, int tail)
{
	int		ret;
	t_stack	*ptr;

	ptr = a;
	ret = ptr->value;
	while (ptr->value != tail)
	{
		if (ptr->value > ret)
			ret = ptr->value;
		ptr = ptr->next;
	}
	return (ret);
}

int		ft_new_pivot(t_stack *a, int tail)
{
	int		size;
	int		count;
	int		ret;
	int		mem;
	t_stack	*ptr;

	size = ft_part_size(a, tail);
	count = 0;
	ptr = a;
	mem = ft_part_min(a, tail);
	ret = ft_part_max(a, tail);;
	while (count < (ft_part_size(a, tail) / 2))
	{
		ptr = a;
		ret = ft_part_max(a, tail);;
		while (ptr->value != tail)
		{
			if (ptr->value < ret && ptr->value > mem)
				ret = ptr->value;
			ptr = ptr->next;
		}
		mem = ret;
		count += 1;
	}
	return (ret);
}