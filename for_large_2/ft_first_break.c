#include "../swaplib.h"

static void	ft_loop_single(t_stack **a, t_stack **b, t_stack *aptr, t_pack *pack)
{
	if (aptr->value <= pack->pivot)
		ft_push_from_a_to_b(a, b, pack);
	else
		ft_rotate_a(a, pack);
}

static void	ft_p_or_r_a(t_stack **a, t_stack **b, t_pack *pack)
{
	t_stack *aptr;
	t_stack *bptr;

	aptr = *a;
	bptr = *b;
	while (aptr->value != pack->mem)
	{
		ft_loop_single(a, b, aptr, pack);
		aptr = *a;
		bptr = *b;
	}
	ft_loop_single(a, b, aptr, pack);
}

void ft_first_break(t_stack **a, t_stack **b, t_pack *pack, t_stack **pivots)
{
	t_stack *aptr;
	t_stack	*bptr;

	aptr = *a;
	bptr = *b;
	while (!ft_is_sorted(*a))
	{
		pack->pivot = ft_get_pivot(*a, ft_get_size(*a) / 2);
		pack->mem = ft_get_last_value(*a);
		ft_p_or_r_a(a, b, pack);
		aptr = *a;
		bptr = *b;
		ft_add_node(ft_create_node(ft_get_min(*a)), pivots);
	}
	while (aptr->value != ft_get_min(*a))
	{
		ft_rotate_a(a, pack);
		aptr = *a;
	}
}