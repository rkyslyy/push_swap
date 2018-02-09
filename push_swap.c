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
#include "./libft/libft.h"

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
			if (ft_get_size(a) <= 100)
				pivot = ft_get_pivot(a, ft_get_size(a) / 3);
			else if (ft_get_size(a) <= 250)
				pivot = ft_get_pivot(a, ft_get_size(a) / 4);
			else
				pivot = ft_get_pivot(a, ft_get_size(a) / 8);
			mem = a->value;
			ft_rotate(&a);
			printf("ra\n");
			total += 1;
			while (a->value != mem)
			{
				if (a->value <= pivot)
				{
					if (b != NULL && ft_pick_rotate(b, ft_get_biggest(b, a->value)) == 1)
						while (b->value != ft_get_biggest(b, a->value))
						{
							ft_rotate(&b);
							total += 1;
							printf("rb\n");
						}
					else
						while (b != NULL && b->value != ft_get_biggest(b, a->value))
						{
							ft_reverse_rotate(&b);
							total += 1;
							printf("rrb\n");
						}
					ft_push_from_to(&a, &b);
					printf("pb\n");
					total += 1;
				}
				else
				{
					if (b != NULL && ft_scout(a, mem, pivot) && ft_pick_rotate(b, ft_get_biggest(b, ft_get_next(a, mem, pivot))) == 1 && b->value != ft_get_biggest(b, ft_get_next(a, mem, pivot)))
					{
						ft_rotate(&a);
						ft_rotate(&b);
						printf("rr\n");
						total += 1;
					}
					else
					{
						total += 1;
						printf("ra\n");
						ft_rotate(&a);
					}
				}
			}
			if (a->value <= pivot)
				{
					if (b != NULL && ft_pick_rotate(b, ft_get_biggest(b, a->value)) == 1)
						while (b->value != ft_get_biggest(b, a->value))
						{
							ft_rotate(&b);
							total += 1;
							printf("rb\n");
						}
					else
						while (b != NULL && b->value != ft_get_biggest(b, a->value))
						{
							ft_reverse_rotate(&b);
							total += 1;
							printf("rrb\n");
						}
					ft_push_from_to(&a, &b);
					printf("pb\n");
					total += 1;
				}
			if (ft_pick_rotate(b, ft_get_max(b)) == 1)
				while (b->value != ft_get_max(b))
				{
					ft_rotate(&b);
					total += 1;
					printf("rb\n");
				}
			else
				while (b->value != ft_get_max(b))
				{
					ft_reverse_rotate(&b);
					total += 1;
					printf("rrb\n");
				}
			ft_print_stacks(a, b);
		}
		while (b != NULL)
		{
			ft_push_from_to(&b, &a);
			total += 1;
			printf("pa\n");
		}
		ft_print_stacks(a, b);
		printf("\nTotal amount of operations: %d\n", total);
	}
	return (0);
}
