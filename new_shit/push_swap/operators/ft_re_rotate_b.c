/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_re_rotate_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 17:38:40 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/02/19 17:38:40 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

void	ft_reverse_rotate_b(t_stack **b, t_pack *pack)
{
	ft_reverse_rotate(&*b);
	if (pack->print == 1)
		ft_printf("rrb\n");
	pack->total += 1;
}
