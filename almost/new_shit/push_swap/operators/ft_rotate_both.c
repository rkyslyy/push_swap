/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_both.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 17:38:30 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/02/19 17:38:31 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

void	ft_rotate_both(t_stack **a, t_stack **b, t_pack *pack)
{
	ft_rotate(&*a);
	ft_rotate(&*b);
	if (pack->print == 1)
		ft_printf("rr\n");
	pack->total += 1;
}
