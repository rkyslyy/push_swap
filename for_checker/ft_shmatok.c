/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shmatok.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 13:27:02 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/02/20 13:27:03 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

void	ft_shmatok(t_pack *pack, int *fd, t_stack *a, t_stack *b)
{
	pack->add = 1;
	if (pack->input == 1)
		pack->read = 1;
	if (pack->output == 1)
		ft_make_header(fd, a);
	if (pack->print == 0 && pack->visual == 1 && pack->add != 0)
	{
		ft_printf("[Beginning]\n ↓↓↓↓↓↓↓↓↓");
		ft_print_stacks(a, b, "NULL", *pack);
	}
}
