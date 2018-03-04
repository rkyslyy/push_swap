/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_result.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 14:55:56 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/02/19 14:55:57 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

static void	ft_conclusion(t_stack *a, int fd, t_pack pack)
{
	if (ft_is_sorted(a) && a->value == ft_get_min(a))
	{
		if (pack.output == 1)
			ft_putendl_fd("Values are sorted", fd);
		ft_printf("OK\n");
	}
	else
	{
		if (pack.output == 1)
			ft_putendl_fd("Values are not sorted", fd);
		ft_printf("KO\n");
	}
}

int			ft_result(t_pack pack, int fd, t_stack *a, t_stack *b)
{
	if (pack.output == 1)
		ft_putendl_fd("____", fd);
	if (pack.result == 1)
	{
		ft_printf("Total amount of operations: %d\n", pack.total);
		ft_printf("___________________________________\n");
		ft_putstr_fd("Total amount of operations: ", fd);
		ft_putnbr_fd(pack.total, fd);
		ft_putchar_fd('\n', fd);
		ft_putendl_fd("____________________________________", fd);
	}
	ft_conclusion(a, fd, pack);
	close(fd);
	ft_free_lists(a, b);
	return (0);
}
