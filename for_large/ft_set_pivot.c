/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_pivot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 17:02:32 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/02/19 17:02:38 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

void	ft_set_pivot(t_stack *a, t_pack *pack)
{
	if (ft_get_size(a) <= 20)
		pack->pivot = ft_get_pivot(a, ft_get_size(a) / 2);
	else if (ft_get_size(a) <= 50)
		pack->pivot = ft_get_pivot(a, ft_get_size(a) / 2.5);
	else if (ft_get_size(a) <= 100)
		pack->pivot = ft_get_pivot(a, ft_get_size(a) / 3.5);
	else if (ft_get_size(a) <= 250)
		pack->pivot = ft_get_pivot(a, ft_get_size(a) / 4);
	else if (ft_get_size(a) <= 300)
		pack->pivot = ft_get_pivot(a, ft_get_size(a) / 5.5);
	else if (ft_get_size(a) <= 350)
		pack->pivot = ft_get_pivot(a, ft_get_size(a) / 6);
	else if (ft_get_size(a) <= 400)
		pack->pivot = ft_get_pivot(a, ft_get_size(a) / 6.5);
	else if (ft_get_size(a) <= 450)
		pack->pivot = ft_get_pivot(a, ft_get_size(a) / 7);
	else if (ft_get_size(a) <= 500)
		pack->pivot = ft_get_pivot(a, ft_get_size(a) / 7.5);
	else
		pack->pivot = ft_get_pivot(a, ft_get_size(a) / 9);
}
