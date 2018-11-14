/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_a_to_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 17:38:56 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/02/19 17:38:57 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

void	ft_push_from_a_to_b(t_stack **a, t_stack **b, t_pack *pack)
{
	ft_push_from_to(&*a, &*b);
	if (pack->print == 1)
		ft_printf("pb\n");
	pack->total += 1;
}
