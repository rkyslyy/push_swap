#include "../swaplib.h"

void	ft_swap_both(t_stack **a, t_stack **b, int *total)
{
	ft_swap_first_two(&*a);
	ft_swap_first_two(&*b);
	*total += 1;
	ft_printf("ss\n");
}
