/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 16:57:06 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/02/19 16:57:27 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

int	ft_is_sorted(t_stack *anchor)
{
	t_stack *ptr;
	int		min;

	ptr = anchor;
	min = ptr->value;
	while (ptr != NULL)
	{
		if (ptr->value < min)
			min = ptr->value;
		ptr = ptr->next;
	}
	ptr = anchor;
	while (ptr != NULL)
	{
		if (ptr->next != NULL && ptr->value > ptr->next->value
			&& ptr->next->value != min)
			return (0);
		if (ptr->next == NULL &&
			ptr->value > anchor->value && anchor->value != min)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}
