/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 14:51:14 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/02/02 14:51:15 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

int	ft_range(t_stack *a, int first_b)
{
	t_stack *ptr;
	int before;
	int after;
	int	max;
	int	min;

	ptr = a;
	before = ptr->value;
	after = ptr->value;
	max = ft_get_max(a);
	min = ft_get_min(a);
	//printf("min = %d max = %d\n", min, max);
	while (ptr != NULL)
	{
		// if (first_b < ft_get_min(a) && ptr->value == max)
		// {
		// 	before = ptr->value;
		// 	break ;
		// }
		if (ptr->value < first_b && ptr->value > before)
			before = ptr->value;
		ptr = ptr->next;
	}
	ptr = a;
	while (ptr != NULL)
	{
		if (ptr->value > first_b && ptr->value < after)
				after = ptr->value;
		ptr = ptr->next;
	}
	printf("before = %d after = %d\n", before, after);
	return (0);
}
