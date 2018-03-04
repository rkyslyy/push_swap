#include "../swaplib.h"

static void	ft_rotate_back(t_stack **a, t_pack *pack)
{
	if (ft_pick_rotate(*a, pack->mem) == 1)
		while (ft_get_last_value(*a) != pack->mem)
			ft_rotate_a(a, pack);
	else
		while (ft_get_last_value(*a) != pack->mem)
			ft_reverse_rotate_a(a, pack);
}

void	ft_break_a(t_stack **a, t_stack **b, t_pack *pack, t_stack **pivots)
{
	t_stack *aptr;
	t_stack *bptr;
	t_stack *pivptr;

	aptr = *a;
	bptr = *b;
	pivptr = *pivots;
	pack->pivot = ft_new_pivot(*a, ft_find_next_a(*a, pivptr->value));
	pack->mem = ft_get_last_value(*a);
	while (aptr->value <= pivptr->value && ft_is_left_a(*a, pivptr->value, pack->pivot))
	{
		if (aptr->value <= pack->pivot)
			ft_push_from_a_to_b(a, b, pack);
		else
			ft_rotate_a(a, pack);
		aptr = *a;
		bptr = *b;
	}
	if (aptr->value <= pack->pivot)
		ft_push_from_a_to_b(a, b, pack);
	aptr = *a;
	bptr = *b;
	ft_rotate_back(a, pack);
	ft_add_next(ft_create_node(pack->pivot), pivots);
}