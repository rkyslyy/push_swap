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

int		ft_check_front(t_stack *a, int pivot)
{
	t_stack *ptr;
	int		mem;

	ptr = a;
	mem = a->value;
	while (ptr->value != pivot)
	{
		if (ptr->value < mem)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

int		ft_check_back(t_stack *a, int superlast)
{
	t_stack *ptr;
	int		mem;

	ptr = a;
	mem = a->value;
	while (ptr->value != superlast)
	{
		if (ptr->value < mem)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

int		ft_check_if(t_stack *a, int val)
{
	t_stack *ptr;

	ptr = a;
	while (ptr != NULL)
	{
		if (ptr->value < val)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

void	ft_fast_af_boi(t_stack **a, t_stack **b, t_pack *pack)
{
	t_stack	*aptr;
	t_stack *bptr;

	aptr = *a;
	bptr = *b;
	while (aptr != NULL && !ft_is_sorted(aptr))
	{
		ft_set_pivot(aptr, pack);
		while (ft_get_min(aptr) < pack->pivot)
		{
			if (ft_pick_rotate(aptr, ft_get_min(aptr)) == 1)
				while (aptr->value != ft_get_min(aptr))
				{
					ft_rotate_a(a, pack);
					aptr = *a;
				}
			else
				while (aptr->value != ft_get_min(aptr))
				{
					ft_reverse_rotate_a(a, pack);
					aptr = *a;
				}
			ft_push_from_a_to_b(a, b, pack);
			aptr = *a;
			bptr = *b;
		}
	}
	ft_print_stacks(*a, *b, "line", *pack);
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
	else
		ft_quick_sort(&a, &b, &pack);
	ft_free_lists(a, b);
	return (0);
}
