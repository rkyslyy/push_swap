/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_com.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 13:26:28 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/02/20 13:26:30 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

int	ft_valid_com(char *line)
{
	if (ft_strcmp(line, "sa") != 0 && ft_strcmp(line, "sb") != 0 &&
		ft_strcmp(line, "ss") != 0 && ft_strcmp(line, "ra") != 0 &&
		ft_strcmp(line, "rb") != 0 && ft_strcmp(line, "rr") != 0 &&
		ft_strcmp(line, "rra") != 0 && ft_strcmp(line, "rrb") != 0 &&
		ft_strcmp(line, "rrr") != 0 && ft_strcmp(line, "pa") != 0 &&
		ft_strcmp(line, "pb") != 0 && line[0] != '\0')
		return (0);
	return (1);
}
