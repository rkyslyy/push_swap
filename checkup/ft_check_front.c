/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_front.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:38:26 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/02/07 15:38:27 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

int	ft_check_front(t_stack *node, int median)
{
	t_stack *ptr;

	ptr = node;
	ptr = ptr->next;
	while (ptr->value != median)
	{
		if (ptr->value < node->value)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}
