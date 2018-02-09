#include "../swaplib.h"

void	ft_rotate_both(t_stack **a, t_stack **b, int *total)
{
	ft_rotate(&*a);
	ft_rotate(&*b);
	printf("rr\n");
	*total += 1;
}
