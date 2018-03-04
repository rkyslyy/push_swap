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

void	ft_fast_af_boi(t_stack **a, t_stack **b, t_pack *pack)
{
	t_stack	*aptr;
	t_stack	*bptr;
	t_stack	*pivots;

	pivots = NULL;
	ft_add_node(ft_create_node(ft_get_min(*a)), &pivots);
	ft_first_break(a, b, pack, &pivots);
	aptr = *a;
	bptr = *b;
	while (ft_get_size(*b) > 150)
	{
		ft_break_b(a, b, pack, &pivots);
		aptr = *a;
		bptr = *b;
		while (ft_find_size_a(*a, pivots->value) > 3)
		{
			pack->pivot = ft_new_pivot(*a, ft_find_next_a(*a, pivots->value));
			pack->mem = ft_get_last_value(*a);
			while (aptr->value <= pivots->value && ft_is_left_a(*a, pivots->value, pack->pivot))
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
			if (ft_pick_rotate(*a, pack->mem) == 1)
				while (ft_get_last_value(*a) != pack->mem)
					ft_rotate_a(a, pack);
			else
				while (ft_get_last_value(*a) != pack->mem)
					ft_reverse_rotate_a(a, pack);
			aptr = *a;
			bptr = *b;
			ft_add_next(ft_create_node(pack->pivot), &pivots);
		}
		if (ft_find_size_a(*a, pivots->value) == 2)
		{
			if (aptr->value > aptr->next->value)
			ft_swap_a(a, pack);
			aptr = *a;
		}
		else if (ft_find_size_a(*a, pivots->value) == 3)
		{
			
			ft_swap_three(a, b, pack);
			aptr = *a;
			bptr = *b;
		}
		ft_del_node(&pivots);
	}
	ft_rev_quick_sort(b, a, pack);
	while (*b)
		ft_deal_with_a(a, b, pack);
	aptr = *a;
	if (ft_pick_rotate(*a, ft_get_min(*a)) == 1)
		while (aptr->value != ft_get_min(*a))
		{
			ft_rotate_a(a, pack);
			aptr = *a;
		}
	else
		while (aptr->value != ft_get_min(*a))
		{
			ft_reverse_rotate_a(a, pack);
			aptr = *a;
		}
}