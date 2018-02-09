#include "../swaplib.h"

void	ft_push_till_big(t_stack *a, t_stack *b, int mem)
{
	ft_push_from_to(&a, &b);
	ft_printf("pb\n");
	while (a->value < mem)
	{
		ft_push_from_to(&a, &b);
		ft_printf("pb\n");
	}
}