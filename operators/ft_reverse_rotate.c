/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 17:39:41 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/02/19 17:39:47 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

void	ft_reverse_rotate(t_stack **anchor)
{
	t_stack	*prelast;
	t_stack	*ptr;
	t_stack	*last;

	ptr = *anchor;
	if (ptr != NULL && ptr->next != NULL)
	{
		prelast = ptr;
		while (prelast->next->next != NULL)
			prelast = prelast->next;
		last = ptr;
		while (last->next != NULL)
			last = last->next;
		last->next = *anchor;
		*anchor = last;
		prelast->next = NULL;
	}
}
