/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 17:37:09 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/02/19 17:37:17 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

void	ft_add_next(t_stack *new, t_stack **anchor)
{
	t_stack *ptr;

	ptr = *anchor;
	new->next = ptr->next;
	ptr->next = new;
}

void	ft_add_node(t_stack *new, t_stack **anchor)
{
	new->next = *anchor;
	*anchor = new;
}
