#include "../swaplib.h"

void	ft_reverse_rotate_b(t_stack **b, int *total)
{
	ft_reverse_rotate(&*b);
	ft_printf("rrb\n");
	*total += 1;
}
