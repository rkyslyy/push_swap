/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scout.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 16:59:23 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/02/19 16:59:24 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

int	ft_scout(t_stack *node, int mem, int pivot)
{
	t_stack *ptr;

	ptr = node;
	while (ptr != NULL && ptr->value != mem)
	{
		if (ptr->value < pivot)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}
