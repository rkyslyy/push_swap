#include "../swaplib.h"
#include <stdio.h>

void ft_swap_rotate(t_stack **a, t_pack *pack)
{
	t_stack *ptr;

	ptr = *a;
	if (ptr->value > ptr->next->value)
		ft_swap_a(a, pack);
	if (pack->print == 0 && pack->visual == 1)
		ft_printf_stacks(*a, NULL);
	if (ft_pick_rotate(a, ft_get_min(a)) == 1)
		while (a->value != ft_get_min(a))
			ft_rotate_a(a, pack);
	else
		while (a->value != ft_get_min(a))
			ft_reverse_rotate(a, pack);
}