/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:32:48 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/02/19 17:35:21 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

static void	ft_before_a(t_pack pack, char const *line)
{
	if (pack.highlight == 1 && (ft_strcmp(line, "ra") == 0 ||
		ft_strcmp(line, "rra") == 0 || ft_strcmp(line, "pa") == 0 ||
			ft_strcmp(line, "pb") == 0 || ft_strcmp(line, "rrr") == 0
			|| ft_strcmp(line, "rr") == 0))
		ft_printf("[");
	if (pack.highlight == 1 && (ft_strcmp(line, "ra") == 0 ||
		ft_strcmp(line, "rr") == 0))
		ft_printf("⇽ ");
	if (pack.highlight == 1 && (ft_strcmp(line, "rra") == 0 ||
		ft_strcmp(line, "rrr") == 0))
		ft_printf("⇾ ");
}

static void	ft_after_a(t_pack pack, char const *line)
{
	if (pack.highlight == 1 && ft_strcmp(line, "pb") == 0)
		ft_printf(" ↘ ");
	if (pack.highlight == 1 && (ft_strcmp(line, "ra") == 0 ||
		ft_strcmp(line, "rr") == 0))
		ft_printf(" ⇽");
	if (pack.highlight == 1 && (ft_strcmp(line, "rra") == 0 ||
		ft_strcmp(line, "rrr") == 0))
		ft_printf(" ⇾");
	if (pack.highlight == 1 && (ft_strcmp(line, "ra") == 0 ||
		ft_strcmp(line, "rra") == 0 || ft_strcmp(line, "pa") == 0 ||
			ft_strcmp(line, "pb") == 0 || ft_strcmp(line, "rrr") == 0
			|| ft_strcmp(line, "rr") == 0))
		ft_printf("]");
	ft_printf(": ");
}

static void	ft_before_b(t_pack pack, char const *line)
{
	if (pack.highlight == 1 && (ft_strcmp(line, "rb") == 0 ||
		ft_strcmp(line, "rrb") == 0 || ft_strcmp(line, "pa") == 0 ||
			ft_strcmp(line, "pb") == 0 || ft_strcmp(line, "rrr") == 0
			|| ft_strcmp(line, "rr") == 0))
		ft_printf("[");
	if (pack.highlight == 1 && (ft_strcmp(line, "rb") == 0 ||
		ft_strcmp(line, "rr") == 0))
		ft_printf("⇽ ");
	if (pack.highlight == 1 && (ft_strcmp(line, "rrb") == 0 ||
		ft_strcmp(line, "rrr") == 0))
		ft_printf("⇾ ");
}

static void	ft_after_b(t_pack pack, char const *line)
{
	if (pack.highlight == 1 && ft_strcmp(line, "pa") == 0)
		ft_printf(" ↗ ");
	if (pack.highlight == 1 && (ft_strcmp(line, "rb") == 0 ||
		ft_strcmp(line, "rr") == 0))
		ft_printf(" ⇽");
	if (pack.highlight == 1 && (ft_strcmp(line, "rrb") == 0 ||
		ft_strcmp(line, "rrr") == 0))
		ft_printf(" ⇾");
	if (pack.highlight == 1 && (ft_strcmp(line, "rb") == 0 ||
		ft_strcmp(line, "rrb") == 0 || ft_strcmp(line, "pa") == 0 ||
			ft_strcmp(line, "pb") == 0 || ft_strcmp(line, "rrr") == 0
			|| ft_strcmp(line, "rr") == 0))
		ft_printf("]");
	ft_printf(": ");
}

void		ft_print_stacks(t_stack *a, t_stack *b, char const *l, t_pack pack)
{
	t_stack *ptr;

	ptr = a;
	ft_printf("\n");
	ft_before_a(pack, l);
	ft_printf("a");
	ft_after_a(pack, l);
	ft_nums_a(ptr, a, pack, l);
	ft_printf("NULL\n");
	ptr = b;
	ft_before_b(pack, l);
	ft_printf("b");
	ft_after_b(pack, l);
	ft_nums_b(ptr, b, pack, l);
	ft_printf("NULL\n\n");
}
