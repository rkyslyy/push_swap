#include "../swaplib.h"

void	ft_push_from_b_to_a(t_stack **a, t_stack **b, int *total)
{
	ft_push_from_to(&b, &a);
	ft_printf("pa\n");
	*total += 1;
}
