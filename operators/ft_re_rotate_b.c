#include "../swaplib.h"

void	ft_reverse_rotate_b(t_stack **b, t_pack *pack)
{
	ft_reverse_rotate(&*b);
	ft_printf("rrb\n");
	pack->total += 1;
}
