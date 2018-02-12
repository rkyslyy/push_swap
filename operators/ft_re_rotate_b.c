#include "../swaplib.h"

void	ft_reverse_rotate_b(t_stack **b, t_pack *pack)
{
	ft_reverse_rotate(&*b);
	if (pack->print == 1)
		ft_printf("rrb\n");
	pack->total += 1;
}
