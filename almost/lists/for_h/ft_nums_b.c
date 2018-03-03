/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nums_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 17:36:17 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/02/19 17:36:18 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../swaplib.h"

void	ft_nums_b(t_stack *ptr, t_stack *b, t_pack pack, char const *line)
{
	while (ptr != NULL)
	{
		if (pack.highlight == 1 && ((ft_strcmp(line, "sb") == 0 &&
			(ptr == b || ptr == b->next)) ||
			(ft_strcmp(line, "pb") == 0 && ptr == b)))
			ft_printf("[");
		ft_printf("%d", ptr->value);
		if (pack.highlight == 1 && ((ft_strcmp(line, "sb") == 0 &&
			(ptr == b || ptr == b->next)) ||
			(ft_strcmp(line, "pb") == 0 && ptr == b)))
			ft_printf("]");
		if (pack.highlight == 1 && ft_strcmp(line, "sb") == 0 &&
			ptr == b)
			ft_printf(" ⇔ ");
		else
			if (ptr->next != NULL)
				ft_printf(" ‿ ");
		ptr = ptr->next;
	}
}
