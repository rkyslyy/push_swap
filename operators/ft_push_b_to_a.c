#include "../swaplib.h"

void	ft_push_from_b_to_a(t_stack **a, t_stack **b, t_pack *pack)
{
	ft_push_from_to(&*b, &*a);
	if (pack->print == 1)
		ft_printf("pa\n");
	pack->total += 1;
}
