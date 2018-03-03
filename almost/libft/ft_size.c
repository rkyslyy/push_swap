/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:52:50 by rkyslyy           #+#    #+#             */
/*   Updated: 2017/11/14 16:53:35 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_size(unsigned int n)
{
	int m;

	m = 1;
	while (n >= 10)
	{
		n /= 10;
		m++;
	}
	return (m);
}