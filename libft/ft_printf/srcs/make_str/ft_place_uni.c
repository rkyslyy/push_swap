/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_uni.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 13:05:21 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/19 13:05:22 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prlib.h"

void		ft_place_uni(wchar_t *str)
{
	size_t	n;

	n = 0;
	while (str[n] != '\0')
	{
		if (str[n] > 127)
			ft_print_uni(str[n]);
		else
			write(1, &str[n], 1);
		n++;
	}
}
