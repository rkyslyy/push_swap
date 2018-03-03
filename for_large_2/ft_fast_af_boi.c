/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fast_af_boi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 14:29:36 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/02/21 14:29:36 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../swaplib.h"

void	ft_swap_rotate(t_stack **a, t_pack *pack)
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

static int		ft_get_big(t_stack *b, int val)
{
	t_stack *ptr;
	int		ret;

	if (val > ft_get_max(b))
		return (ft_get_min(b));
	ptr = b;
	ret = ft_get_max(b);
	while (ptr != NULL)
	{
		if (ptr->value < ret && ptr->value > val)
			ret = ptr->value;
		ptr = ptr->next;
	}
	return (ret);
}

void	ft_deal_with_a(t_stack **a, t_stack **b, t_pack *pack)
{
	t_stack *bptr;
	t_stack *aptr;

	bptr = *b;
	aptr = *a;
	if (aptr != NULL &&
		ft_pick_rotate(aptr, ft_get_big(aptr, bptr->value)) == 1)
		while (aptr->value != ft_get_big(aptr, bptr->value))
		{
			ft_rotate_a(a, pack);
			aptr = *a;
		}
	else
		while (aptr != NULL &&
			aptr->value != ft_get_big(aptr, bptr->value))
		{
			ft_reverse_rotate_a(a, pack);
			aptr = *a;
		}
	ft_push_from_b_to_a(a, b, pack);
}

int		ft_new_pivot(t_stack *a, int tail)
{
	int		size;
	int		min;
	int		max;
	int		count;
	int		ret;
	int		mem;
	t_stack	*ptr;

	size = 0;
	ptr = a;
	while (ptr->value != tail)
	{
		size += 1;
		ptr = ptr->next;
	}
	ptr = a;
	min = ptr->value;
	while (ptr->value != tail)
	{
		if (ptr->value < min)
			min = ptr->value;
		ptr = ptr->next;
	}
	ptr = a;
	max = ptr->value;
	while (ptr->value != tail)
	{
		if (ptr->value > max)
			max = ptr->value;
		ptr = ptr->next;
	}
	count = 0;
	ptr = a;
	mem = min;
	ret = max;
	while (count < (size / 2))
	{
		ptr = a;
		ret = max;
		while (ptr->value != tail)
		{
			if (ptr->value < ret && ptr->value > mem)
				ret = ptr->value;
			ptr = ptr->next;
		}
		mem = ret;
		count += 1;
	}
	return (ret);
}

int		ft_is_part_sorted(t_stack *a, int tail)
{
	t_stack *ptr;

	 ptr = a;
	 while (ptr->value != tail)
	 {
	 	if (ptr->value > ptr->next->value)
	 		return (0);
	 	ptr = ptr->next;
	 }
	 return (1);
}

int		ft_find_size(t_stack *b, int pivot)
{
	int ret;
	t_stack *ptr;

	ret = 0;
	ptr = b;
	while (ptr->next && ptr->value >= pivot)
	{
		ret += 1;
		ptr = ptr->next;
	}
	return (ret);
}

int		ft_find_size_a(t_stack *a, int pivot)
{
	int ret;
	t_stack *ptr;

	ret = 0;
	ptr = a;
	while (ptr->next && ptr->value <= pivot)
	{
		ret += 1;
		ptr = ptr->next;
	}
	return (ret);
}

int		ft_find_next(t_stack *b, int pivot)
{
	t_stack *ptr;

	ptr = b;
	while (ptr->next && ptr->value >= pivot)
		ptr = ptr->next;
	return (ptr->value);
}

int		ft_find_next_a(t_stack *a, int pivot)
{
	t_stack *ptr;

	ptr = a;
	while (ptr->next && ptr->value < pivot)
		ptr = ptr->next;
	return (ptr->value);
}

int		ft_min(t_stack *a)
{
	int ret;
	int	count;
	t_stack *ptr;

	ret = a->value;
	count = 0;
	ptr = a;
	while (count < 3)
	{
		if (ptr->value < ret)
			ret = ptr->value;
		ptr = ptr->next;
		count += 1;
	}
	return (ret);
}

int		ft_max(t_stack *a)
{
	int ret;
	int	count;
	t_stack *ptr;

	ret = a->value;
	count = 0;
	ptr = a;
	while (count < 3)
	{
		if (ptr->value > ret)
			ret = ptr->value;
		ptr = ptr->next;
		count += 1;
	}
	return (ret);
}

