/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_break.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:34:20 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/03/05 16:34:21 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

static void	ft_loop_single(t_stack **a, t_stack **b, t_stack *aptr, t_pack *p)
{
	if (aptr->value <= p->pivot)
		ft_push_from_a_to_b(a, b, p);
	else
		ft_rotate_a(a, p);
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

void		ft_first_break(t_stack **a, t_stack **b, t_pack *pack, t_stack **p)
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
		ft_add_node(ft_create_node(ft_get_min(*a)), p);
	}
	while (aptr->value != ft_get_min(*a))
	{
		ft_rotate_a(a, pack);
		aptr = *a;
	}
}
