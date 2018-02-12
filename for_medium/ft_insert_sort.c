#include "../swaplib.h"

static void	ft_get_to_unsorted(t_stack **a, int *mem, t_pack *pack)
{
	t_stack *aptr;

	aptr = *a;
	if (ft_find_unsorted(aptr, ft_get_min(aptr), ft_get_max(aptr), mem) == 1)
		while (aptr->value != *mem)
		{
			ft_rotate_a(a, pack);
			aptr = *a;
		}
	else
		while (aptr->value != *mem)
		{
			ft_reverse_rotate_a(a, pack);
			aptr = *a;
		}
}

static void	ft_if_max(t_stack **a, t_stack **b, t_pack *pack)
{
	t_stack *aptr;
	t_stack *bptr;

	aptr = *a;
	bptr = *b;
	if (aptr->next->next->value == ft_get_min(aptr) &&
		aptr->next->value > ft_get_last_value(aptr))
	{
		ft_swap_a(a, pack);
		aptr = *a;
	}
	else
	{
		ft_rotate_a(a, pack);
		aptr = *a;
		while (aptr->value != ft_get_min(aptr))
		{
			ft_push_from_a_to_b(a, b, pack);
			aptr = *a;
			bptr = *b;
		}
	}
}

static void	ft_for_no_max(t_stack **a, t_stack **b, t_pack *pack, int mem)
{
	t_stack *aptr;
	t_stack *bptr;

	aptr = *a;
	bptr = *b;
	if (aptr->value < aptr->next->next->value &&
		(aptr->next->value > ft_get_last_value(aptr) ||
			(aptr->next->value == ft_get_min(aptr) &&
				ft_get_last_value(aptr) == ft_get_max(aptr))))
	{
		ft_swap_a(a, pack);
		aptr = *a;
	}
	else
	{
		ft_rotate_a(a, pack);
		aptr = *a;
		while (aptr->value < mem)
		{
			ft_push_from_a_to_b(a, b, pack);
			aptr = *a;
			bptr = *b;
		}
	}
}

static void	ft_empty_b(t_stack **a, t_stack **b, t_pack *pack)
{
	t_stack *aptr;
	t_stack *bptr;

	aptr = *a;
	bptr = *b;
	while (bptr != NULL)
	{
		if (ft_pick_rotate(aptr, ft_get_biggest(aptr, bptr->value)) == 1)
			while (ft_get_last_value(aptr) !=
				ft_get_biggest(aptr, bptr->value))
			{
				ft_rotate_a(a, pack);
				aptr = *a;
			}
		else
			while (ft_get_last_value(aptr) !=
				ft_get_biggest(aptr, bptr->value))
			{
				ft_reverse_rotate_a(a, pack);
				aptr = *a;
			}
		ft_push_from_b_to_a(a, b, pack);
		aptr = *a;
		bptr = *b;
	}
}

void	ft_insert_swap(t_stack **a, t_stack **b, t_pack *pack)
{
	t_stack *aptr;
	t_stack	*bptr;
	int		mem;

	aptr = *a;
	bptr = *b;
	while (!ft_is_sorted(aptr))
	{
		ft_get_to_unsorted(a, &mem, pack);
		aptr = *a;
		if (aptr->value == ft_get_max(aptr))
			ft_if_max(a, b, pack);
		else
			ft_for_no_max(a, b, pack, mem);
		aptr = *a;
	}
	ft_empty_b(a, b, pack);
	ft_last_rotate(a, pack);
}