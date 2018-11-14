/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:29:29 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/03/05 16:29:30 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

static void	ft_for_321(t_stack **a, t_stack **b, t_pack *pack)
{
	ft_push_from_a_to_b(a, b, pack);
	ft_swap_a(a, pack);
	ft_rotate_a(a, pack);
	ft_rotate_a(a, pack);
	ft_push_from_b_to_a(a, b, pack);
	ft_reverse_rotate_a(a, pack);
	ft_reverse_rotate_a(a, pack);
}

static void	ft_for_213(t_stack **a, t_stack **b, t_pack *pack)
{
	ft_push_from_a_to_b(a, b, pack);
	ft_rotate_a(a, pack);
	ft_rotate_a(a, pack);
	ft_push_from_b_to_a(a, b, pack);
	ft_reverse_rotate_a(a, pack);
	ft_reverse_rotate_a(a, pack);
}

static void	ft_for_231_132(t_stack **a, t_stack **b, t_pack *pack, int min)
{
	t_stack *ptr;

	ptr = *a;
	if (ptr->value == min)
	{
		ft_rotate_a(a, pack);
		ft_swap_a(a, pack);
		ft_reverse_rotate_a(a, pack);
	}
	else
	{
		ft_push_from_a_to_b(a, b, pack);
		ft_swap_a(a, pack);
		ft_rotate_a(a, pack);
		ft_push_from_b_to_a(a, b, pack);
		ft_reverse_rotate_a(a, pack);
	}
}

static void	ft_for_312_213(t_stack **a, t_stack **b, t_pack *pack, int max)
{
	t_stack *ptr;

	ptr = *a;
	if (ptr->value != max)
		ft_swap_a(a, pack);
	else
	{
		ft_push_from_a_to_b(a, b, pack);
		ft_rotate_a(a, pack);
		ft_rotate_a(a, pack);
		ft_push_from_b_to_a(a, b, pack);
		ft_reverse_rotate_a(a, pack);
		ft_reverse_rotate_a(a, pack);
	}
}

void		ft_swap_three(t_stack **a, t_stack **b, t_pack *pack)
{
	t_stack *ptr;
	int		min;
	int		max;

	ptr = *a;
	min = ft_min(*a);
	max = ft_max(*a);
	if (ptr->value > ptr->next->value ||
		ptr->next->value > ptr->next->next->value)
	{
		if (ptr->value > ptr->next->value && ptr->next->value <
			ptr->next->next->value)
			ft_for_312_213(a, b, pack, max);
		else if (ptr->value < ptr->next->value &&
			ptr->next->value > ptr->next->next->value)
			ft_for_231_132(a, b, pack, min);
		else if (ptr->value > ptr->next->value &&
			ptr->next->value < ptr->next->next->value)
			ft_for_213(a, b, pack);
		else if (ptr->value > ptr->next->value &&
			ptr->next->value > ptr->next->next->value)
			ft_for_321(a, b, pack);
	}
}
