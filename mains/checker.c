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

#include "../swaplib.h"

static int	ft_build_stack(t_stack **a, t_pack *pack, char **argv, int argc)
{
	char	**nums;

	pack->add = 0;
	nums = ft_strsplit(argv[argc - 1], ' ');
	if (nums[0] == 0)
		return (ft_free_nums(nums, 0));
	if (!ft_is_input_valid(nums, pack))
		return (ft_free_nums(nums, 1));
	if (ft_strcmp(nums[0], "-v") == 0 || ft_strcmp(nums[0], "-o") == 0
		|| ft_strcmp(nums[0], "-t") == 0 || ft_strcmp(nums[0], "-h") == 0
		|| ft_strcmp(nums[0], "-r") == 0 || ft_strcmp(nums[0], "-i") == 0)
		return (ft_free_nums(nums, 0));
	while (nums[pack->add] != 0)
		pack->add += 1;
	pack->add -= 1;
	while (pack->add >= 0)
	{
		ft_add_node(ft_create_node(ft_atoi(nums[pack->add])), a);
		pack->add -= 1;
	}
	return (ft_free_nums(nums, 0));
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

static void	ft_assign(t_pack *pack, t_stack **a, t_stack **b, int *fd)
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

int			main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;
	t_pack	pack;
	int		fd;

	ft_assign(&pack, &a, &b, &fd);
	ft_check_conf(argv, argc, &pack);
	while (pack.ac > 1)
		if (ft_build_stack(&a, &pack, argv, pack.ac--) || pack.read == -1)
			return (ft_return_error(argc));
	if (argc < 2 || ft_get_size(a) == 0 || !ft_check_unique(a))
		return (ft_return_error(argc));
	ft_shmatok(&pack, &fd, a, b);
	while (pack.add != 0)
	{
		if (ft_get_insts(&pack, &line))
			return (ft_return_error(argc));
		ft_apply(line, &a, &b, &pack);
		ft_vis_stacks(pack, line, a, b);
		if (pack.output == 1 && ft_strlen(line))
			ft_putendl_fd(line, fd);
		free(line);
	}
	return (ft_result(pack, fd, a, b));
}
