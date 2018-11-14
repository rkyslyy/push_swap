/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 17:38:23 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/02/19 17:38:24 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

void	ft_rotate_a(t_stack **a, t_pack *pack)
{
	ft_rotate(&*a);
	pack->total += 1;
	if (pack->print == 1)
		ft_printf("ra\n");
}