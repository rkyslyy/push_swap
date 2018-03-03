/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_swap_good.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 16:58:18 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/02/19 16:58:20 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

int	ft_is_swap_good(t_stack *anchor)
{
	int		big;
	int		little;
	int		last;
	t_stack	*ptr;

	big = anchor->value;
	little = anchor->next->value;
	if (big > little && big < anchor->next->next->value)
		return (1);
	ptr = anchor;
	while (ptr->next != NULL)
		ptr = ptr->next;
	last = ptr->value;
	big = anchor->value;
	little = anchor->next->value;
	if ((big == ft_get_max(anchor) &&
		(anchor->next->next->value == ft_get_min(anchor))) ||
		(big != ft_get_max(anchor) && (big < anchor->next->next->value)))
		if (little > last || (little == ft_get_min(anchor)
			&& last == ft_get_max(anchor)))
			return (1);
	return (0);
}
