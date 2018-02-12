#include "../swaplib.h"

void	ft_rotate_b(t_stack **b, t_pack *pack)
{
	ft_rotate(&*b);
	pack->total += 1;
	if (pack->print == 1)
		ft_printf("rb\n");
}
