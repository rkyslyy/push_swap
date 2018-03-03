/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_with_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 17:02:47 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/02/19 17:02:48 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

static int		ft_get_big(t_stack *b, int val)
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

void	ft_deal_with_b(t_stack **b, t_stack **a, t_pack *pack)
{
	t_stack *bptr;
	t_stack *aptr;

	bptr = *b;
	aptr = *a;
	if (bptr != NULL &&
		ft_pick_rotate(bptr, ft_get_big(bptr, aptr->value)) == 1)
		while (ft_get_last_value(bptr) != ft_get_big(bptr, aptr->value))
		{
			ft_rotate_b(b, pack);
			bptr = *b;
		}
	else
		while (bptr != NULL &&
			ft_get_last_value(bptr) != ft_get_big(bptr, aptr->value))
		{
			ft_reverse_rotate_b(b, pack);
			bptr = *b;
		}
	ft_push_from_a_to_b(a, b, pack);
}
