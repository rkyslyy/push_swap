#include "../swaplib.h"

void	ft_swap_a(t_stack **a, t_pack *pack)
{
	ft_swap_first_two(&*a);
	pack->total += 1;
	if (pack->print == 1)
		ft_printf("sa\n");
}