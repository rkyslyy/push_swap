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
		|| ft_strcmp(nums[0], "-t") == 0 || ft_strcmp(nums[0], "-h") == 0
		|| ft_strcmp(nums[0], "-r") == 0 || ft_strcmp(nums[0], "-i") == 0)
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
	*fd = open("log.txt", O_WRONLY | O_CREAT | O_TRUNC);
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

static void ft_check_conf(char **argv, int argc, t_pack *pack)
{
	while (argc != 1)
	{
		if (ft_strcmp(argv[argc - 1], "-i") == 0)
			pack->no = 1;
		argc -= 1;
	}
}

static int	ft_valid_com(char *line)
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

static int	ft_check_unique(t_stack *a)
{
	t_stack *ptr;
	int		mem;

	while (a != NULL)
	{
		mem = a->value;
		ptr = a;
		while (ptr != NULL)
		{
			ptr = ptr->next;
			if (ptr != NULL && ptr->value == mem)
				return (0);
		}
		a = a->next;
	}
	return (1);
}

static void	ft_apply(char *line, t_stack **a, t_stack **b, t_pack *pack)
{
	if (ft_strcmp(line, "sa") == 0)
		ft_swap_a(a, pack);
	if (ft_strcmp(line, "sb") == 0)
		ft_swap_b(b, pack);
	if (ft_strcmp(line, "ss") == 0)
		ft_swap_both(a, b, pack);
	if (ft_strcmp(line, "pa") == 0)
		ft_push_from_b_to_a(a, b, pack);
	if (ft_strcmp(line, "pb") == 0)
		ft_push_from_a_to_b(a, b, pack);
	if (ft_strcmp(line, "ra") == 0)
		ft_rotate_a(a, pack);
	if (ft_strcmp(line, "rb") == 0)
		ft_rotate_b(b, pack);
	if (ft_strcmp(line, "rr") == 0)
		ft_rotate_both(a, b, pack);
	if (ft_strcmp(line, "rra") == 0)
		ft_reverse_rotate_a(a, pack);
	if (ft_strcmp(line, "rrb") == 0)
		ft_reverse_rotate_b(b, pack);
	if (ft_strcmp(line, "rrr") == 0)
		ft_reverse_rotate_both(a, b, pack);
}

static void ft_assign(t_pack *pack, t_stack **a, t_stack **b, int *fd)
{
	*a = NULL;
	*b = NULL;
	*fd = -1;
	pack->total = 0;
	pack->print = 0;
	pack->visual = 0;
	pack->output = 0;
	pack->result = 0;
	pack->highlight = 0;
	pack->read = 0;
	pack->input = 0;
	pack->no = 0;
}

static int	ft_get_insts(t_pack *pack, char **line)
{
	if (pack->input == 1)
		ft_printf("Instruction: ");
	pack->add = get_next_line(pack->read, line);
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

static void	ft_vis_stacks(t_pack pack, char *line, t_stack *a, t_stack *b)
{
	if (pack.print == 0 && pack.visual == 1 && pack.add != 0)
	{
		ft_printf("[%s]\n", line);
		if (ft_strlen(line) == 2)
			ft_printf(" ↓↓");
		else
			ft_printf(" ↓↓↓");
		ft_print_stacks(a, b, line, pack);
	}
}

static int	ft_result(t_pack pack, int fd, t_stack *a)
{
	if (pack.output == 1)
		ft_putendl_fd("____", fd);
	if (pack.result == 1)
	{
		ft_printf("End of sorting\nTotal amount of operations: %d\n", pack.total);
		ft_printf("___________________________________\n");
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

static void	ft_shmatok(t_pack *pack, int *fd, t_stack *a, t_stack *b)
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

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;
	t_pack	pack;
	int		fd;

	ft_assign(&pack, &a, &b, &fd);
	ft_check_conf(argv, argc, &pack);
	while (argc > 1)
		if (ft_build_stack(&a, &pack, argv, argc--) || pack.read == -1)
			return (ft_return_usage());
	if (!ft_check_unique(a))
		return (ft_return_usage());
	ft_shmatok(&pack, &fd, a, b);
	while (pack.add != 0)
	{
		if (ft_get_insts(&pack, &line))
			return (ft_return_usage());
		ft_apply(line, &a, &b, &pack);
		ft_vis_stacks(pack, line, a, b);
		if (pack.output == 1 && ft_strlen(line))
			ft_putendl_fd(line, fd);
	}
	return (ft_result(pack, fd, a));
}
