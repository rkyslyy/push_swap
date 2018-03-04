/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_median.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 14:24:18 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/02/07 14:41:26 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

static t_stack	*ft_assign(t_stack *anchor, int *count, int *size)
{
	*count = 0;
	*size = ft_get_size(anchor);
	return (anchor);
}

int				ft_get_median(t_stack *anchor)
{
	t_stack *ptr;
	int		size;
	int		count;
	int		ret;
	int		mem;

	ptr = ft_assign(anchor, &count, &size);
	ret = ft_get_min(anchor);
	mem = ret;
	while (count < size / 2)
	{
		ptr = anchor;
		while (ptr->value <= ret)
			ptr = ptr->next;
		ret = ptr->value;
		while (ptr != NULL)
		{
			if (ptr->value < ret && ptr->value > mem)
				ret = ptr->value;
			ptr = ptr->next;
		}
		mem = ret;
		count += 1;
	}
	return (ret);
}
