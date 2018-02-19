/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nums_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 17:36:29 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/02/19 17:36:30 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../swaplib.h"

void	ft_nums_a(t_stack *ptr, t_stack *a, t_pack pack, char const *line)
{
	while (ptr != NULL)
	{
		if (pack.highlight == 1 && ((ft_strcmp(line, "sa") == 0 &&
			(ptr == a || ptr == a->next)) ||
			(ft_strcmp(line, "pa") == 0 && ptr == a)))
			ft_printf("[");
		ft_printf("%d", ptr->value);
		if (pack.highlight == 1 && ((ft_strcmp(line, "sa") == 0 &&
			(ptr == a || ptr == a->next)) ||
			(ft_strcmp(line, "pa") == 0 && ptr == a)))
			ft_printf("]");
		if (pack.highlight == 1 && ft_strcmp(line, "sa") == 0 &&
			ptr == a)
			ft_printf(" ⇔ ");
		else
			ft_printf(" ⁀ ");
		ptr = ptr->next;
	}
}
