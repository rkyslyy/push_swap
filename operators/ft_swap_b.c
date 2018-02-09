#include "../swaplib.h"

void	ft_swap_b(t_stack **b, t_pack *pack)
{
	ft_swap_first_two(&*b);
	pack->total += 1;
	ft_printf("sb\n");
}
