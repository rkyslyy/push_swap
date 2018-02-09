#include "../swaplib.h"

void	ft_rotate_a(t_stack **a, t_pack *pack)
{
	ft_rotate(&*a);
	pack->total += 1;
	ft_printf("ra\n");
}
