/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_b_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 17:39:01 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/02/19 17:39:02 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

void	ft_push_from_b_to_a(t_stack **a, t_stack **b, t_pack *pack)
{
	ft_push_from_to(&*b, &*a);
	if (pack->print == 1)
		ft_printf("pa\n");
	pack->total += 1;
}
