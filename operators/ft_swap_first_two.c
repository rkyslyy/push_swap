/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_first_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 17:37:36 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/02/19 17:37:42 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

void	ft_swap_first_two(t_stack **anchor)
{
	t_stack *ptr;
	t_stack *tmp;

	ptr = *anchor;
	if (ptr != NULL && ptr->next != NULL)
	{
		tmp = *anchor;
		*anchor = ptr->next;
		tmp->next = tmp->next->next;
		ptr = *anchor;
		ptr->next = tmp;
	}
}
