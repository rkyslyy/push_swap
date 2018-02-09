#include "../swaplib.h"

void	ft_rotate_both(t_stack **a, t_stack **b, t_pack *pack)
{
	ft_rotate(&*a);
	ft_rotate(&*b);
	ft_printf("rr\n");
	pack->total += 1;
}
