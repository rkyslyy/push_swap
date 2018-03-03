/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 17:00:51 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/02/19 17:00:51 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

int	ft_get_max(t_stack *anchor)
{
	t_stack *ptr;
	int		max;

	ptr = anchor;
	max = ptr->value;
	while (ptr != NULL)
	{
		if (ptr->value > max)
			max = ptr->value;
		ptr = ptr->next;
	}
	return (max);
}
