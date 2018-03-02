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

int		ft_get_big(t_stack *b, int val)
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

void	ft_swap_three(t_stack **a, t_stack **b, t_pack *pack)
{
	t_stack *ptr;
	int		min;

	ptr = *a;
	min = ft_min(*a);
	printf("min is %d\n", min);
	if (ptr->value > ptr->next->value ||
		ptr->next->value > ptr->next->next->value)
	{
		if (ptr->value > ptr->next->value && ptr->next->value < ptr->next->next->value)
			ft_swap_a(a, pack);
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
		else if (ptr->value > ptr->next->value && ptr->next->value < ptr->next->next->value)
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

void	ft_fast_af_boi(t_stack **a, t_stack **b, t_pack *pack)
{
	t_stack	*aptr;
	t_stack	*bptr;
	int		pivot;
	int		mem;
	t_stack	*pivots;

	aptr = *a;
	bptr = *b;
	pivots = NULL;
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
	mem = ft_get_last_value(*b);
	if (ft_find_size(*b, pivots->next->value) > 3)
	{
		pivot = ft_new_pivot(*b, ft_find_next(*b, pivots->next->value));
		while (bptr->value >= pivots->next->value)
		{
			if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
			aptr = *a;
			bptr = *b;
		}
		if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
			if (bptr->value >= pivots->next->value)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
		printf("brekin dis bitch\n");
		pivot = ft_new_pivot(*a, ft_find_next_a(*a, pivots->value));
		printf("%d\n", pivot);
		mem = ft_get_last_value(*a);
		while (aptr->value < pivots->value)
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
			else
				ft_rotate_a(a, pack);
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
		printf("swappin\n");
	}
	else if (ft_find_size_a(*a, pivots->value) == 3)
	{
		ft_swap_three(a, b, pack);
		aptr = *a;
		bptr = *b;
		printf("swappin three\n");
	}
	ft_del_node(&pivots);
	mem = ft_get_last_value(*b);
	if (ft_find_size(*b, pivots->next->value) > 3)
	{
		pivot = ft_new_pivot(*b, ft_find_next(*b, pivots->next->value));
		while (bptr->value >= pivots->next->value)
		{
			if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
			aptr = *a;
			bptr = *b;
		}
		if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
			if (bptr->value >= pivots->next->value)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
		printf("brekin dis bitch\n");
		pivot = ft_new_pivot(*a, ft_find_next_a(*a, pivots->value));
		printf("%d\n", pivot);
		mem = ft_get_last_value(*a);
		while (aptr->value < pivots->value)
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
			else
				ft_rotate_a(a, pack);
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
		printf("swappin\n");
	}
	else if (ft_find_size_a(*a, pivots->value) == 3)
	{
		ft_swap_three(a, b, pack);
		aptr = *a;
		bptr = *b;
		printf("swappin three\n");
	}
	ft_del_node(&pivots);
	mem = ft_get_last_value(*b);
	if (ft_find_size(*b, pivots->next->value) > 3)
	{
		pivot = ft_new_pivot(*b, ft_find_next(*b, pivots->next->value));
		while (bptr->value >= pivots->next->value)
		{
			if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
			aptr = *a;
			bptr = *b;
		}
		if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
			if (bptr->value >= pivots->next->value)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
		printf("brekin dis bitch\n");
		pivot = ft_new_pivot(*a, ft_find_next_a(*a, pivots->value));
		printf("%d\n", pivot);
		mem = ft_get_last_value(*a);
		while (aptr->value < pivots->value)
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
			else
				ft_rotate_a(a, pack);
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
		printf("swappin\n");
	}
	else if (ft_find_size_a(*a, pivots->value) == 3)
	{
		ft_swap_three(a, b, pack);
		aptr = *a;
		bptr = *b;
		printf("swappin three\n");
	}
	ft_del_node(&pivots);
	mem = ft_get_last_value(*b);
	if (ft_find_size(*b, pivots->next->value) > 3)
	{
		pivot = ft_new_pivot(*b, ft_find_next(*b, pivots->next->value));
		while (bptr->value >= pivots->next->value)
		{
			if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
			aptr = *a;
			bptr = *b;
		}
		if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
			if (bptr->value >= pivots->next->value)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
		printf("brekin dis bitch\n");
		pivot = ft_new_pivot(*a, ft_find_next_a(*a, pivots->value));
		printf("%d\n", pivot);
		mem = ft_get_last_value(*a);
		while (aptr->value < pivots->value)
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
			else
				ft_rotate_a(a, pack);
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
		printf("swappin\n");
	}
	else if (ft_find_size_a(*a, pivots->value) == 3)
	{
		ft_swap_three(a, b, pack);
		aptr = *a;
		bptr = *b;
		printf("swappin three\n");
	}
	ft_del_node(&pivots);
	mem = ft_get_last_value(*b);
	if (ft_find_size(*b, pivots->next->value) > 3)
	{
		pivot = ft_new_pivot(*b, ft_find_next(*b, pivots->next->value));
		while (bptr->value >= pivots->next->value)
		{
			if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
			aptr = *a;
			bptr = *b;
		}
		if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
			if (bptr->value >= pivots->next->value)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
		printf("brekin dis bitch\n");
		pivot = ft_new_pivot(*a, ft_find_next_a(*a, pivots->value));
		printf("%d\n", pivot);
		mem = ft_get_last_value(*a);
		while (aptr->value < pivots->value)
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
			else
				ft_rotate_a(a, pack);
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
		printf("swappin\n");
	}
	else if (ft_find_size_a(*a, pivots->value) == 3)
	{
		ft_swap_three(a, b, pack);
		aptr = *a;
		bptr = *b;
		printf("swappin three\n");
	}
	ft_del_node(&pivots);
	mem = ft_get_last_value(*b);
	if (ft_find_size(*b, pivots->next->value) > 3)
	{
		pivot = ft_new_pivot(*b, ft_find_next(*b, pivots->next->value));
		while (bptr->value >= pivots->next->value)
		{
			if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
			aptr = *a;
			bptr = *b;
		}
		if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
			if (bptr->value >= pivots->next->value)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
		printf("brekin dis bitch\n");
		pivot = ft_new_pivot(*a, ft_find_next_a(*a, pivots->value));
		printf("%d\n", pivot);
		mem = ft_get_last_value(*a);
		while (aptr->value < pivots->value)
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
			else
				ft_rotate_a(a, pack);
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
		printf("swappin\n");
	}
	else if (ft_find_size_a(*a, pivots->value) == 3)
	{
		ft_swap_three(a, b, pack);
		aptr = *a;
		bptr = *b;
		printf("swappin three\n");
	}
	ft_del_node(&pivots);
	mem = ft_get_last_value(*b);
	if (ft_find_size(*b, pivots->next->value) > 3)
	{
		pivot = ft_new_pivot(*b, ft_find_next(*b, pivots->next->value));
		while (bptr->value >= pivots->next->value)
		{
			if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
			aptr = *a;
			bptr = *b;
		}
		if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
			if (bptr->value >= pivots->next->value)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
		printf("brekin dis bitch\n");
		pivot = ft_new_pivot(*a, ft_find_next_a(*a, pivots->value));
		printf("%d\n", pivot);
		mem = ft_get_last_value(*a);
		while (aptr->value < pivots->value)
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
			else
				ft_rotate_a(a, pack);
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
		printf("swappin\n");
	}
	else if (ft_find_size_a(*a, pivots->value) == 3)
	{
		ft_swap_three(a, b, pack);
		aptr = *a;
		bptr = *b;
		printf("swappin three\n");
	}
	ft_del_node(&pivots);
	mem = ft_get_last_value(*b);
	if (ft_find_size(*b, pivots->next->value) > 3)
	{
		pivot = ft_new_pivot(*b, ft_find_next(*b, pivots->next->value));
		while (bptr->value >= pivots->next->value)
		{
			if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
			aptr = *a;
			bptr = *b;
		}
		if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
			if (bptr->value >= pivots->next->value)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
		printf("brekin dis bitch\n");
		pivot = ft_new_pivot(*a, ft_find_next_a(*a, pivots->value));
		printf("%d\n", pivot);
		mem = ft_get_last_value(*a);
		while (aptr->value < pivots->value)
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
			else
				ft_rotate_a(a, pack);
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
		printf("swappin\n");
	}
	else if (ft_find_size_a(*a, pivots->value) == 3)
	{
		ft_swap_three(a, b, pack);
		aptr = *a;
		bptr = *b;
		printf("swappin three\n");
	}
	ft_del_node(&pivots);
	mem = ft_get_last_value(*b);
	if (ft_find_size(*b, pivots->next->value) > 3)
	{
		pivot = ft_new_pivot(*b, ft_find_next(*b, pivots->next->value));
		while (bptr->value >= pivots->next->value)
		{
			if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
			aptr = *a;
			bptr = *b;
		}
		if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
			if (bptr->value >= pivots->next->value)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
		printf("brekin dis bitch\n");
		pivot = ft_new_pivot(*a, ft_find_next_a(*a, pivots->value));
		printf("%d\n", pivot);
		mem = ft_get_last_value(*a);
		while (aptr->value < pivots->value)
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
			else
				ft_rotate_a(a, pack);
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
		printf("swappin\n");
	}
	else if (ft_find_size_a(*a, pivots->value) == 3)
	{
		ft_swap_three(a, b, pack);
		aptr = *a;
		bptr = *b;
		printf("swappin three\n");
	}
	ft_del_node(&pivots);
	mem = ft_get_last_value(*b);
	if (ft_find_size(*b, pivots->next->value) > 3)
	{
		pivot = ft_new_pivot(*b, ft_find_next(*b, pivots->next->value));
		while (bptr->value >= pivots->next->value)
		{
			if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
			aptr = *a;
			bptr = *b;
		}
		if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
			if (bptr->value >= pivots->next->value)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
		printf("brekin dis bitch\n");
		pivot = ft_new_pivot(*a, ft_find_next_a(*a, pivots->value));
		printf("%d\n", pivot);
		mem = ft_get_last_value(*a);
		while (aptr->value < pivots->value)
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
			else
				ft_rotate_a(a, pack);
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
		printf("swappin\n");
	}
	else if (ft_find_size_a(*a, pivots->value) == 3)
	{
		ft_swap_three(a, b, pack);
		aptr = *a;
		bptr = *b;
		printf("swappin three\n");
	}
	ft_del_node(&pivots);
	mem = ft_get_last_value(*b);
	if (ft_find_size(*b, pivots->next->value) > 3)
	{
		pivot = ft_new_pivot(*b, ft_find_next(*b, pivots->next->value));
		while (bptr->value >= pivots->next->value)
		{
			if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
			aptr = *a;
			bptr = *b;
		}
		if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
			if (bptr->value >= pivots->next->value)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
		printf("brekin dis bitch\n");
		pivot = ft_new_pivot(*a, ft_find_next_a(*a, pivots->value));
		printf("%d\n", pivot);
		mem = ft_get_last_value(*a);
		while (aptr->value < pivots->value)
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
			else
				ft_rotate_a(a, pack);
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
		printf("swappin\n");
	}
	else if (ft_find_size_a(*a, pivots->value) == 3)
	{
		ft_swap_three(a, b, pack);
		aptr = *a;
		bptr = *b;
		printf("swappin three\n");
	}
	ft_del_node(&pivots);
	mem = ft_get_last_value(*b);
	if (ft_find_size(*b, pivots->next->value) > 3)
	{
		pivot = ft_new_pivot(*b, ft_find_next(*b, pivots->next->value));
		while (bptr->value >= pivots->next->value)
		{
			if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
			aptr = *a;
			bptr = *b;
		}
		if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
			if (bptr->value >= pivots->next->value)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
		printf("brekin dis bitch\n");
		pivot = ft_new_pivot(*a, ft_find_next_a(*a, pivots->value));
		printf("%d\n", pivot);
		mem = ft_get_last_value(*a);
		while (aptr->value < pivots->value)
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
			else
				ft_rotate_a(a, pack);
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
		printf("swappin\n");
	}
	else if (ft_find_size_a(*a, pivots->value) == 3)
	{
		ft_swap_three(a, b, pack);
		aptr = *a;
		bptr = *b;
		printf("swappin three\n");
	}
	ft_del_node(&pivots);
	mem = ft_get_last_value(*b);
	if (ft_find_size(*b, pivots->next->value) > 3)
	{
		pivot = ft_new_pivot(*b, ft_find_next(*b, pivots->next->value));
		while (bptr->value >= pivots->next->value)
		{
			if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
			aptr = *a;
			bptr = *b;
		}
		if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
			if (bptr->value >= pivots->next->value)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
		printf("brekin dis bitch\n");
		pivot = ft_new_pivot(*a, ft_find_next_a(*a, pivots->value));
		printf("%d\n", pivot);
		mem = ft_get_last_value(*a);
		while (aptr->value < pivots->value)
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
			else
				ft_rotate_a(a, pack);
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
		printf("swappin\n");
	}
	else if (ft_find_size_a(*a, pivots->value) == 3)
	{
		ft_swap_three(a, b, pack);
		aptr = *a;
		bptr = *b;
		printf("swappin three\n");
	}
	ft_del_node(&pivots);
	mem = ft_get_last_value(*b);
	if (ft_find_size(*b, pivots->next->value) > 3)
	{
		pivot = ft_new_pivot(*b, ft_find_next(*b, pivots->next->value));
		while (bptr->value >= pivots->next->value)
		{
			if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
			aptr = *a;
			bptr = *b;
		}
		if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
			if (bptr->value >= pivots->next->value)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
		printf("brekin dis bitch\n");
		pivot = ft_new_pivot(*a, ft_find_next_a(*a, pivots->value));
		printf("%d\n", pivot);
		mem = ft_get_last_value(*a);
		while (aptr->value < pivots->value)
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
			else
				ft_rotate_a(a, pack);
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
		printf("swappin\n");
	}
	else if (ft_find_size_a(*a, pivots->value) == 3)
	{
		ft_swap_three(a, b, pack);
		aptr = *a;
		bptr = *b;
		printf("swappin three\n");
	}
	ft_del_node(&pivots);
	mem = ft_get_last_value(*b);
	if (ft_find_size(*b, pivots->next->value) > 3)
	{
		pivot = ft_new_pivot(*b, ft_find_next(*b, pivots->next->value));
		while (bptr->value >= pivots->next->value)
		{
			if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
			aptr = *a;
			bptr = *b;
		}
		if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
			if (bptr->value >= pivots->next->value)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
		printf("brekin dis bitch\n");
		pivot = ft_new_pivot(*a, ft_find_next_a(*a, pivots->value));
		printf("%d\n", pivot);
		mem = ft_get_last_value(*a);
		while (aptr->value < pivots->value)
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
			else
				ft_rotate_a(a, pack);
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
		printf("swappin\n");
	}
	else if (ft_find_size_a(*a, pivots->value) == 3)
	{
		ft_swap_three(a, b, pack);
		aptr = *a;
		bptr = *b;
		printf("swappin three\n");
	}
	ft_del_node(&pivots);
	mem = ft_get_last_value(*b);
	if (ft_find_size(*b, pivots->next->value) > 3)
	{
		pivot = ft_new_pivot(*b, ft_find_next(*b, pivots->next->value));
		while (bptr->value >= pivots->next->value)
		{
			if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
			aptr = *a;
			bptr = *b;
		}
		if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
			if (bptr->value >= pivots->next->value)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
		printf("brekin dis bitch\n");
		pivot = ft_new_pivot(*a, ft_find_next_a(*a, pivots->value));
		printf("%d\n", pivot);
		mem = ft_get_last_value(*a);
		while (aptr->value < pivots->value)
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
			else
				ft_rotate_a(a, pack);
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
		printf("swappin\n");
	}
	else if (ft_find_size_a(*a, pivots->value) == 3)
	{
		ft_swap_three(a, b, pack);
		aptr = *a;
		bptr = *b;
		printf("swappin three\n");
	}
	ft_del_node(&pivots);
	mem = ft_get_last_value(*b);
	if (ft_find_size(*b, pivots->next->value) > 3)
	{
		pivot = ft_new_pivot(*b, ft_find_next(*b, pivots->next->value));
		while (bptr->value >= pivots->next->value)
		{
			if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
			aptr = *a;
			bptr = *b;
		}
		if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
			if (bptr->value >= pivots->next->value)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
		printf("brekin dis bitch\n");
		pivot = ft_new_pivot(*a, ft_find_next_a(*a, pivots->value));
		printf("%d\n", pivot);
		mem = ft_get_last_value(*a);
		while (aptr->value < pivots->value)
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
			else
				ft_rotate_a(a, pack);
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
		printf("swappin\n");
	}
	else if (ft_find_size_a(*a, pivots->value) == 3)
	{
		ft_swap_three(a, b, pack);
		aptr = *a;
		bptr = *b;
		printf("swappin three\n");
	}
	ft_del_node(&pivots);
	mem = ft_get_last_value(*b);
	if (ft_find_size(*b, pivots->next->value) > 3)
	{
		pivot = ft_new_pivot(*b, ft_find_next(*b, pivots->next->value));
		while (bptr->value >= pivots->next->value)
		{
			if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
			aptr = *a;
			bptr = *b;
		}
		if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
			if (bptr->value >= pivots->next->value)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
		printf("brekin dis bitch\n");
		pivot = ft_new_pivot(*a, ft_find_next_a(*a, pivots->value));
		printf("%d\n", pivot);
		mem = ft_get_last_value(*a);
		while (aptr->value < pivots->value)
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
			else
				ft_rotate_a(a, pack);
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
		printf("swappin\n");
	}
	else if (ft_find_size_a(*a, pivots->value) == 3)
	{
		ft_swap_three(a, b, pack);
		aptr = *a;
		bptr = *b;
		printf("swappin three\n");
	}
	ft_del_node(&pivots);
	mem = ft_get_last_value(*b);
	if (ft_find_size(*b, pivots->next->value) > 3)
	{
		pivot = ft_new_pivot(*b, ft_find_next(*b, pivots->next->value));
		while (bptr->value >= pivots->next->value)
		{
			if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
			aptr = *a;
			bptr = *b;
		}
		if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
			if (bptr->value >= pivots->next->value)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
		printf("brekin dis bitch\n");
		pivot = ft_new_pivot(*a, ft_find_next_a(*a, pivots->value));
		printf("%d\n", pivot);
		mem = ft_get_last_value(*a);
		while (aptr->value <= pivots->value)
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
			else
				ft_rotate_a(a, pack);
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
		printf("swappin\n");
	}
	else if (ft_find_size_a(*a, pivots->value) == 3)
	{
		ft_swap_three(a, b, pack);
		aptr = *a;
		bptr = *b;
		printf("swappin three\n");
	}
	ft_del_node(&pivots);
	mem = ft_get_last_value(*b);
	if (ft_find_size(*b, pivots->next->value) > 3)
	{
		pivot = ft_new_pivot(*b, ft_find_next(*b, pivots->next->value));
		while (bptr->value >= pivots->next->value)
		{
			if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
			aptr = *a;
			bptr = *b;
		}
		if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
			if (bptr->value >= pivots->next->value)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
		printf("brekin dis bitch\n");
		pivot = ft_new_pivot(*a, ft_find_next_a(*a, pivots->value));
		printf("%d\n", pivot);
		mem = ft_get_last_value(*a);
		while (aptr->value <= pivots->value)
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
			else
				ft_rotate_a(a, pack);
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
		printf("swappin\n");
	}
	else if (ft_find_size_a(*a, pivots->value) == 3)
	{
		ft_swap_three(a, b, pack);
		aptr = *a;
		bptr = *b;
		printf("swappin three\n");
	}
	ft_del_node(&pivots);
	mem = ft_get_last_value(*b);
	if (ft_find_size(*b, pivots->next->value) > 3)
	{
		pivot = ft_new_pivot(*b, ft_find_next(*b, pivots->next->value));
		while (bptr->value >= pivots->next->value)
		{
			if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
			aptr = *a;
			bptr = *b;
		}
		if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
			if (bptr->value >= pivots->next->value)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
		printf("brekin dis bitch\n");
		pivot = ft_new_pivot(*a, ft_find_next_a(*a, pivots->value));
		printf("%d\n", pivot);
		mem = ft_get_last_value(*a);
		while (aptr->value <= pivots->value)
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
			else
				ft_rotate_a(a, pack);
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
		printf("swappin\n");
	}
	else if (ft_find_size_a(*a, pivots->value) == 3)
	{
		ft_swap_three(a, b, pack);
		aptr = *a;
		bptr = *b;
		printf("swappin three\n");
	}
	ft_del_node(&pivots);
	mem = ft_get_last_value(*b);
	if (ft_find_size(*b, pivots->next->value) > 3)
	{
		pivot = ft_new_pivot(*b, ft_find_next(*b, pivots->next->value));
		while (bptr->value >= pivots->next->value)
		{
			if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
			aptr = *a;
			bptr = *b;
		}
		if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
			if (bptr->value >= pivots->next->value)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
		printf("brekin dis bitch\n");
		pivot = ft_new_pivot(*a, ft_find_next_a(*a, pivots->value));
		printf("%d\n", pivot);
		mem = ft_get_last_value(*a);
		while (aptr->value <= pivots->value)
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
			else
				ft_rotate_a(a, pack);
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
		printf("swappin\n");
	}
	else if (ft_find_size_a(*a, pivots->value) == 3)
	{
		ft_swap_three(a, b, pack);
		aptr = *a;
		bptr = *b;
		printf("swappin three\n");
	}
	ft_del_node(&pivots);
	mem = ft_get_last_value(*b);
	if (ft_find_size(*b, pivots->next->value) > 3)
	{
		pivot = ft_new_pivot(*b, ft_find_next(*b, pivots->next->value));
		while (bptr->value >= pivots->next->value)
		{
			if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
			aptr = *a;
			bptr = *b;
		}
		if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
			if (bptr->value >= pivots->next->value)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
		printf("brekin dis bitch\n");
		pivot = ft_new_pivot(*a, ft_find_next_a(*a, pivots->value));
		printf("%d\n", pivot);
		mem = ft_get_last_value(*a);
		while (aptr->value <= pivots->value)
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
			else
				ft_rotate_a(a, pack);
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
		printf("swappin\n");
	}
	else if (ft_find_size_a(*a, pivots->value) == 3)
	{
		ft_swap_three(a, b, pack);
		aptr = *a;
		bptr = *b;
		printf("swappin three\n");
	}
	ft_del_node(&pivots);
	mem = ft_get_last_value(*b);
	if (ft_find_size(*b, pivots->next->value) > 3)
	{
		pivot = ft_new_pivot(*b, ft_find_next(*b, pivots->next->value));
		while (bptr->value >= pivots->next->value)
		{
			if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
			aptr = *a;
			bptr = *b;
		}
		if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
			if (bptr->value >= pivots->next->value)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
		printf("brekin dis bitch\n");
		pivot = ft_new_pivot(*a, ft_find_next_a(*a, pivots->value));
		printf("%d\n", pivot);
		mem = ft_get_last_value(*a);
		while (aptr->value <= pivots->value)
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
			else
				ft_rotate_a(a, pack);
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
		printf("swappin\n");
	}
	else if (ft_find_size_a(*a, pivots->value) == 3)
	{
		ft_swap_three(a, b, pack);
		aptr = *a;
		bptr = *b;
		printf("swappin three\n");
	}
	ft_del_node(&pivots);
	mem = ft_get_last_value(*b);
	if (ft_find_size(*b, pivots->next->value) > 3)
	{
		pivot = ft_new_pivot(*b, ft_find_next(*b, pivots->next->value));
		while (bptr->value >= pivots->next->value)
		{
			if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
			aptr = *a;
			bptr = *b;
		}
		if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
			if (bptr->value >= pivots->next->value)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
		printf("brekin dis bitch\n");
		pivot = ft_new_pivot(*a, ft_find_next_a(*a, pivots->value));
		printf("%d\n", pivot);
		mem = ft_get_last_value(*a);
		while (aptr->value <= pivots->value)
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
			else
				ft_rotate_a(a, pack);
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
		printf("swappin\n");
	}
	else if (ft_find_size_a(*a, pivots->value) == 3)
	{
		ft_swap_three(a, b, pack);
		aptr = *a;
		bptr = *b;
		printf("swappin three\n");
	}
	ft_del_node(&pivots);
	mem = ft_get_last_value(*b);
	if (ft_find_size(*b, pivots->next->value) > 3)
	{
		pivot = ft_new_pivot(*b, ft_find_next(*b, pivots->next->value));
		while (bptr->value >= pivots->next->value)
		{
			if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
			aptr = *a;
			bptr = *b;
		}
		if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
			if (bptr->value >= pivots->next->value)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
		printf("brekin dis bitch\n");
		pivot = ft_new_pivot(*a, ft_find_next_a(*a, pivots->value));
		printf("%d\n", pivot);
		mem = ft_get_last_value(*a);
		while (aptr->value <= pivots->value)
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
			else
				ft_rotate_a(a, pack);
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
		printf("swappin\n");
	}
	else if (ft_find_size_a(*a, pivots->value) == 3)
	{
		ft_swap_three(a, b, pack);
		aptr = *a;
		bptr = *b;
		printf("swappin three\n");
	}
	ft_del_node(&pivots);
	mem = ft_get_last_value(*b);
	if (ft_find_size(*b, pivots->next->value) > 3)
	{
		pivot = ft_new_pivot(*b, ft_find_next(*b, pivots->next->value));
		while (bptr->value >= pivots->next->value)
		{
			if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
			aptr = *a;
			bptr = *b;
		}
		if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
			if (bptr->value >= pivots->next->value)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
		printf("brekin dis bitch\n");
		pivot = ft_new_pivot(*a, ft_find_next_a(*a, pivots->value));
		printf("%d\n", pivot);
		mem = ft_get_last_value(*a);
		while (aptr->value <= pivots->value)
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
			else
				ft_rotate_a(a, pack);
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
		printf("swappin\n");
	}
	else if (ft_find_size_a(*a, pivots->value) == 3)
	{
		ft_swap_three(a, b, pack);
		aptr = *a;
		bptr = *b;
		printf("swappin three\n");
	}
	ft_del_node(&pivots);
	mem = ft_get_last_value(*b);
	if (ft_find_size(*b, pivots->next->value) > 3)
	{
		pivot = ft_new_pivot(*b, ft_find_next(*b, pivots->next->value));
		while (bptr->value >= pivots->next->value)
		{
			if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
			aptr = *a;
			bptr = *b;
		}
		if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
			if (bptr->value >= pivots->next->value)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
		printf("brekin dis bitch\n");
		pivot = ft_new_pivot(*a, ft_find_next_a(*a, pivots->value));
		printf("%d\n", pivot);
		mem = ft_get_last_value(*a);
		while (aptr->value <= pivots->value)
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
			else
				ft_rotate_a(a, pack);
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
		printf("swappin\n");
	}
	else if (ft_find_size_a(*a, pivots->value) == 3)
	{
		ft_swap_three(a, b, pack);
		aptr = *a;
		bptr = *b;
		printf("swappin three\n");
	}
	ft_del_node(&pivots);
	mem = ft_get_last_value(*b);
	if (ft_find_size(*b, pivots->next->value) > 3)
	{
		pivot = ft_new_pivot(*b, ft_find_next(*b, pivots->next->value));
		while (bptr->value >= pivots->next->value)
		{
			if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
			aptr = *a;
			bptr = *b;
		}
		if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
			if (bptr->value >= pivots->next->value)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
		printf("brekin dis bitch\n");
		pivot = ft_new_pivot(*a, ft_find_next_a(*a, pivots->value));
		printf("%d\n", pivot);
		mem = ft_get_last_value(*a);
		while (aptr->value <= pivots->value)
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
			else
				ft_rotate_a(a, pack);
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
		printf("swappin\n");
	}
	else if (ft_find_size_a(*a, pivots->value) == 3)
	{
		ft_swap_three(a, b, pack);
		aptr = *a;
		bptr = *b;
		printf("swappin three\n");
	}
	ft_del_node(&pivots);
	mem = ft_get_last_value(*b);
	if (ft_find_size(*b, pivots->next->value) > 3)
	{
		pivot = ft_new_pivot(*b, ft_find_next(*b, pivots->next->value));
		while (bptr->value >= pivots->next->value)
		{
			if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
			aptr = *a;
			bptr = *b;
		}
		if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
			if (bptr->value >= pivots->next->value)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
		printf("brekin dis bitch\n");
		pivot = ft_new_pivot(*a, ft_find_next_a(*a, pivots->value));
		printf("%d\n", pivot);
		mem = ft_get_last_value(*a);
		while (aptr->value <= pivots->value)
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
			else
				ft_rotate_a(a, pack);
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
		printf("swappin\n");
	}
	else if (ft_find_size_a(*a, pivots->value) == 3)
	{
		ft_swap_three(a, b, pack);
		aptr = *a;
		bptr = *b;
		printf("swappin three\n");
	}
	ft_del_node(&pivots);
	mem = ft_get_last_value(*b);
	if (ft_find_size(*b, pivots->next->value) > 3)
	{
		pivot = ft_new_pivot(*b, ft_find_next(*b, pivots->next->value));
		while (bptr->value >= pivots->next->value)
		{
			if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
			aptr = *a;
			bptr = *b;
		}
		if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
			if (bptr->value >= pivots->next->value)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
		printf("brekin dis bitch\n");
		pivot = ft_new_pivot(*a, ft_find_next_a(*a, pivots->value));
		printf("%d\n", pivot);
		mem = ft_get_last_value(*a);
		while (aptr->value <= pivots->value)
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
			else
				ft_rotate_a(a, pack);
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
		printf("swappin\n");
	}
	else if (ft_find_size_a(*a, pivots->value) == 3)
	{
		ft_swap_three(a, b, pack);
		aptr = *a;
		bptr = *b;
		printf("swappin three\n");
	}
	ft_del_node(&pivots);
	mem = ft_get_last_value(*b);
	if (ft_find_size(*b, pivots->next->value) > 3)
	{
		pivot = ft_new_pivot(*b, ft_find_next(*b, pivots->next->value));
		while (bptr->value >= pivots->next->value)
		{
			if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
			aptr = *a;
			bptr = *b;
		}
		if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
			if (bptr->value >= pivots->next->value)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
		printf("brekin dis bitch\n");
		pivot = ft_new_pivot(*a, ft_find_next_a(*a, pivots->value));
		printf("%d\n", pivot);
		mem = ft_get_last_value(*a);
		while (aptr->value <= pivots->value)
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
			else
				ft_rotate_a(a, pack);
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
		printf("swappin\n");
	}
	else if (ft_find_size_a(*a, pivots->value) == 3)
	{
		ft_swap_three(a, b, pack);
		aptr = *a;
		bptr = *b;
		printf("swappin three\n");
	}
	ft_del_node(&pivots);
	mem = ft_get_last_value(*b);
	if (ft_find_size(*b, pivots->next->value) > 3)
	{
		pivot = ft_new_pivot(*b, ft_find_next(*b, pivots->next->value));
		while (bptr->value >= pivots->next->value)
		{
			if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
			aptr = *a;
			bptr = *b;
		}
		if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
			if (bptr->value >= pivots->next->value)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
		printf("brekin dis bitch\n");
		pivot = ft_new_pivot(*a, ft_find_next_a(*a, pivots->value));
		printf("%d\n", pivot);
		mem = ft_get_last_value(*a);
		while (aptr->value <= pivots->value)
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
			else
				ft_rotate_a(a, pack);
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
		printf("swappin\n");
	}
	else if (ft_find_size_a(*a, pivots->value) == 3)
	{
		ft_swap_three(a, b, pack);
		aptr = *a;
		bptr = *b;
		printf("swappin three\n");
	}
	ft_del_node(&pivots);
	mem = ft_get_last_value(*b);
	if (ft_find_size(*b, pivots->next->value) > 3)
	{
		pivot = ft_new_pivot(*b, ft_find_next(*b, pivots->next->value));
		while (bptr->value >= pivots->next->value)
		{
			if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
			aptr = *a;
			bptr = *b;
		}
		if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
			if (bptr->value >= pivots->next->value)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
		printf("brekin dis bitch\n");
		pivot = ft_new_pivot(*a, ft_find_next_a(*a, pivots->value));
		printf("%d\n", pivot);
		mem = ft_get_last_value(*a);
		while (aptr->value <= pivots->value)
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
			else
				ft_rotate_a(a, pack);
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
		printf("swappin\n");
	}
	else if (ft_find_size_a(*a, pivots->value) == 3)
	{
		ft_swap_three(a, b, pack);
		aptr = *a;
		bptr = *b;
		printf("swappin three\n");
	}
	ft_del_node(&pivots);
	mem = ft_get_last_value(*b);
	if (ft_find_size(*b, pivots->next->value) > 3)
	{
		pivot = ft_new_pivot(*b, ft_find_next(*b, pivots->next->value));
		while (bptr->value >= pivots->next->value)
		{
			if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
			aptr = *a;
			bptr = *b;
		}
		if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
			if (bptr->value >= pivots->next->value)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
		printf("brekin dis bitch\n");
		pivot = ft_new_pivot(*a, ft_find_next_a(*a, pivots->value));
		printf("%d\n", pivot);
		mem = ft_get_last_value(*a);
		while (aptr->value <= pivots->value)
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
			else
				ft_rotate_a(a, pack);
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
		printf("swappin\n");
	}
	else if (ft_find_size_a(*a, pivots->value) == 3)
	{
		ft_swap_three(a, b, pack);
		aptr = *a;
		bptr = *b;
		printf("swappin three\n");
	}
	ft_del_node(&pivots);
	while (ft_get_size(*b) > 252)
	{
		mem = ft_get_last_value(*b);
	if (ft_find_size(*b, pivots->next->value) > 3)
	{
		pivot = ft_new_pivot(*b, ft_find_next(*b, pivots->next->value));
		while (bptr->value >= pivots->next->value)
		{
			if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
			aptr = *a;
			bptr = *b;
		}
		if (bptr->value >= pivot)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
			if (bptr->value >= pivots->next->value)
				ft_push_from_b_to_a(a, b, pack);
			else
				ft_rotate_b(b, pack);
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
		printf("brekin dis bitch\n");
		pivot = ft_new_pivot(*a, ft_find_next_a(*a, pivots->value));
		printf("%d\n", pivot);
		mem = ft_get_last_value(*a);
		while (aptr->value <= pivots->value)
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
			else
				ft_rotate_a(a, pack);
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
		printf("swappin\n");
	}
	else if (ft_find_size_a(*a, pivots->value) == 3)
	{
		ft_swap_three(a, b, pack);
		aptr = *a;
		bptr = *b;
		printf("swappin three\n");
	}
	ft_del_node(&pivots);
	}
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
	ft_print_stacks(*a, *b, "stacks", *pack);
	ft_print_stacks(pivots, 0, "pivots", *pack);
}