/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_last_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 17:29:18 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/02/06 17:29:18 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

int	ft_get_last_value(t_stack *anchor)
{
	int		ret;
	t_stack *ptr;

	ptr = anchor;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ret = ptr->value;
	return (ret);
}
