#include "../swaplib.h"

static void	ft_lil_to_a(t_stack **a, t_stack **b, t_stack *p, t_pack *pack)
{
	t_stack *bptr;

	bptr = *b;
	while (bptr->value >= p->next->value)
	{
		ft_push_from_b_to_a(a, b, pack);
		bptr = *b;
	}
	if (ft_pick_rotate(*b, pack->mem) == 1)
		while (ft_get_last_value(*b) != pack->mem)
			ft_rotate_b(b, pack);
	else
		while (ft_get_last_value(*b) != pack->mem)
			ft_reverse_rotate_b(b, pack);
}

static void	ft_p_or_r_b(t_stack **a, t_stack **b, t_pack *pack, t_stack *pivptr)
{
	t_stack *bptr;

	bptr = *b;
	while (bptr->value >= pivptr->next->value && bptr->value != pack->mem
		&& ft_is_left(*b, pivptr->next->value, pack->pivot, pack->mem))
	{
		if (bptr->value >= pack->pivot)
			ft_push_from_b_to_a(a, b, pack);
		else
			ft_rotate_b(b, pack);
		bptr = *b;
	}
	if (bptr->value >= pack->pivot)
	{
		pack->mem = bptr->next->value;
		ft_push_from_b_to_a(a, b, pack);
	}
}

void	ft_break_b(t_stack **a, t_stack **b, t_pack *pack, t_stack **pivots)
{
	t_stack *aptr;
	t_stack *bptr;
	t_stack *pivptr;
	
	aptr = *a;
	bptr = *b;
	pivptr = *pivots;
	pack->mem = ft_get_last_value(*b);
	if (ft_find_size(*b, pivptr->next->value) > 3)
	{
		pack->pivot = ft_new_pivot(*b, ft_find_next(*b, pivptr->next->value));
		ft_p_or_r_b(a, b, pack, pivptr);
		if (ft_pick_rotate(*b, pack->mem) == 1)
			while (ft_get_last_value(*b) != pack->mem)
				ft_rotate_b(b, pack);
		else
			while (ft_get_last_value(*b) != pack->mem)
				ft_reverse_rotate_b(b, pack);
		aptr = *a;
		bptr = *b;
		ft_add_next(ft_create_node(pack->pivot), pivots);
	}
	else
		ft_lil_to_a(a, b, pivptr, pack);
}