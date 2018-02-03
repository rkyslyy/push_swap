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

// static int		ft_get_size(t_stack *a)
// {
// 	t_stack *ptr;
// 	int	size;

// 	ptr = a;
// 	size = 0;
// 	while (ptr != NULL)
// 	{
// 		size += 1;
// 		ptr = ptr->next;
// 	}
// 	return (size);
// }

static void		ft_print_stacks(t_stack *a, t_stack *b)
{
	t_stack *ptr;

	ptr = a;
	printf("\na: ");
	while (ptr != NULL)
	{
		printf("%d - ", ptr->value);
		ptr = ptr->next;
	}
	printf("NULL\nb: ");
	ptr = b;
	while (ptr != NULL)
	{
		printf("%d - ", ptr->value);
		ptr = ptr->next;
	}
	printf("NULL\n");
}

int		ft_get_next(t_stack *anchor, int prev)
{
	t_stack *ptr;
	int		next;

	ptr = anchor;
	next = ptr->value;
	while (ptr != NULL)
	{
		if (ptr->value > prev && ptr->value < next)
			next = ptr->value;
		ptr = ptr->next;
	}
	return (next);
}

int		ft_pick_final(t_stack *anchor)
{
	t_stack *ptr;
	int		size;
	int		min;
	int		gotcha;

	ptr = anchor;
	size = 0;
	min = ft_get_min(anchor);
	gotcha = 1;
	while (ptr != NULL)
	{
		size += 1;
		ptr = ptr->next;
	}
	ptr = anchor;
	while (ptr != NULL)
	{
		if (ptr->value == min)
			break ;
		gotcha += 1;
		ptr = ptr->next;
	}
	if (size - gotcha < size / 2)
		return (2);
	return (1);
}

int				main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		total;
	int		add;
	char	**nums;
	int		mem;

	mem = 0;
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
	// printf("_______________________________");
	// ft_print_stacks(a, b);
	// printf("\n");
	if (ft_is_sorted(a) == 1)
		printf("sorted\n");
	else
	{
		while (ft_is_sorted(a) != 1 || b != NULL)
		{
			if (ft_find_unsorted(a, ft_get_min(a), ft_get_max(a), &mem) == 1)
				while (a->value != mem)
				{
					printf("ra\n");
					ft_rotate(&a);
				}
			else
				while (a->value != mem)
				{
					printf("rra\n");
					ft_reverse_rotate(&a);
				}
			if (ft_is_swap_good(a, ft_get_min(a), ft_get_max(a)) == 1)
			{
				printf("sa\n");
				ft_swap_first_two(&a);
			}
			else
			{
				ft_rotate(&a);
				printf("ra\n");
				while (a->value < mem && !(mem == ft_get_max(a) && a->value == ft_get_min(a)))
				{
					ft_push_from_to(&a, &b);
					printf("pb\n");
				}
				// ft_print_stacks(a, b);
				// printf("_______________________________\n");
				while (b != NULL)
				{
					ft_range(&a, b->value);
					printf("pa\n");
					ft_push_from_to(&b, &a);
				}
				// ft_print_stacks(a, b);
				// printf("_______________________________\n");
			}
		}
		if (ft_pick_rotate(a, ft_get_min(a)) == 1)
			while (a->value != ft_get_min(a))
			{
				printf("ra\n");
				ft_rotate(&a);
			}
		else
			while (a->value != ft_get_min(a))
			{
				printf("rra\n");
				ft_reverse_rotate(&a);
			}
		ft_print_stacks(a, b);
		printf("_______________________________\n");
	}
	// ft_print_stacks(a, b);
	// printf("_______________________________\n");
	// printf("Total amount of operations: %d\n\n", total);
	return (0);
}
