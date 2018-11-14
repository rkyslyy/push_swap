/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vis_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 13:26:51 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/02/20 13:26:51 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

void	ft_vis_stacks(t_pack pack, char *line, t_stack *a, t_stack *b)
{
	if (pack.print == 0 && pack.visual == 1 && pack.add != 0)
	{
		ft_printf("[%s]\n", line);
		if (ft_strlen(line) == 2)
			ft_printf(" ↓↓");
		else
			ft_printf(" ↓↓↓");
		ft_print_stacks(a, b, line, pack);
	}
}
