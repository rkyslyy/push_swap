/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_insts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 13:26:43 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/02/20 13:26:43 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

int	ft_get_insts(t_pack *pack, char **line)
{
	if (pack->input == 1)
		ft_printf("Instruction: ");
	pack->add = get_next_line(pack->read, line);
	if (pack->input == 1 && *line[0] == '\0')
		ft_printf("\n");
	if (pack->input == 1 && !ft_valid_com(*line))
		while (!ft_valid_com(*line))
		{
			ft_printf("Please enter valid instruction: ");
			pack->add = get_next_line(pack->read, line);
		}
	if (pack->read == 0 && !ft_valid_com(*line))
		return (1);
	if (pack->read != 0 && pack->read != 1 && !ft_valid_com(*line))
	{
		ft_printf("Next command in instructions file is invalid\n");
		return (1);
	}
	return (0);
}