void	ft_swap_three(t_stack **a, t_stack **b, t_pack *pack)
{
	t_stack *ptr;
	int		min;
	int		max;

	ptr = *a;
	min = ft_min(*a);
	max = ft_max(*a);
	if (ptr->value > ptr->next->value ||
		ptr->next->value > ptr->next->next->value)
	{
		if (ptr->value > ptr->next->value && ptr->next->value < ptr->next->next->value)
		{
			if (ptr->value != max)
				ft_swap_a(a, pack);
			else
			{
				ft_push_from_a_to_b(a, b, pack);
				ft_rotate_a(a, pack);
				ft_rotate_a(a, pack);
				ft_push_from_b_to_a(a, b, pack);
				ft_reverse_rotate_a(a, pack);
				ft_reverse_rotate_a(a, pack);
			}
		}
		else if (ptr->value < ptr->next->value && ptr->next->value > ptr->next->next->value)
		{
			if (ptr->value == min)
			{
				ft_rotate_a(a, pack);
				ft_swap_a(a, pack);
				ft_reverse_rotate_a(a, pack);
			}
			else
			{
				ft_push_from_a_to_b(a, b, pack);
				ft_swap_a(a, pack);
				ft_rotate_a(a, pack);
				ft_push_from_b_to_a(a, b, pack);
				ft_reverse_rotate_a(a, pack);
			}
		}
		else if (ptr->value > ptr->next->value && ptr->next->value < ptr->next->next->value)
		{
			ft_push_from_a_to_b(a, b, pack);
			ft_rotate_a(a, pack);
			ft_rotate_a(a, pack);
			ft_push_from_b_to_a(a, b, pack);
			ft_reverse_rotate_a(a, pack);
			ft_reverse_rotate_a(a, pack);
		}
		else if (ptr->value > ptr->next->value && ptr->next->value > ptr->next->next->value)
		{
			ft_push_from_a_to_b(a, b, pack);
			ft_swap_a(a, pack);
			ft_rotate_a(a, pack);
			ft_rotate_a(a, pack);
			ft_push_from_b_to_a(a, b, pack);
			ft_reverse_rotate_a(a, pack);
			ft_reverse_rotate_a(a, pack);
		}
	}
}

