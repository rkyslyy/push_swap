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

static int	ft_return_usage(void)
{
	ft_printf("Error\n____________________________________\n");
	ft_printf("Usage: ./push_swap [values] [flags] |\n");
	ft_printf("                      ^^       ^    |\n");
	ft_printf("   Range of integer only      -v    |\n");
	ft_printf("Digits, '-' and '+' only      -o    |\n");
	ft_printf("____________________________________|\n");
	return (1);
}

static int	ft_build_stack(t_stack **a, t_pack *pack, char **argv, int argc)
{
	char	**nums;

	pack->add = 0;
	nums = ft_strsplit(argv[argc - 1], ' ');
	if (!ft_is_input_valid(nums, pack))
		return (1);
	if (ft_strcmp(nums[0], "-v") == 0 || ft_strcmp(nums[0], "-o") == 0)
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

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;
	t_pack	pack;
	int		fd;

	a = NULL;
	b = NULL;
	pack.total = 0;
	pack.print = 0;
	pack.visual = 0;
	pack.output = 0;
	while (argc > 1)
		if (ft_build_stack(&a, &pack, argv, argc--))
			return (ft_return_usage());
	pack.add = 1;
	if (pack.print == 0 && pack.visual == 1 && pack.add != 0)
	{
		ft_printf("[Beginning]\n ↓↓↓↓↓↓↓↓↓");
		ft_print_stacks(a, b);
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
			ft_print_stacks(a, b);
		}
		if (pack.output == 1)
		{
			fd = open("output.txt", O_APPEND | O_CREAT, S_IRUSR | S_IWUSR);
			ft_putstr_fd(line, fd);
			close(fd);
		}
	}
	if (ft_is_sorted(a) && a->value == ft_get_min(a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}
