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

// int		ft_new_pivot(t_stack *a, int tail)
// {
// 	int		size;
// 	int		min;
// 	int		max;
// 	int		count;
// 	int		ret;
// 	int		mem;
// 	t_stack	*ptr;

// 	size = 0;
// 	ptr = a;
// 	while (ptr->value != tail)
// 	{
// 		size += 1;
// 		ptr = ptr->next;
// 	}
// 	ptr = a;
// 	min = ptr->value;
// 	while (ptr->value != tail)
// 	{
// 		if (ptr->value < min)
// 			min = ptr->value;
// 		ptr = ptr->next;
// 	}
// 	ptr = a;
// 	max = ptr->value;
// 	while (ptr->value != tail)
// 	{
// 		if (ptr->value > max)
// 			max = ptr->value;
// 		ptr = ptr->next;
// 	}
// 	count = 0;
// 	ptr = a;
// 	mem = min;
// 	ret = max;
// 	while (count < (size / 2))
// 	{
// 		ptr = a;
// 		ret = max;
// 		while (ptr->value != tail)
// 		{
// 			if (ptr->value < ret && ptr->value > mem)
// 				ret = ptr->value;
// 			ptr = ptr->next;
// 		}
// 		mem = ret;
// 		count += 1;
// 	}
// 	return (ret);
// }

// void	ft_fast_af_boi(t_stack **a, t_stack **b, t_pack *pack)
// {
// 	t_stack	*aptr;
// 	t_stack	*bptr;
// 	int		pivot;
// 	int		tail;

