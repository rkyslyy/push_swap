/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_got_less.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 16:41:41 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/02/07 16:41:41 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

int	ft_got_less(t_stack *a, int median)
{
	t_stack *ptr;

	ptr = a;
	while (ptr != NULL)
	{
		if (ptr->value < median)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}
