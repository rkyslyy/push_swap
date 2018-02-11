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

#include "./swaplib.h"

static void	ft_insert_swap(t_stack **a, t_stack **b, t_pack *pack)
{
	t_stack *aptr;
	t_stack	*bptr;
	int		mem;

	aptr = *a;
	bptr = *b;
	while (!ft_is_sorted(aptr))
	{
		if (ft_find_unsorted(aptr, ft_get_min(aptr), ft_get_max(aptr), &mem) == 1)
			while (aptr->value != mem)
			{
				ft_rotate_a(a, pack);
				aptr = *a;
			}
		else
			while (aptr->value != mem)
			{
				ft_reverse_rotate_a(a, pack);
				aptr = *a;
			}
		if (aptr->value == ft_get_max(aptr))
		{
			if (aptr->next->next->value == ft_get_min(aptr) && aptr->next->value > ft_get_last_value(aptr))
			{
				ft_swap_a(a, pack);
				aptr = *a;
			}
			else
			{
				ft_rotate_a(a, pack);
				aptr = *a;
				while (aptr->value != ft_get_min(aptr))
				{
					ft_push_from_a_to_b(a, b, pack);
					aptr = *a;
					bptr = *b;
				}
			}
		}
		else
		{
			if (aptr->value < aptr->next->next->value && (aptr->next->value > ft_get_last_value(aptr) || (aptr->next->value == ft_get_min(aptr) && ft_get_last_value(aptr) == ft_get_max(aptr))))
			{
				ft_swap_a(a, pack);
				aptr = *a;
			}
			else
			{
				ft_rotate_a(a, pack);
				aptr = *a;
				while (aptr->value < mem)
				{
					ft_push_from_a_to_b(a, b, pack);
					aptr = *a;
					bptr = *b;
				}
			}
		}
		while (bptr != NULL)
		{
			if (ft_pick_rotate(aptr, ft_get_biggest(aptr, bptr->value)) == 1)
				while (ft_get_last_value(aptr) != ft_get_biggest(aptr, bptr->value))
				{
					ft_rotate_a(a, pack);
					aptr = *a;
				}
			else
				while (ft_get_last_value(aptr) != ft_get_biggest(aptr, bptr->value))
				{
					ft_reverse_rotate_a(a, pack);
					aptr = *a;
				}
			ft_push_from_b_to_a(a, b, pack);
			aptr = *a;
			bptr = *b;
		}
	}
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
}

static void ft_swap_rotate(t_stack **a, t_pack *pack)
{
	t_stack *ptr;

	ptr = *a;
	if (ptr->value > ptr->next->value && !ft_is_sorted(ptr))
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

static void	ft_assign(t_stack **a, t_stack **b, t_pack *pack, char **nums)
{
	*a = NULL;
	*b = NULL;
	pack->total = 0;
	pack->add = 0;
	while (nums[pack->add] != 0)
		pack->add += 1;
	pack->add -= 1;
	while (pack->add >= 0)
	{
		ft_add_node(ft_create_node(ft_atoi(nums[pack->add])), a);
		pack->add -= 1;
	}
}

int			main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**nums;
	t_pack	pack;

	if (argc != 2)
		return (1);
	nums = ft_strsplit(argv[1], ' ');
	ft_assign(&a, &b, &pack, nums);
	if (ft_get_size(a) <= 3)
		ft_swap_rotate(&a, &pack);
	else if (ft_get_size(a) <= 10)
		ft_insert_swap(&a, &b, &pack);
	else
		ft_quick_sort(&a, &b, &pack);
	ft_print_stacks(a, b);
	ft_printf("\nTotal amount of operations: %d\n", pack.total);
	return (0);
}
