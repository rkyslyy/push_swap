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

static void ft_set_pivot(t_stack *a, int *pivot)
{
	if (ft_get_size(a) <= 100)
		*pivot = ft_get_pivot(a, ft_get_size(a) / 3);
	else if (ft_get_size(a) <= 250)
		*pivot = ft_get_pivot(a, ft_get_size(a) / 4);
	else
		*pivot = ft_get_pivot(a, ft_get_size(a) / 8);
}

static void	ft_deal_with_b(t_stack **b, t_stack **a, int *total)
{
	t_stack *bptr;
	t_stack *aptr;

	bptr = *b;
	aptr = *a;
	if (bptr != NULL && ft_pick_rotate(bptr, ft_get_biggest(bptr, aptr->value)) == 1)
		while (bptr->value != ft_get_biggest(bptr, aptr->value))
		{
			ft_rotate_b(b, total);
			bptr = *b;
		}
	else
		while (bptr != NULL && bptr->value != ft_get_biggest(bptr, aptr->value))
		{
			ft_reverse_rotate_b(b, total);
			bptr = *b;
		}
	ft_push_from_a_to_b(a, b, total);
}

static void	ft_final(t_stack **a, t_stack **b, int *total)
{
	t_stack *aptr;
	t_stack *bptr;

	aptr = *a;
	bptr = *b;
	while (aptr->next != NULL && aptr->value != ft_get_min(aptr))
	{
		ft_rotate(a);
		aptr = *a;
	}
	while (bptr != NULL)
	{
		ft_push_from_b_to_a(a, b, total);
		bptr = *b;
	}
}

int				main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		total;
	int		add;
	char	**nums;
	int		pivot;
	int		mem;

	if (argc != 2)
		return (1);
	a = NULL;
	b = NULL;
	total = 0;
	nums = ft_strsplit(argv[1], ' ');
	add = 0;
	while (nums[add] != 0)
		add += 1;
	add -= 1;
	while (add >= 0)
	{
		ft_add_node(ft_create_node(ft_atoi(nums[add])), &a);
		add -= 1;
	}
	if (ft_is_sorted(a) == 1)
		printf("sorted\n");
	else
	{
		while (a != NULL && !ft_is_sorted(a))
		{
			ft_set_pivot(a, &pivot);
			mem = a->value;
			ft_rotate_a(&a, &total);
			while (a->value != mem)
			{
				if (a->value <= pivot)
					ft_deal_with_b(&b, &a, &total);
				else
				{
					if (b != NULL && ft_scout(a, mem, pivot) && ft_pick_rotate(b, ft_get_biggest(b, ft_get_next(a, mem, pivot))) == 1 && b->value != ft_get_biggest(b, ft_get_next(a, mem, pivot)))
						ft_rotate_both(&a, &b, &total);
					else
						ft_rotate_a(&a, &total);
				}
			}
			if (a->value <= pivot)
					ft_deal_with_b(&b, &a, &total);
			if (ft_pick_rotate(b, ft_get_max(b)) == 1)
				while (b->value != ft_get_max(b))
					ft_rotate_b(&b, &total);
			else
				while (b->value != ft_get_max(b))
					ft_reverse_rotate_b(&b, &total);
		}
		ft_final(&a, &b, &total);
		ft_print_stacks(a, b);
		printf("\nTotal amount of operations: %d\n", total);
	}
	return (0);
}
