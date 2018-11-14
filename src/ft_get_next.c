/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 17:00:19 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/02/19 17:00:34 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

int	ft_get_next(t_stack *node, int mem, int pivot)
{
	t_stack *ptr;

	ptr = node;
	while (ptr->value != mem)
	{
		if (ptr->value < pivot)
			break ;
		ptr = ptr->next;
	}
	return (ptr->value);
}
