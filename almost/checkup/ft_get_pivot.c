/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pivot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 16:59:35 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/02/19 16:59:36 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

int	ft_get_pivot(t_stack *a, int val)
{
	int		mem;
	int		ret;
	int		count;
	t_stack	*ptr;

	count = 0;
	mem = ft_get_max(a);
	ret = ft_get_min(a);
	while (count < val)
	{
		ret = ft_get_min(a);
		ptr = a;
		while (ptr != NULL)
		{
			if (ptr->value > ret && ptr->value < mem)
				ret = ptr->value;
			ptr = ptr->next;
		}
		mem = ret;
		count += 1;
	}
	return (ret);
}
