/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_conf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 13:26:16 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/02/20 13:26:17 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

void	ft_check_conf(char **argv, int argc, t_pack *pack)
{
	pack->ac = argc;
	while (argc != 1)
	{
		if (ft_strcmp(argv[argc - 1], "-i") == 0)
			pack->no = 1;
		argc -= 1;
	}
}
