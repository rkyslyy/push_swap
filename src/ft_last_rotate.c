/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 17:33:36 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/02/19 17:33:37 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

void	ft_last_rotate(t_stack **a, t_pack *pack)
{
	t_stack *aptr;

	aptr = *a;
	if (ft_pick_rotate(aptr, ft_get_min(aptr)) == 1)
		while (aptr->value != ft_get_min(aptr))
		{
			ft_rotate_a(a, pack);
			aptr = *a;
		}
	else
		while (aptr->value != ft_get_min(aptr))
		{
			ft_reverse_rotate_a(a, pack);
			aptr = *a;
		}
}
