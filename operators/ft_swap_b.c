#include "../swaplib.h"

void	ft_swap_b(t_stack **b, int *total)
{
	ft_swap_first_two(&*b);
	*total += 1;
	ft_printf("sb\n");
}
