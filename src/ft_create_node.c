/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 17:36:43 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/02/19 17:37:00 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

t_stack	*ft_create_node(int value)
{
	t_stack *new;

	new = (t_stack*)malloc(sizeof(t_stack));
	new->value = value;
	new->next = NULL;
	return (new);
}
