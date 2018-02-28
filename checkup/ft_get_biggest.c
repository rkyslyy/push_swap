/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_biggest.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 17:01:02 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/02/19 17:01:03 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

int	ft_get_biggest(t_stack *b, int val)
{
	t_stack *ptr;
	int		ret;

	if (val > ft_get_max(b))
		return (ft_get_min(b));
	ptr = b;
	ret = ft_get_max(b);
	while (ptr != NULL)
	{
		if (ptr->value < ret && ptr->value > val)
			ret = ptr->value;
		ptr = ptr->next;
	}
	return (ret);
}
