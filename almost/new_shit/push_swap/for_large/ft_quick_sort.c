/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 17:02:14 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/02/19 17:02:14 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

int		ft_get_big(t_stack *b, int val)
{
	t_stack *ptr;
	int		ret;

	if (val > ft_get_max(b))
		return (ft_get_min(b));
	ptr = b;
	ret = ft_get_max(b);
	while (ptr != NULL)
	{
		if (ptr->value < ret && ptr->value > val)
			ret = ptr->value;
		ptr = ptr->next;
	}
	return (ret);
}

static void	ft_pall(t_stack **a, t_stack **b, t_pack *p)
{
	t_stack *ap;
	t_stack *bp;
	int		(*f_b)(t_stack *b, int val);
	int		(*f_g)(t_stack *node, int mem, int pivot);

	ap = *a;
	bp = *b;
	f_b = &ft_get_big;
	f_g = &ft_get_next;
	while (ap->value != p->mem)
	{
		if (ap->value <= p->pivot)
			ft_deal_with_b(b, a, p);
		else
		{
			if (bp != NULL && ft_scout(ap, p->mem, p->pivot) &&
				ft_pick_rotate(bp, f_b(bp, f_g(ap, p->mem, p->pivot))) == 1
				&& bp->value != f_b(bp, f_g(ap, p->mem, p->pivot)))
				ft_rotate_both(a, b, p);
			else
				ft_rotate_a(a, p);
		}
		ap = *a;
		bp = *b;
	}
}

// static void	ft_shmatochok(t_stack **a, t_stack **b, t_pack *pack)
// {
// 	t_stack *aptr;
// 	t_stack *bptr;

// 	aptr = *a;
// 	bptr = *b;
// 	if (ft_pick_rotate(bptr, ft_get_max(bptr)) == 1)
// 		while (bptr->value != ft_get_max(bptr))
// 		{
// 			ft_rotate_b(b, pack);
// 			bptr = *b;
// 		}
// 	else
// 		while (bptr->value != ft_get_max(bptr))
// 		{
// 			ft_reverse_rotate_b(b, pack);
// 			bptr = *b;
// 		}
// }

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
		// ft_shmatochok(a, b, pack);
		aptr = *a;
		bptr = *b;
	}
	// ft_final(a, b, pack);
}
