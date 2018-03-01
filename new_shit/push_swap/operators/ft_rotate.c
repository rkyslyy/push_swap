/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 17:39:23 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/02/19 17:39:26 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

void	ft_rotate(t_stack **anchor)
{
	t_stack *ptr;
	t_stack *tmp;

	ptr = *anchor;
	if (ptr != NULL && ptr->next != NULL)
	{
		tmp = *anchor;
		*anchor = ptr->next;
		ptr = *anchor;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = tmp;
		tmp->next = NULL;
	}
}
