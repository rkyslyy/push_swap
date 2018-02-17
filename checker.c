/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:22:05 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/24 18:22:06 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./swaplib.h"

static int	ft_build_stack(t_stack **a, t_pack *pack, char **argv, int argc)
{
	char	**nums;

	pack->add = 0;
	nums = ft_strsplit(argv[argc - 1], ' ');
	if (!ft_is_input_valid(nums, pack))
		return (1);
	if (ft_strcmp(nums[0], "-v") == 0 || ft_strcmp(nums[0], "-o") == 0
		|| ft_strcmp(nums[0], "-t") == 0 || ft_strcmp(nums[0], "-h") == 0)
		return (0);
	while (nums[pack->add] != 0)
		pack->add += 1;
	pack->add -= 1;
	while (pack->add >= 0)
	{
		ft_add_node(ft_create_node(ft_atoi(nums[pack->add])), a);
		pack->add -= 1;
	}
	return (0);
}

static void	ft_make_header(int *fd, t_stack *a)
{
	*fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC);
	ft_putendl_fd("________________________________________________", *fd);
	ft_putendl_fd("Instructions memo:                              |", *fd);
	ft_putendl_fd("sa - swap first two in stack 'A'                |", *fd);
	ft_putendl_fd("sb - swap first two in stack 'B'                |", *fd);
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

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;
	t_pack	pack;
	int		fd;

	a = NULL;
	b = NULL;
	fd = -1;
	pack.total = 0;
	pack.print = 0;
	pack.visual = 0;
	pack.output = 0;
	pack.result = 0;
	pack.highlight = 0;
	while (argc > 1)
		if (ft_build_stack(&a, &pack, argv, argc--))
			return (ft_return_usage());
	pack.add = 1;
	if (pack.output == 1)
		ft_make_header(&fd, a);
	if (pack.print == 0 && pack.visual == 1 && pack.add != 0)
	{
		ft_printf("[Beginning]\n ↓↓↓↓↓↓↓↓↓");
		ft_print_stacks(a, b, "NULL", pack);
	}
	while (pack.add != 0)
	{
		pack.add = get_next_line(0, &line);
		if (ft_strcmp(line, "sa") == 0)
			ft_swap_a(&a, &pack);
		if (ft_strcmp(line, "sb") == 0)
			ft_swap_b(&b, &pack);
		if (ft_strcmp(line, "ss") == 0)
			ft_swap_both(&a, &b, &pack);
		if (ft_strcmp(line, "pa") == 0)
			ft_push_from_b_to_a(&a, &b, &pack);
		if (ft_strcmp(line, "pb") == 0)
			ft_push_from_a_to_b(&a, &b, &pack);
		if (ft_strcmp(line, "ra") == 0)
			ft_rotate_a(&a, &pack);
		if (ft_strcmp(line, "rb") == 0)
			ft_rotate_b(&b, &pack);
		if (ft_strcmp(line, "rr") == 0)
			ft_rotate_both(&a, &b, &pack);
		if (ft_strcmp(line, "rra") == 0)
			ft_reverse_rotate_a(&a, &pack);
		if (ft_strcmp(line, "rrb") == 0)
			ft_reverse_rotate_b(&b, &pack);
		if (ft_strcmp(line, "rrr") == 0)
			ft_reverse_rotate_both(&a, &b, &pack);
		if (pack.print == 0 && pack.visual == 1 && pack.add != 0)
		{
			ft_printf("[%s]\n", line);
			if (ft_strlen(line) == 2)
				ft_printf(" ↓↓");
			else
				ft_printf(" ↓↓↓");
			ft_print_stacks(a, b, line, pack);
		}
		if (pack.output == 1 && ft_strlen(line))
			ft_putendl_fd(line, fd);
	}
	if (pack.output == 1)
		ft_putendl_fd("____", fd);
	if (pack.result == 1)
	{
		ft_printf("Total amount of operations: %d\n", pack.total);
		ft_putstr_fd("Total amount of operations: ", fd);
		ft_putnbr_fd(pack.total, fd);
		ft_putchar_fd('\n', fd);
		ft_putendl_fd("____________________________________", fd);
	}
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
	close(fd);
	return (0);
}
