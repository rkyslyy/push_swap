#include "../swaplib.h"

void	ft_reverse_rotate_both(t_stack **a, t_stack **b, int *total)
{
	ft_reverse_rotate(&a);
	ft_reverse_rotate(&b);
	ft_printf("rrr\n");
	*total += 1;
}
