#include "../swaplib.h"

int	ft_find_size(t_stack *b, int pivot)
{
	int ret;
	t_stack *ptr;

	ret = 0;
	ptr = b;
	while (ptr->next && ptr->value >= pivot)
	{
		ret += 1;
		ptr = ptr->next;
	}
	return (ret);
}

int	ft_find_size_a(t_stack *a, int pivot)
{
	int ret;
	t_stack *ptr;

	ret = 0;
	ptr = a;
	while (ptr->next && ptr->value <= pivot)
	{
		ret += 1;
		ptr = ptr->next;
	}
	return (ret);
}

int	ft_find_next(t_stack *b, int pivot)
{
	t_stack *ptr;

	ptr = b;
	while (ptr->next && ptr->value >= pivot)
		ptr = ptr->next;
	return (ptr->value);
}

int	ft_find_next_a(t_stack *a, int pivot)
{
	t_stack *ptr;

	ptr = a;
	while (ptr->next && ptr->value < pivot)
		ptr = ptr->next;
	return (ptr->value);
}
