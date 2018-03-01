/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 17:14:23 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/22 17:14:48 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../swaplib.h"

static void	ft_swap_rotate(t_stack **a, t_pack *pack)
{
	t_stack *ptr;

	ptr = *a;
	if (!ft_is_sorted(ptr))
		ft_swap_a(a, pack);
	ptr = *a;
	if (ft_pick_rotate(ptr, ft_get_min(ptr)) == 1)
		while (ptr->value != ft_get_min(ptr))
		{
			ft_rotate_a(a, pack);
			ptr = *a;
		}
	else
		while (ptr->value != ft_get_min(ptr))
		{
			ft_reverse_rotate_a(a, pack);
			ptr = *a;
		}
}

static int	ft_build_stack(t_stack **a, t_pack *pack, char **argv, int argc)
{
	char	**nums;

	pack->add = 0;
	nums = ft_strsplit(argv[argc - 1], ' ');
	if (nums[0] == 0)
		ft_free_nums(nums, 0);
	if (!ft_is_input_valid(nums, pack))
		ft_free_nums(nums, 1);
	if (ft_strcmp(nums[0], "-v") == 0 || ft_strcmp(nums[0], "-o") == 0
		|| ft_strcmp(nums[0], "-t") == 0 || ft_strcmp(nums[0], "-h") == 0
		|| ft_strcmp(nums[0], "-r") == 0 || ft_strcmp(nums[0], "-i") == 0)
		ft_free_nums(nums, 0);
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

int			main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_pack	pack;

	a = NULL;
	b = NULL;
	pack.total = 0;
	pack.print = 1;
	pack.visual = 0;
	pack.ac = argc;
	while (pack.ac > 1)
		if (ft_build_stack(&a, &pack, argv, pack.ac--))
			return (ft_return_error(argc));
	if (argc < 2 || ft_get_size(a) == 0 || !ft_check_unique(a))
		return (ft_return_error(argc));
	if (ft_get_size(a) <= 3)
		ft_swap_rotate(&a, &pack);
	else if (ft_get_size(a) <= 10)
		ft_insert_swap(&a, &b, &pack);
	else if (ft_get_size(a) <= 100)
		ft_quick_sort(&a, &b, &pack);
	else
		ft_fast_af_boi(&a, &b, &pack);
	ft_free_lists(a, b);
	return (0);
}
