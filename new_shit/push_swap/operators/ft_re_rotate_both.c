/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_re_rotate_both.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 17:38:35 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/02/19 17:38:36 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

void	ft_reverse_rotate_both(t_stack **a, t_stack **b, t_pack *pack)
{
	ft_reverse_rotate(&*a);
	ft_reverse_rotate(&*b);
	if (pack->print == 1)
		ft_printf("rrr\n");
	pack->total += 1;
}
