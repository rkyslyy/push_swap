#include "../swaplib.h"

void	ft_push_from_a_to_b(t_stack **a, t_stack **b, int *total)
{
	ft_push_from_to(&a, &b);
	ft_printf("pb\n");
	*total += 1;
}
