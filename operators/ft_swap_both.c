/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_both.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 17:37:59 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/02/19 17:37:59 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

void	ft_swap_both(t_stack **a, t_stack **b, t_pack *pack)
{
	ft_swap_first_two(&*a);
	ft_swap_first_two(&*b);
	pack->total += 1;
	if (pack->print == 1)
		ft_printf("ss\n");
}
