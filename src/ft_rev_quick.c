/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_quick_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 17:02:14 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/02/19 17:02:14 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

static int	ft_get_rev_pivot(t_stack *a, int val)
{
	int		mem;
	int		ret;
	int		count;
	t_stack	*ptr;

	count = 0;
	mem = ft_get_max(a);
	ret = ft_get_min(a);
	while (count < val)
	{
		ret = ft_get_min(a);
		ptr = a;
		while (ptr != NULL)
		{
			if (ptr->value > ret && ptr->value < mem)
				ret = ptr->value;
			ptr = ptr->next;
		}
		mem = ret;
		count += 1;
	}
	return (ret);
}

static void	ft_set_rev_pivot(t_stack *a, t_pack *pack)
{
	if (ft_get_size(a) <= 20)
		pack->pivot = ft_get_rev_pivot(a, ft_get_size(a) / 2);
	else if (ft_get_size(a) <= 50)
		pack->pivot = ft_get_rev_pivot(a, ft_get_size(a) / 2.5);
	else if (ft_get_size(a) <= 100)
		pack->pivot = ft_get_rev_pivot(a, ft_get_size(a) / 3.5);
	else if (ft_get_size(a) <= 250)
		pack->pivot = ft_get_rev_pivot(a, ft_get_size(a) / 4);
	else if (ft_get_size(a) <= 300)
		pack->pivot = ft_get_rev_pivot(a, ft_get_size(a) / 5.5);
	else if (ft_get_size(a) <= 350)
		pack->pivot = ft_get_rev_pivot(a, ft_get_size(a) / 6);
	else if (ft_get_size(a) <= 400)
		pack->pivot = ft_get_rev_pivot(a, ft_get_size(a) / 6.5);
	else if (ft_get_size(a) <= 450)
		pack->pivot = ft_get_rev_pivot(a, ft_get_size(a) / 7);
	else if (ft_get_size(a) <= 500)
		pack->pivot = ft_get_rev_pivot(a, ft_get_size(a) / 7.5);
	else
		pack->pivot = ft_get_rev_pivot(a, ft_get_size(a) / 9);
}

static int	ft_get_big(t_stack *b, int val)
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
		if (ap->value >= p->pivot)
			ft_rev_deal_with_b(b, a, p);
		else
		{
			if (bp != NULL && ft_scout(ap, p->mem, p->pivot) &&
				ft_pick_rotate(bp, f_b(bp, f_g(ap, p->mem, p->pivot))) == 1
				&& bp->value != f_b(bp, f_g(ap, p->mem, p->pivot)))
				ft_rotate_both(a, b, p);
			else
				ft_rotate_b(a, p);
		}
		ap = *a;
		bp = *b;
	}
}

void		ft_rev_quick_sort(t_stack **a, t_stack **b, t_pack *pack)
{
	t_stack *aptr;
	t_stack *bptr;

	aptr = *a;
	bptr = *b;
	while (aptr != NULL && !ft_is_sorted(aptr))
	{
		ft_set_rev_pivot(aptr, pack);
		pack->mem = aptr->value;
		ft_rotate_b(a, pack);
		aptr = *a;
		ft_pall(a, b, pack);
		aptr = *a;
		bptr = *b;
		if (aptr->value >= pack->pivot)
			ft_rev_deal_with_b(b, a, pack);
		aptr = *a;
		bptr = *b;
	}
}
