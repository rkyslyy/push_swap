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

// static int	ft_get_prev(t_stack *anchor, int value)
// {
// 	t_stack *ptr;

// 	ptr = anchor;
// 	if (anchor->value == value)
// 		return (ft_get_last_value(anchor));
// 	while (ptr != NULL)
// 	{
// 		if (ptr->next != NULL && ptr->next->value == value)
// 			break ;
// 		ptr = ptr->next;
// 	}
// 	return (ptr->value);
// }

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

// static void	ft_get_unsorted(t_stack *anchor, int min, int max)
// {
// 	t_stack *ptr;

// 	ptr = anchor;
// 	while (ptr != NULL)
// 	{
// 		if (ptr->value > ptr->next->value && !(ptr->value == max && ptr->next->value == min))
// 		{

// 		}
// 		ptr = ptr->next;
// 	}
// }

int				main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		total;
	int		add;
	char	**nums;
	int		median;

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
		median = ft_get_median(a);
		while (a->value != median)
		{
			if (a->value > median || !ft_check_front(a, median))
			{
				if (b != NULL && ft_pick_rotate(b) == 1)
					while (b->value != ft_get_max(b))
					{
						ft_rotate(&b);
						printf("rb\n");
						total += 1;
					}
				else
					while (b != NULL && b->value != ft_get_max(b))
					{
						ft_reverse_rotate(&b);
						printf("rrb\n");
						total += 1;
					}
				ft_push_from_to(&a, &b);
				total += 1;
				printf("pb\n");
			}
			else
			{
				ft_rotate(&a);
				total += 1;
				printf("ra\n");
			}
		}
		ft_rotate(&a);
		printf("ra\n");
		total += 1;
		while (a->value != median)
		{
			if (a->value < median || !ft_check_front(a, median))
			{
				if (b != NULL && ft_pick_rotate(b) == 1)
					while (b->value != ft_get_max(b))
					{
						ft_rotate(&b);
						printf("rb\n");
						total += 1;
					}
				else
					while (b != NULL && b->value != ft_get_max(b))
					{
						ft_reverse_rotate(&b);
						printf("rrb\n");
						total += 1;
					}
				ft_push_from_to(&a, &b);
				printf("pb\n");
				total += 1;
			}
			else
			{
				ft_rotate(&a);
				printf("ra\n");
				total += 1;
			}
		}
		ft_print_stacks(a, b);
		return (0);
		while (b != NULL)
		{
			
			printf("pa\n");
			ft_push_from_to(&b, &a);
			total += 1;
			if (b != NULL && ft_get_max(b) < median && !ft_got_less(a, median))
			{
				ft_reverse_rotate(&a);
				printf("ra\n");
				total += 1;
			}
		}
		ft_print_stacks(a, b);
		printf("\nTotal amount of operations: %d\n", total);
		// while (ft_is_sorted(a) != 1 || b != NULL)
		// {
		// 	if (ft_find_unsorted(a, ft_get_min(a), ft_get_max(a), &mem) == 1)
		// 		while (a->value != mem)
		// 		{	
		// 			printf("ra\n");
		// 			ft_rotate(&a);
		// 		}
		// 	else
		// 		while (ft_get_last_value(a) != mem)
		// 		{
		// 			printf("rra\n");
		// 			ft_reverse_rotate(&a);
		// 		}
		// 	if (ft_is_swap_good(a, ft_get_min(a), ft_get_max(a)) == 1)
		// 	{
		// 		printf("sa\n");
		// 		ft_swap_first_two(&a);
		// 	}
		// 	else if ((ft_is_swap_good(a, ft_get_min(a), ft_get_max(a)) == 2) ||
		// 		(a->value == ft_get_max(a) && ft_get_last_value(a) == ft_get_min(a)))
		// 	{
		// 		ft_reverse_rotate(&a);
		// 		printf("rra\n");
		// 		ft_swap_first_two(&a);
		// 		printf("sa\n");
		// 	}
		// 	else
		// 	{
		// 		while (ft_get_last_value(a) != mem)
		// 		{
		// 			ft_rotate(&a);
		// 			printf("ra\n");
		// 		}
		// 		while (a->value < mem && !(mem == ft_get_max(a) && a->value == ft_get_min(a)))
		// 		{
		// 				ft_push_from_to(&a, &b);
		// 				printf("pb\n");
		// 		}
		// 		ft_print_stacks(a, b);
		// 		printf("_______________________________\n");
		// 		while (b != NULL)
		// 		{
		// 			ft_range(&a, b->value);
		// 			printf("pa\n");
		// 			ft_push_from_to(&b, &a);
		// 			// ft_print_stacks(a, b);
		// 			// printf("_______________________________\n");
		// 		}
		// 		// ft_print_stacks(a, b);
		// 		// printf("_______________________________\n");
		// 	}
		// }
		// if (ft_pick_rotate(a, ft_get_min(a)) == 1)
		// 	while (a->value != ft_get_min(a))
		// 	{
		// 		printf("ra\n");
		// 		ft_rotate(&a);
		// 	}
		// else
		// 	while (a->value != ft_get_min(a))
		// 	{
		// 		printf("rra\n");
		// 		ft_reverse_rotate(&a);
		// 	}
		// ft_print_stacks(a, b);
		// printf("_______________________________\n");
	}
	// ft_print_stacks(a, b);
	// printf("_______________________________\n");
	// printf("Total amount of operations: %d\n\n", total);
	return (0);
}
