#include "../swaplib.h"

void	ft_reverse_rotate_a(t_stack **a, t_pack *pack)
{
	ft_reverse_rotate(&*a);
	ft_printf("rra\n");
	pack->total += 1;
}