int		ft_is_left(t_stack *stack, int end, int pivot, int mem)
{
	t_stack *ptr;

	ptr = stack;
	if (mem <= pivot && mem > end)
		return (1);
	while (ptr->value >= end)
	{
		if (ptr->value >= pivot)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

int		ft_is_left_a(t_stack *stack, int end, int pivot)
{
	t_stack *ptr;

	ptr = stack;
	while (ptr->value <= end)
	{
		if (ptr->value <= pivot)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

void	ft_fast_af_boi(t_stack **a, t_stack **b, t_pack *pack)
{
	t_stack	*aptr;
	t_stack	*bptr;
	int		pivot;
	int		mem;
	t_stack	*pivots;
	int		count;

	aptr = *a;
	bptr = *b;
	pivots = NULL;
	count = 0;
	ft_add_node(ft_create_node(ft_get_min(*a)), &pivots);
	while (!ft_is_sorted(*a))
	{
		pivot = ft_get_pivot(*a, ft_get_size(*a) / 2);
		mem = ft_get_last_value(*a);
		while (aptr->value != mem)
		{
			if (aptr->value <= pivot)
			{
				ft_push_from_a_to_b(a, b, pack);
				aptr = *a;
				bptr = *b;
			}
			else
			{
				ft_rotate_a(a, pack);
				aptr = *a;
			}
		}
		if (aptr->value <= pivot)
		{
			ft_push_from_a_to_b(a, b, pack);
			aptr = *a;
			bptr = *b;
		}
		else
		{
			ft_rotate_a(a, pack);
			aptr = *a;
		}
		ft_add_node(ft_create_node(ft_get_min(*a)), &pivots);
	}
	while (aptr->value != ft_get_min(*a))
	{
		ft_rotate_a(a, pack);
		aptr = *a;
	}
	while (ft_get_size(*b) > 150)
	{
		mem = ft_get_last_value(*b);
		if (ft_find_size(*b, pivots->next->value) > 3)
		{
			// printf("brekin b\n");
			pivot = ft_new_pivot(*b, ft_find_next(*b, pivots->next->value));
			while (bptr->value >= pivots->next->value && bptr->value != mem && ft_is_left(*b, pivots->next->value, pivot, mem))
			{
				if (bptr->value >= pivot)
					ft_push_from_b_to_a(a, b, pack);
				else
				{
					ft_rotate_b(b, pack);
				}
				aptr = *a;
				bptr = *b;
			}
			if (bptr->value >= pivot)
			{
				mem = bptr->next->value;
				ft_push_from_b_to_a(a, b, pack);
			}
			aptr = *a;
			bptr = *b;
			if (ft_pick_rotate(*b, mem) == 1)
				while (ft_get_last_value(*b) != mem)
					ft_rotate_b(b, pack);
			else
				while (ft_get_last_value(*b) != mem)
					ft_reverse_rotate_b(b, pack);
			aptr = *a;
			bptr = *b;
			ft_add_next(ft_create_node(pivot), &pivots);
		}
		else
		{
			while (bptr->value >= pivots->next->value)
			{
				ft_push_from_b_to_a(a, b, pack);
				aptr = *a;
				bptr = *b;
			}
			if (ft_pick_rotate(*b, mem) == 1)
				while (ft_get_last_value(*b) != mem)
					ft_rotate_b(b, pack);
			else
				while (ft_get_last_value(*b) != mem)
					ft_reverse_rotate_b(b, pack);
			aptr = *a;
			bptr = *b;
		}
		while (ft_find_size_a(*a, pivots->value) > 3)
		{
			// printf("brekin a\n");
			pivot = ft_new_pivot(*a, ft_find_next_a(*a, pivots->value));
			// printf("%d\n", pivot);
			mem = ft_get_last_value(*a);
			while (aptr->value <= pivots->value && ft_is_left_a(*a, pivots->value, pivot))
			{
				if (aptr->value <= pivot)
					ft_push_from_a_to_b(a, b, pack);
				else
					ft_rotate_a(a, pack);
				aptr = *a;
				bptr = *b;
			}
			if (aptr->value <= pivot)
				ft_push_from_a_to_b(a, b, pack);
			aptr = *a;
			bptr = *b;
			if (ft_pick_rotate(*a, mem) == 1)
				while (ft_get_last_value(*a) != mem)
					ft_rotate_a(a, pack);
			else
				while (ft_get_last_value(*a) != mem)
					ft_reverse_rotate_a(a, pack);
			aptr = *a;
			bptr = *b;
			ft_add_next(ft_create_node(pivot), &pivots);
		}
		if (ft_find_size_a(*a, pivots->value) == 2)
		{
			if (aptr->value > aptr->next->value)
			ft_swap_a(a, pack);
			aptr = *a;
			// printf("swappin\n");
		}
		else if (ft_find_size_a(*a, pivots->value) == 3)
		{
			// printf("we got %d %d %d\n", aptr->value, aptr->next->value, aptr->next->next->value);
			// printf("swappin three\n");
			ft_swap_three(a, b, pack);
			aptr = *a;
			bptr = *b;
		}
		ft_del_node(&pivots);
		count += 1;
		// ft_print_stacks(*a, *b, "stacks", *pack);
		// ft_print_stacks(pivots, 0, "pivots", *pack);
		// printf("Press Enter...\n");
		// getchar();
	}
	ft_rev_quick_sort(b, a, pack);
	while (*b)
		ft_deal_with_a(a, b, pack);
	// aptr = *a;
	// // while (*b)
	// // 	ft_deal_with_a(a, b, pack);
	// // aptr = *a;
	// // bptr = *b;
	// if (ft_pick_rotate(*a, ft_get_min(*a)) == 1)
	// 	while (aptr->value != ft_get_min(*a))
	// 	{
	// 		ft_rotate_a(a, pack);
	// 		aptr = *a;
	// 	}
	// else
	// 	while (aptr->value != ft_get_min(*a))
	// 	{
	// 		ft_reverse_rotate_a(a, pack);
	// 		aptr = *a;
	// 	}
	// if (ft_is_sorted(*a))
	// 	printf("a is sorted boii\n");
	// else
	// 	printf("a is not sorted\n");
	// while (*b)
	// {
	// 	mem = ft_get_last_value(*b);
	// 	if (ft_find_size(*b, pivots->next->value) > 3)
	// 	{
	// 		pivot = ft_new_pivot(*b, ft_find_next(*b, pivots->next->value));
	// 		while (bptr->value >= pivots->next->value)
	// 		{
	// 			if (bptr->value >= pivot)
	// 				ft_push_from_b_to_a(a, b, pack);
	// 			else
	// 				ft_rotate_b(b, pack);
	// 			aptr = *a;
	// 			bptr = *b;
	// 		}
	// 		if (bptr->value >= pivot)
	// 				ft_push_from_b_to_a(a, b, pack);
	// 			else
	// 				ft_rotate_b(b, pack);
	// 			aptr = *a;
	// 			bptr = *b;
	// 		if (ft_pick_rotate(*b, mem) == 1)
	// 			while (ft_get_last_value(*b) != mem)
	// 				ft_rotate_b(b, pack);
	// 		else
	// 			while (ft_get_last_value(*b) != mem)
	// 				ft_reverse_rotate_b(b, pack);
	// 		aptr = *a;
	// 		bptr = *b;
	// 		ft_add_next(ft_create_node(pivot), &pivots);
	// 	}
	// 	else
	// 	{
	// 		while (bptr->value >= pivots->next->value)
	// 		{
	// 			if (bptr->value >= pivots->next->value)
	// 				ft_push_from_b_to_a(a, b, pack);
	// 			else
	// 				ft_rotate_b(b, pack);
	// 			aptr = *a;
	// 			bptr = *b;
	// 		}
	// 		if (ft_pick_rotate(*b, mem) == 1)
	// 			while (ft_get_last_value(*b) != mem)
	// 				ft_rotate_b(b, pack);
	// 		else
	// 			while (ft_get_last_value(*b) != mem)
	// 				ft_reverse_rotate_b(b, pack);
	// 		aptr = *a;
	// 		bptr = *b;
	// 	}
	// 	while (ft_find_size_a(*a, pivots->value) > 3)
	// 	{
	// 		printf("brekin dis bitch\n");
	// 		pivot = ft_new_pivot(*a, ft_find_next_a(*a, pivots->value));
	// 		printf("%d\n", pivot);
	// 		mem = ft_get_last_value(*a);
	// 		while (aptr->value <= pivots->value)
	// 		{
	// 			if (aptr->value <= pivot)
	// 				ft_push_from_a_to_b(a, b, pack);
	// 			else
	// 				ft_rotate_a(a, pack);
	// 			aptr = *a;
	// 			bptr = *b;
	// 		}
	// 		if (aptr->value <= pivot)
	// 				ft_push_from_a_to_b(a, b, pack);
	// 			else
	// 				ft_rotate_a(a, pack);
	// 			aptr = *a;
	// 			bptr = *b;
	// 		if (ft_pick_rotate(*a, mem) == 1)
	// 			while (ft_get_last_value(*a) != mem)
	// 				ft_rotate_a(a, pack);
	// 		else
	// 			while (ft_get_last_value(*a) != mem)
	// 				ft_reverse_rotate_a(a, pack);
	// 		aptr = *a;
	// 		bptr = *b;
	// 		ft_add_next(ft_create_node(pivot), &pivots);
	// 	}
	// 	if (ft_find_size_a(*a, pivots->value) == 2)
	// 	{
	// 		if (aptr->value > aptr->next->value)
	// 		ft_swap_a(a, pack);
	// 		aptr = *a;
	// 		printf("swappin\n");
	// 	}
	// 	else if (ft_find_size_a(*a, pivots->value) == 3)
	// 	{
	// 		ft_swap_three(a, b, pack);
	// 		aptr = *a;
	// 		bptr = *b;
	// 		printf("swappin three\n");
	// 	}
	// 	ft_del_node(&pivots);
	// 	}
	// 	if (ft_find_size_a(*a, pivots->value) == 2)
	// 	{
	// 		if (aptr->value > aptr->next->value)
	// 		ft_swap_a(a, pack);
	// 		aptr = *a;
	// 		printf("swappin\n");
	// 	}
	// 	else if (ft_find_size_a(*a, pivots->value) == 3)
	// 	{
	// 		ft_swap_three(a, b, pack);
	// 		aptr = *a;
	// 		bptr = *b;
	// 		printf("swappin three\n");
	// 	}
	// 	ft_del_node(&pivots);
	// }
	// ft_print_stacks(*a, *b, "stacks", *pack);
	// ft_print_stacks(pivots, 0, "pivots", *pack);
}