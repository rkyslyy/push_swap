/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_from_to.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 17:43:00 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/02/19 17:43:09 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

void	ft_push_from_to(t_stack **from, t_stack **to)
{
	t_stack *tmp;
	t_stack *ptr;

	if (*from != NULL)
	{
		tmp = *from;
		ptr = *from;
		*from = ptr->next;
		tmp->next = *to;
		*to = tmp;
	}
}
