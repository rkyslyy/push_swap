/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pick_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 16:58:50 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/02/19 16:59:04 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

int	ft_pick_rotate(t_stack *anchor, int to_find)
{
	t_stack	*ptr;
	int		size;
	int		gotcha;

	gotcha = 1;
	size = ft_get_size(anchor);
	ptr = anchor;
	while (ptr != NULL)
	{
		if (ptr->value == to_find)
			break ;
		gotcha += 1;
		ptr = ptr->next;
	}
	if (size - gotcha < size / 2)
		return (2);
	else
		return (1);
}
