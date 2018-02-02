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

int	ft_find_unsorted(t_stack *anchor)
{
	t_stack *ptr;
	int		gotcha;
	int		size;
	int		min;

	gotcha = 1;
	size = 0;
	ptr = anchor;
	min = ptr->value;
	while (ptr != NULL)
	{
		size += 1;
		if (ptr->value < min)
			min = ptr->value;
		ptr = ptr->next;
	}
	ptr = anchor;
	while (ptr != NULL)
	{
		if (ptr->next != NULL && ptr->value > ptr->next->value && ptr->next->value != min)
			break ;
		if (ptr->next == NULL && ptr->value > anchor->value && anchor->value != min)
			break ;
		gotcha += 1;
		ptr = ptr->next;
	}
	if (size - gotcha < size / 2)
		return (2);
	return (1);
}

int		ft_get_min(t_stack *anchor)
{
	t_stack *ptr;
	int		min;

	ptr = anchor;
	min = ptr->value;
	while (ptr != NULL)
	{
		if (ptr->value < min)
			min = ptr->value;
		ptr = ptr->next;
	}
	return (min);
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
	int		next;

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
		while (ft_is_sorted(a) != 1)
		{
			add = ft_get_min(a);
			if (a->value > a->next->value)
				ft_swap_first_two(&a);
			if (ft_find_unsorted(a) == 1)
				while (a->value < a->next->value || a->next->value == add)
				{
					printf("ra\n");
					ft_rotate(&a);
					//ft_print_stacks(a, b);
				}
			else
				while (a->value < a->next->value || a->next->value == add)
				{
					printf("rra\n");
					ft_reverse_rotate(&a);
					//ft_print_stacks(a, b);
				}
			mem = a->value;
			ft_rotate(&a);
			printf("ra\n");
			//ft_print_stacks(a, b);
			while (a->value < mem && a->value != add)
			{
				printf("pb\n");
				ft_push_from_to(&a, &b);
				//ft_print_stacks(a, b);
			}
			while (b != NULL)
			{
				next = ft_get_next(a, b->value);
				if (ft_pick_rotate(a, next) == 1)
					while (a->value != next)
					{
						printf("ra\n");
						ft_rotate(&a);
						//ft_print_stacks(a, b);
					}
				else
					while (a->value != next)
					{
						printf("rra\n");
						ft_reverse_rotate(&a);
						//ft_print_stacks(a, b);
					}
				printf("pa\n");
				ft_push_from_to(&b, &a);
				//ft_print_stacks(a, b);
			}
		}
		if (ft_pick_final(a) == 1)
			while (a->value != ft_get_min(a))
			{
				printf("ra\n");
				ft_rotate(&a);
				//ft_print_stacks(a, b);
			}
		else
			while (a->value != ft_get_min(a))
			{
				printf("rra\n");
				ft_reverse_rotate(&a);
			//	ft_print_stacks(a, b);
			}
	ft_print_stacks(a, b);
	printf("_______________________________\n");
	}
	// ft_print_stacks(a, b);
	// printf("_______________________________\n");
	// printf("Total amount of operations: %d\n\n", total);
	return (0);
}
