/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_header.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 14:54:47 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/02/19 14:54:48 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

void	ft_make_header(int *fd, t_stack *a)
{
	*fd = open("log.txt", O_WRONLY | O_CREAT | O_TRUNC);
	ft_putendl_fd("________________________________________________", *fd);
	ft_putendl_fd("Instructions memo:                              |", *fd);
	ft_putendl_fd("sa - swap first two values in stack 'A'         |", *fd);
	ft_putendl_fd("sb - swap first two values in stack 'B'         |", *fd);
	ft_putendl_fd("ss - swap first two in both stacks              |", *fd);
	ft_putendl_fd("ra - rotate stack 'A'                           |", *fd);
	ft_putendl_fd("rb - rotate stack 'B'                           |", *fd);
	ft_putendl_fd("rr - rotate both stacks                         |", *fd);
	ft_putendl_fd("rra - reverse rotate stack 'A'                  |", *fd);
	ft_putendl_fd("rrb - reverse rotate stack 'B'                  |", *fd);
	ft_putendl_fd("rrr - reverse ratate both stacks                |", *fd);
	ft_putendl_fd("pa - push top value from stack 'B' to stack 'A' |", *fd);
	ft_putendl_fd("pb - push top value form stack 'A' to stack 'B' |", *fd);
	ft_putendl_fd("________________________________________________|", *fd);
	ft_putendl_fd("\n_________________\nGiven values are:", *fd);
	while (a != NULL)
	{
		ft_putnbr_fd(a->value, *fd);
		ft_putchar_fd(' ', *fd);
		a = a->next;
	}
	ft_putendl_fd("\n", *fd);
	ft_putendl_fd("Suggested sorting instructions are:", *fd);
	ft_putendl_fd("____", *fd);
}
