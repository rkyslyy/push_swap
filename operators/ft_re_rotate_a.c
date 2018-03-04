/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_re_rotate_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 17:38:42 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/02/19 17:38:42 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

void	ft_reverse_rotate_a(t_stack **a, t_pack *pack)
{
	ft_reverse_rotate(&*a);
	if (pack->print == 1)
		ft_printf("rra\n");
	pack->total += 1;
}
