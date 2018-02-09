#include "../swaplib.h"

void	ft_rotate_b(t_stack **b, int *total)
{
	ft_rotate(&*b);
	*total += 1;
	ft_printf("rb\n");
}
