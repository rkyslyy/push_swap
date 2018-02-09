#include "../swaplib.h"

static void	ft_pall(t_stack **a, t_stack **b, t_pack *pack)
{
	t_stack *aptr;
	t_stack *bptr;

	aptr = *a;
	bptr = *b;
	while (aptr->value != pack->mem)
	{
		if (aptr->value <= pack->pivot)
			ft_deal_with_b(b, a, pack);
		else
		{
			if (bptr != NULL && ft_scout(aptr, pack->mem, pack->pivot) &&
				ft_pick_rotate(bptr, ft_get_biggest(bptr, ft_get_next(aptr, pack->mem, pack->pivot))) == 1
				&& bptr->value != ft_get_biggest(bptr, ft_get_next(aptr, pack->mem, pack->pivot)))
				ft_rotate_both(a, b, pack);
			else
				ft_rotate_a(a, pack);
		}
		aptr = *a;
		bptr = *b;
	}
}

static void	ft_shmatok(t_stack **a, t_stack **b, t_pack *pack)
{
	t_stack *aptr;
	t_stack *bptr;

	aptr = *a;
	bptr = *b;
	if (ft_pick_rotate(bptr, ft_get_max(bptr)) == 1)
		while (bptr->value != ft_get_max(bptr))
		{
			ft_rotate_b(b, pack);
			bptr = *b;
		}
	else
		while (bptr->value != ft_get_max(bptr))
		{
			ft_reverse_rotate_b(b, pack);
			bptr = *b;
		}
}

void		ft_quick_sort(t_stack **a, t_stack **b, t_pack *pack)
{
	t_stack *aptr;
	t_stack *bptr;

	aptr = *a;
	bptr = *b;
	while (aptr != NULL && !ft_is_sorted(aptr))
	{
		ft_set_pivot(aptr, pack);
		pack->mem = aptr->value;
		ft_rotate_a(a, pack);
		aptr = *a;
		ft_pall(a, b, pack);
		aptr = *a;
		bptr = *b;
		if (aptr->value <= pack->pivot)
			ft_deal_with_b(b, a, pack);
		ft_shmatok(a, b, pack);
		aptr = *a;
		bptr = *b;
	}
}