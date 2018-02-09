#include "../swaplib.h"

void	ft_swap_a(t_stack **a, int *total)
{
	ft_swap_first_two(&*a);
	*total += 1;
	ft_printf("sa\n");
}