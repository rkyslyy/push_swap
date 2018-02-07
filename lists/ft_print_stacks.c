/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:32:48 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/02/07 15:32:49 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

void	ft_print_stacks(t_stack *a, t_stack *b)
{
	t_stack *ptr;

	ptr = a;
	printf("\na: ");
	while (ptr != NULL)
	{
		printf("%d - ", ptr->value);
		ptr = ptr->next;
	}
	printf("NULL\nb: ");
	ptr = b;
	while (ptr != NULL)
	{
		printf("%d - ", ptr->value);
		ptr = ptr->next;
	}
	printf("NULL\n");
}
