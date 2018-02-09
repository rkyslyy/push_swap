#include "../swaplib.h"

static void	ft_pall(t_stack **a, t_stack **b, t_pack *p)
{
	t_stack *ap;
	t_stack *bp;

	ap = *a;
	bp = *b;
	while (ap->value != p->mem)
	{
		if (ap->value <= p->pivot)
			ft_deal_with_b(b, a, p);
		else
		{
			if (bp != NULL && ft_scout(ap, p->mem, p->pivot) &&
				ft_pick_rotate(bp, ft_get_biggest(bp, ft_get_next(ap, p->mem, p->pivot))) == 1
				&& bp->value != ft_get_biggest(bp, ft_get_next(ap, p->mem, p->pivot)))
				ft_rotate_both(a, b, p);
			else
				ft_rotate_a(a, p);
		}
		ap = *a;
		bp = *b;
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
	ft_final(a, b, pack);
}