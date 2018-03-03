/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 17:38:26 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/02/19 17:38:26 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

void	ft_rotate_b(t_stack **b, t_pack *pack)
{
	ft_rotate(&*b);
	pack->total += 1;
	if (pack->print == 1)
		ft_printf("rb\n");
}
