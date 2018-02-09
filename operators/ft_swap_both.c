#include "../swaplib.h"

void	ft_swap_both(t_stack **a, t_stack **b, t_pack *pack)
{
	ft_swap_first_two(&*a);
	ft_swap_first_two(&*b);
	pack->total += 1;
	ft_printf("ss\n");
}
