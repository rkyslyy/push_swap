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

void	ft_do_shit(t_stack **a, t_stack **b, t_pack *pack, int *pivot, int *tail)
{
	t_stack *aptr;
	t_stack *bptr;

	aptr = *a;
	bptr = *b;
	*pivot = ft_new_pivot(*a, *tail);
	//printf("dis out pivot - %d\n", *pivot);
	while (aptr->value != *tail)
	{
		if (aptr->value >= *pivot)
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
	if (aptr->value >= *pivot)
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
	//ft_print_stacks(*a, *b, "LOL", *pack);
	if (ft_pick_rotate(bptr, ft_get_min(bptr)) == 1)
		while (ft_get_last_value(bptr) != ft_get_min(bptr))
		{
			ft_rotate_b(b, pack);
			bptr = *b;
		}
	else
		while (ft_get_last_value(bptr) != ft_get_min(bptr))
		{
			ft_reverse_rotate_b(b, pack);
			bptr = *b;
		}
	*tail = bptr->value;
	while (bptr != NULL)
	{
		ft_push_from_b_to_a(a, b, pack);
		aptr = *a;
		bptr = *b;
	}
}

void	ft_do_shit_short(t_stack **a, t_stack **b, t_pack *pack, int *pivot, int *tail)
{
	t_stack *aptr;
	t_stack *bptr;

	aptr = *a;
	bptr = *b;
	*pivot = ft_new_pivot(*a, *tail);
	while (aptr->value != *tail)
	{
		if (aptr->value >= *pivot)
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
	if (ft_pick_rotate(bptr, ft_get_min(bptr)) == 1)
		while (ft_get_last_value(bptr) != ft_get_min(bptr))
		{
			ft_rotate_b(b, pack);
			bptr = *b;
		}
	else
		while (ft_get_last_value(bptr) != ft_get_min(bptr))
		{
			ft_reverse_rotate_b(b, pack);
			bptr = *b;
		}
	while (bptr != NULL)
	{
		ft_push_from_b_to_a(a, b, pack);
		aptr = *a;
		bptr = *b;
	}
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

int		ft_length(t_stack *a, int tail)
{
	t_stack *ptr;
	int		ret;

	ptr = a;
	ret = 0;
	while (ptr->value != tail)
	{
		ret += 1;
		ptr = ptr->next;
	}
	return (ret);
}

int		ft_find_size(t_stack *b, int pivot)
{
	int ret;
	t_stack *ptr;

	ret = 0;
	ptr = b;
	while (ptr->value >= pivot)
	{
		ret += 1;
		ptr = ptr->next;
	}
	return (ret);
}

void	ft_fast_af_boi(t_stack **a, t_stack **b, t_pack *pack)
{
	t_stack	*aptr;
	t_stack	*bptr;
	int		pivot;
	int		mem;
	int		mina;
	t_stack	*pivots;

	aptr = *a;
	bptr = *b;
	pivots = NULL;
	ft_add_node(ft_create_node(ft_get_min(*a)), &pivots);
	while (ft_get_size(*a) > 3)
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
//	ft_print_stacks(pivots, 0, "pivots", *pack);
	ft_swap_rotate(a, pack);
	ft_del_node(&pivots);
	mina = ft_get_min(*a);
	aptr = *a;
	while (*a)
		ft_push_from_a_to_b(a, b, pack);
	while (ft_get_last_value(*b) != mina)
		ft_rotate_b(b, pack);
	bptr = *b;
	aptr = *a;
	// ft_del_node(&pivots);
	while (pivots)
	{
		while (bptr->value >= pivots->value && bptr->value != ft_get_max(bptr))
		{
			ft_push_from_b_to_a(a, b, pack);
			aptr = *a;
			bptr = *b;
		}
		while (ft_get_size(*a) > 3)
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
		ft_swap_rotate(a, pack);
		ft_del_node(&pivots);
		mina = ft_get_min(*a);
		aptr = *a;
		while (*a)
			ft_push_from_a_to_b(a, b, pack);
		while (ft_get_last_value(*b) != mina)
			ft_rotate_b(b, pack);
		bptr = *b;
		aptr = *a;
	}
	while (*b)
		ft_push_from_b_to_a(a, b, pack);
	// while (pivots != NULL)
	// {
	// 	while (bptr->value >= pivots->value)
	// {
	// 	ft_push_from_b_to_a(a, b, pack);
	// 	aptr = *a;
	// 	bptr = *b;
	// }
	// //ft_print_stacks(*a, *b, "stacks", *pack);
	// while (ft_get_size(*a) > 3)
	// {
	// 	pivot = ft_get_pivot(*a, ft_get_size(*a) / 2);
	// 	mem = ft_get_last_value(*a);
	// 	while (aptr->value != mem)
	// 	{
	// 		if (aptr->value <= pivot)
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
	// 	if (aptr->value <= pivot)
	// 	{
	// 		ft_push_from_b_to_a(a, b, pack);
	// 		aptr = *a;
	// 		bptr = *b;
	// 	}
	// 	else
	// 	{
	// 		ft_rotate_a(a, pack);
	// 		aptr = *a;
	// 	}
	// 	ft_add_node(ft_create_node(ft_get_min(*a)), &pivots);
	// }
	// ft_swap_rotate(a, pack);
	// //ft_print_stacks(*a, *b, "stacks", *pack);
	// mina = ft_get_min(*a);
	// aptr = *a;
	// while (aptr)
	// {
	// 	ft_push_from_a_to_b(a, b, pack);
	// 	aptr = *a;
	// }
	// while (ft_get_last_value(*b) != mina)
	// 	ft_rotate_b(b, pack);
	// aptr = *a;
	// bptr = *b;
	// ft_del_node(&pivots);
	// ft_del_node(&pivots);
	// }
	ft_print_stacks(*a, *b, "stacks", *pack);
	ft_print_stacks(pivots, 0, "pivots", *pack);
}