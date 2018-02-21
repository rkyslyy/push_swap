/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fast_af_boi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 14:29:36 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/02/21 14:29:36 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../swaplib.h"

void	ft_fast_af_boi(t_stack **a, t_stack **b, t_pack *pack)
{
	int pivot;

	printf("hello\n");
	ft_print_stacks(*a, *b, *pack);
	b = NULL;
	pack = NULL;
	pivot = ft_get_pivot(*a, 2);
	//ft_printf("%d\n", pivot);
}
