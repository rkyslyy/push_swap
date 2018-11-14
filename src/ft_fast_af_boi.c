/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fast_af_boi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 14:29:36 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/02/21 14:29:36 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

static void	ft_two_or_three(t_stack **a, t_stack **b, t_pack *pack, t_stack *p)
{
	t_stack *aptr;

	aptr = *a;
	if (ft_find_size_a(*a, p->value) == 2)
	{
		if (aptr->value > aptr->next->value)
			ft_swap_a(a, pack);
	}
	else if (ft_find_size_a(*a, p->value) == 3)
		ft_swap_three(a, b, pack);
}

void		ft_fast_af_boi(t_stack **a, t_stack **b, t_pack *pack)
{
	t_stack	*aptr;
	t_stack	*bptr;
	t_stack	*pivots;

	pivots = NULL;
	ft_add_node(ft_create_node(ft_get_min(*a)), &pivots);
	ft_first_break(a, b, pack, &pivots);
	while (ft_get_size(*b) > 150)
	{
		ft_break_b(a, b, pack, &pivots);
		while (ft_find_size_a(*a, pivots->value) > 3)
			ft_break_a(a, b, pack, &pivots);
		ft_two_or_three(a, b, pack, pivots);
		aptr = *a;
		bptr = *b;
		ft_del_node(&pivots);
	}
	ft_rev_quick_sort(b, a, pack);
	while (*b)
		ft_deal_with_a(a, b, pack);
	ft_last_rotate(a, pack);
	ft_free_lists(pivots, 0);
}
