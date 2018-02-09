#include "../swaplib.h"

void	ft_rotate_a(t_stack **a, int *total)
{
	ft_rotate(&*a);
	*total += 1;
	ft_printf("ra\n");
}