// 	aptr = *a;
// 	bptr = *b;
// 	pivot = ft_get_pivot(*a, ft_get_size(*a) / 2);
// 	tail = ft_get_last_value(aptr);
// 	while (aptr->value != tail)
// 	{
// 		if (aptr->value >= pivot)
// 		{
// 			ft_push_from_a_to_b(a, b, pack);
// 			aptr = *a;
// 			bptr = *b;
// 		}
// 		else
// 		{
// 			ft_rotate_a(a, pack);
// 			aptr = *a;
// 		}
// 	}
// 	if (aptr->value >= pivot)
// 	{
// 		ft_push_from_a_to_b(a, b, pack);
// 		aptr = *a;
// 		bptr = *b;
// 	}
// 	else
// 	{
// 		ft_rotate_a(a, pack);
// 		aptr = *a;
// 	}
// 	if (ft_pick_rotate(aptr, ft_get_min(bptr)) == 1)
// 		while (ft_get_last_value(bptr) != ft_get_min(bptr))
// 		{
// 			ft_rotate_b(b, pack);
// 			bptr = *b;
// 		}
// 	else
// 		while (ft_get_last_value(bptr) != ft_get_min(bptr))
// 		{
// 			ft_reverse_rotate_b(b, pack);
// 			bptr = *b;
// 		}
// 	tail = bptr->value;
// 	ft_print_stacks(*a, *b, "NULL", *pack);
// 	while (bptr != NULL)
// 	{
// 		ft_push_from_b_to_a(a, b, pack);
// 		aptr = *a;
// 		bptr = *b;
// 	}
// 	ft_print_stacks(*a, *b, "NULL", *pack);
// 	ft_rotate_a(a, pack);
// 	aptr = *a;
// 	pivot = ft_new_pivot(aptr, tail);
// 	printf("from %d tp %d\n", aptr->value, tail);
// 	printf("pivot is %d\n", pivot);
// 	while (aptr->value != tail)
// 	{
// 		if (aptr->value >= pivot)
// 		{
// 			ft_push_from_a_to_b(a, b, pack);
// 			aptr = *a;
// 			bptr = *b;
// 		}
// 		else
// 		{
// 			ft_rotate_a(a, pack);
// 			aptr = *a;
// 		}
// 	}
// 	if (aptr->value >= pivot)
// 	{
// 		ft_push_from_a_to_b(a, b, pack);
// 		aptr = *a;
// 		bptr = *b;
// 	}
// 	else
// 	{
// 		ft_rotate_a(a, pack);
// 		aptr = *a;
// 	}
// 	if (ft_pick_rotate(aptr, ft_get_min(bptr)) == 1)
// 		while (ft_get_last_value(bptr) != ft_get_min(bptr))
// 		{
// 			ft_rotate_b(b, pack);
// 			bptr = *b;
// 		}
// 	else
// 		while (ft_get_last_value(bptr) != ft_get_min(bptr))
// 		{
// 			ft_reverse_rotate_b(b, pack);
// 			bptr = *b;
// 		}
// 	tail = bptr->value;
// 	while (bptr != NULL)
// 	{
// 		ft_push_from_b_to_a(a, b, pack);
// 		aptr = *a;
// 		bptr = *b;
// 	}
// 	ft_print_stacks(*a, *b, "NULL", *pack);
// 	ft_rotate_a(a, pack);
// 	aptr = *a;
// 	pivot = ft_new_pivot(aptr, tail);
// 	printf("from %d tp %d\n", aptr->value, tail);
// 	printf("pivot is %d\n", pivot);
// 	while (aptr->value != tail)
// 	{
// 		if (aptr->value >= pivot)
// 		{
// 			ft_push_from_a_to_b(a, b, pack);
// 			aptr = *a;
// 			bptr = *b;
// 		}
// 		else
// 		{
// 			ft_rotate_a(a, pack);
// 			aptr = *a;
// 		}
// 	}
// 	if (aptr->value >= pivot)
// 	{
// 		ft_push_from_a_to_b(a, b, pack);
// 		aptr = *a;
// 		bptr = *b;
// 	}
// 	else
// 	{
// 		ft_rotate_a(a, pack);
// 		aptr = *a;
// 	}
// 	if (ft_pick_rotate(aptr, ft_get_min(bptr)) == 1)
// 		while (ft_get_last_value(bptr) != ft_get_min(bptr))
// 		{
// 			ft_rotate_b(b, pack);
// 			bptr = *b;
// 		}
// 	else
// 		while (ft_get_last_value(bptr) != ft_get_min(bptr))
// 		{
// 			ft_reverse_rotate_b(b, pack);
// 			bptr = *b;
// 		}
// 	tail = bptr->value;
// 	while (bptr != NULL)
// 	{
// 		ft_push_from_b_to_a(a, b, pack);
// 		aptr = *a;
// 		bptr = *b;
// 	}
// 	ft_print_stacks(*a, *b, "NULL", *pack);
// 	ft_rotate_a(a, pack);
// 	aptr = *a;
// 	pivot = ft_new_pivot(aptr, tail);
// 	printf("from %d tp %d\n", aptr->value, tail);
// 	printf("pivot is %d\n", pivot);
// 	while (aptr->value != tail)
// 	{
// 		if (aptr->value >= pivot)
// 		{
// 			ft_push_from_a_to_b(a, b, pack);
// 			aptr = *a;
// 			bptr = *b;
// 		}
// 		else
// 		{
// 			ft_rotate_a(a, pack);
// 			aptr = *a;
// 		}
// 	}
// 	if (aptr->value >= pivot)
// 	{
// 		ft_push_from_a_to_b(a, b, pack);
// 		aptr = *a;
// 		bptr = *b;
// 	}
// 	else
// 	{
// 		ft_rotate_a(a, pack);
// 		aptr = *a;
// 	}
// 	if (ft_pick_rotate(aptr, ft_get_min(bptr)) == 1)
// 		while (ft_get_last_value(bptr) != ft_get_min(bptr))
// 		{
// 			ft_rotate_b(b, pack);
// 			bptr = *b;
// 		}
// 	else
// 		while (ft_get_last_value(bptr) != ft_get_min(bptr))
// 		{
// 			ft_reverse_rotate_b(b, pack);
// 			bptr = *b;
// 		}
// 	tail = bptr->value;
// 	while (bptr != NULL)
// 	{
// 		ft_push_from_b_to_a(a, b, pack);
// 		aptr = *a;
// 		bptr = *b;
// 	}
// 	ft_print_stacks(*a, *b, "NULL", *pack);
// 	ft_rotate_a(a, pack);
// 	aptr = *a;
// 	pivot = ft_new_pivot(aptr, tail);
// 	printf("from %d tp %d\n", aptr->value, tail);
// 	printf("pivot is %d\n", pivot);
// 	while (aptr->value != tail)
// 	{
// 		if (aptr->value >= pivot)
// 		{
// 			ft_push_from_a_to_b(a, b, pack);
// 			aptr = *a;
// 			bptr = *b;
// 		}
// 		else
// 		{
// 			ft_rotate_a(a, pack);
// 			aptr = *a;
// 		}
// 	}
// 	if (aptr->value >= pivot)
// 	{
// 		ft_push_from_a_to_b(a, b, pack);
// 		aptr = *a;
// 		bptr = *b;
// 	}
// 	else
// 	{
// 		ft_rotate_a(a, pack);
// 		aptr = *a;
// 	}
// 	if (ft_pick_rotate(aptr, ft_get_min(bptr)) == 1)
// 		while (ft_get_last_value(bptr) != ft_get_min(bptr))
// 		{
// 			ft_rotate_b(b, pack);
// 			bptr = *b;
// 		}
// 	else
// 		while (ft_get_last_value(bptr) != ft_get_min(bptr))
// 		{
// 			ft_reverse_rotate_b(b, pack);
// 			bptr = *b;
// 		}
// 	tail = bptr->value;
// 	while (bptr != NULL)
// 	{
// 		ft_push_from_b_to_a(a, b, pack);
// 		aptr = *a;
// 		bptr = *b;
// 	}
// 	ft_print_stacks(*a, *b, "NULL", *pack);
// 	ft_rotate_a(a, pack);
// 	aptr = *a;
// 	pivot = ft_new_pivot(aptr, tail);
// 	printf("from %d tp %d\n", aptr->value, tail);
// 	printf("pivot is %d\n", pivot);
// 	while (aptr->value != tail)
// 	{
// 		if (aptr->value >= pivot)
// 		{
// 			ft_push_from_a_to_b(a, b, pack);
// 			aptr = *a;
// 			bptr = *b;
// 		}
// 		else
// 		{
// 			ft_rotate_a(a, pack);
// 			aptr = *a;
// 		}
// 	}
// 	if (aptr->value >= pivot)
// 	{
// 		ft_push_from_a_to_b(a, b, pack);
// 		aptr = *a;
// 		bptr = *b;
// 	}
// 	else
// 	{
// 		ft_rotate_a(a, pack);
// 		aptr = *a;
// 	}
// 	if (ft_pick_rotate(aptr, ft_get_min(bptr)) == 1)
// 		while (ft_get_last_value(bptr) != ft_get_min(bptr))
// 		{
// 			ft_rotate_b(b, pack);
// 			bptr = *b;
// 		}
// 	else
// 		while (ft_get_last_value(bptr) != ft_get_min(bptr))
// 		{
// 			ft_reverse_rotate_b(b, pack);
// 			bptr = *b;
// 		}
// 	tail = bptr->value;
// 	while (bptr != NULL)
// 	{
// 		ft_push_from_b_to_a(a, b, pack);
// 		aptr = *a;
// 		bptr = *b;
// 	}
// 	ft_print_stacks(*a, *b, "NULL", *pack);
// }


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
		ft_fast_af_boi(&a, &b, &pack);
	ft_free_lists(a, b);
	return (0);
}
