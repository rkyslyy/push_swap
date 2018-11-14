/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_with_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:38:32 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/03/05 16:38:33 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

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

void		ft_deal_with_a(t_stack **a, t_stack **b, t_pack *pack)
{
	t_stack *bptr;
	t_stack *aptr;

	bptr = *b;
	aptr = *a;
	if (aptr != NULL &&
		ft_pick_rotate(aptr, ft_get_big(aptr, bptr->value)) == 1)
		while (aptr->value != ft_get_big(aptr, bptr->value))
		{
			ft_rotate_a(a, pack);
			aptr = *a;
		}
	else
		while (aptr != NULL &&
			aptr->value != ft_get_big(aptr, bptr->value))
		{
			ft_reverse_rotate_a(a, pack);
			aptr = *a;
		}
	ft_push_from_b_to_a(a, b, pack);
}
