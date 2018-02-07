/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:22:14 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/02/07 15:22:14 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

int		ft_get_size(t_stack *a)
{
	t_stack *ptr;
	int	size;

	ptr = a;
	size = 0;
	while (ptr != NULL)
	{
		size += 1;
		ptr = ptr->next;
	}
	return (size);
}
