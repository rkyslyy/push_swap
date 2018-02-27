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

void	ft_fast_af_boi(t_stack **a, t_stack **b, t_pack *pack)
{
	t_stack	*aptr;
	t_stack	*bptr;
	int		pivot;
	int		tail;
	int		mina;;
	t_stack	*pivots;

	aptr = *a;
	bptr = *b;
	pivot = ft_get_pivot(*a, ft_get_size(*a) / 2);
	pivots = ft_create_node(pivot);
	tail = ft_get_last_value(aptr);
	while (aptr->value != tail)
	{
		if (aptr->value >= 100)
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
	if (aptr->value >= 100)
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
	mina = ft_get_max(aptr);
	// if (ft_pick_rotate(bptr, ft_get_min(bptr)) == 1)
	// 	while (ft_get_last_value(bptr) != ft_get_min(bptr))
	// 	{
	// 		ft_rotate_b(b, pack);
	// 		bptr = *b;
	// 	}
	// else
	// 	while (ft_get_last_value(bptr) != ft_get_min(bptr))
	// 	{
	// 		ft_reverse_rotate_b(b, pack);
	// 		bptr = *b;
	// 	}
	ft_quick_sort(a, b, pack);
	ft_swap_rotate(a, pack);
	printf("%d\n", mina);
	// while (aptr != NULL)
	// {
	// 	ft_push_from_a_to_b(a, b, pack);
	// 	aptr = *a;
	// 	bptr = *b;
	// }
	// while (ft_get_min(bptr) <= mina)
	// {
	// 	if (bptr->value <= mina)
	// 		ft_push_from_b_to_a(a, b, pack);
	// 	else
	// 		ft_rotate_b(b, pack);
	// 	aptr = *a;
	// 	bptr = *b;
	// }
	// ft_quick_sort(a, b, pack);
	// tail = bptr->value;
	// kray = aptr->value;
	// while (bptr != NULL)
	// {
	// 	ft_push_from_b_to_a(a, b, pack);
	// 	aptr = *a;
	// 	bptr = *b;
	// }
	// while (!(aptr->next->next->value == kray && aptr->next->value == ft_get_max(aptr)) && aptr->next->value != kray)
	// {
	// 	ft_do_shit(a, b, pack, &pivot, &tail);
	// 	ft_add_node(ft_create_node(pivot), &pivots);
	// 	aptr = *a;
	// 	bptr = *b;
	// }
	// //ft_print_stacks(*a, *b, "stacks", *pack);
	// tail = pivots->value;
	// kray = pivots->next->value;
	// while (aptr->value != ft_get_last_value(pivots))
	// {
	// 	ft_rotate_a(a, pack);
	// 	aptr = *a;
	// }
	// printf("_______________\n");
	// while (aptr != NULL)
	// {
	// 	ft_deal_with_b(b, a, pack);
	// 	aptr = *a;
	// 	bptr = *b;
	// }
	// while (pivots->next != NULL)
	// {
	// 	while (pivots->next && ft_is_part_sorted(aptr, tail))
	// 	{
	// 		printf("from %d to %d sorted\n", kray, tail);
	// 		ft_del_node(&pivots);
	// 		tail = pivots->value;
	// 		if (pivots->next != NULL)
	// 		{
	// 			kray = pivots->next->value;
	// 			while (aptr->value != kray)
	// 			{
	// 				ft_reverse_rotate_a(a, pack);
	// 				aptr = *a;
	// 			}
	// 		}
	// 	}
	// 	printf("from %d to %d not sorted\n", kray, tail);
	// 	if (ft_length(aptr, tail) == 3)
	// 	{
	// 		ft_rotate_a(a, pack);
	// 		ft_swap_a(a, pack);
	// 		ft_reverse_rotate_a(a, pack);
	// 		aptr = *a;
	// 	}
	// 	// else if (ft_length(aptr, tail) <= 30)
	// 	// {
	// 	// 	ft_print_stacks(aptr, bptr, "stacks", *pack);
	// 	// 	while (aptr->value != tail)
	// 	// 	{
	// 	// 		ft_deal_with_b(b, a, pack);
	// 	// 		aptr = *a;
	// 	// 		bptr = *b;
	// 	// 	}
	// 	// 	while (bptr != NULL)
	// 	// 	{
	// 	// 		ft_push_from_b_to_a(a, b, pack);
	// 	// 		aptr = *a;
	// 	// 		bptr = *b;
	// 	// 	}
	// 	// }
	// 	else
	// 	{
	// 		if (pivots->next != NULL)
	// 		{
	// 			ft_do_shit_short(a, b, pack, &pivot, &tail);
	// 			aptr = *a;
	// 			bptr = *b;
	// 			ft_add_next(ft_create_node(pivot), &pivots);
	// 			kray = pivots->next->value;
	// 		}
	// 	}
	// }
	// while (ft_is_part_sorted(aptr, tail))
	// {
	// 	printf("from %d to %d sorted\n", kray, tail);
	// 	ft_del_node(&pivots);
	// 	tail = pivots->value;
	// 	kray = pivots->next->value;
	// 	while (aptr->value != kray)
	// 	{
	// 		ft_reverse_rotate_a(a, pack);
	// 		aptr = *a;
	// 	}
	// }
	// printf("from %d to %d not sorted\n", kray, tail);
	// ft_print_stacks(*a, *b, "stacks", *pack);
	// ft_do_shit_short(a, b, pack, &pivot, &tail);
	// aptr = *a;
	// bptr = *b;
	// ft_add_next(ft_create_node(pivot), &pivots);
	// kray = pivots->next->value;
	// ft_print_stacks(*a, *b, "LOL", *pack);
	// while (ft_is_part_sorted(aptr, tail))
	// {
	// 	printf("from %d to %d sorted\n", kray, tail);
	// 	ft_del_node(&pivots);
	// 	tail = pivots->value;
	// 	kray = pivots->next->value;
	// 	while (aptr->value != kray)
	// 	{
	// 		ft_reverse_rotate_a(a, pack);
	// 		aptr = *a;
	// 	}
	// }
	// printf("from %d to %d not sorted\n", kray, tail);
	// ft_print_stacks(*a, *b, "stacks", *pack);
	// ft_do_shit_short(a, b, pack, &pivot, &tail);
	// aptr = *a;
	// bptr = *b;
	// ft_add_next(ft_create_node(pivot), &pivots);
	// tail = pivots->value;
	// while (ft_is_part_sorted(aptr, tail))
	// {
	// 	printf("from %d to %d sorted\n", kray, tail);
	// 	ft_del_node(&pivots);
	// 	tail = pivots->value;
	// 	kray = pivots->next->value;
	// 	while (aptr->value != kray)
	// 	{
	// 		ft_reverse_rotate_a(a, pack);
	// 		aptr = *a;
	// 	}
	// }
	// ft_do_shit_short(a, b, pack, &pivot, &tail);
	// aptr = *a;
	// bptr = *b;
	// ft_add_next(ft_create_node(pivot), &pivots);
	// kray = pivots->next->value;
	// while (ft_is_part_sorted(aptr, tail))
	// {
	// 	printf("from %d to %d sorted\n", kray, tail);
	// 	ft_print_stacks(*a, *b, "LOL", *pack);
	// 	ft_del_node(&pivots);
	// 	tail = pivots->value;
	// 	kray = pivots->next->value;
	// 	while (aptr->value != kray)
	// 	{
	// 		ft_reverse_rotate_a(a, pack);
	// 		aptr = *a;
	// 	}
	// }
	// printf("from %d to %d not sorted\n", kray, tail);
	// ft_print_stacks(*a, *b, "stacks", *pack);
	// ft_do_shit_short(a, b, pack, &pivot, &tail);
	// aptr = *a;
	// bptr = *b;
	// ft_add_next(ft_create_node(pivot), &pivots);
	// kray = pivots->next->value;
	// while (ft_is_part_sorted(aptr, tail))
	// {
	// 	printf("from %d to %d sorted\n", kray, tail);
	// 	ft_print_stacks(*a, *b, "LOL", *pack);
	// 	ft_del_node(&pivots);
	// 	tail = pivots->value;
	// 	kray = pivots->next->value;
	// 	while (aptr->value != kray)
	// 	{
	// 		ft_reverse_rotate_a(a, pack);
	// 		aptr = *a;
	// 	}
	// }
	// printf("from %d to %d not sorted\n", kray, tail);
	ft_print_stacks(*a, *b, "stacks", *pack);
}