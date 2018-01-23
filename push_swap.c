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

static int		ft_check_if_min(t_list *anchor)
{
	t_list	*ptr;
	int		first;

	ptr = anchor;
	if (ptr != NULL)
	{
		first = ptr->value;
		ptr = ptr->next;
		while (ptr != NULL)
		{
			if (ptr->value < first)
				return (0);
			ptr = ptr->next;
		}
		return (1);
	}
	return (0);
}

static void		ft_print_stacks(t_list *a, t_list *b)
{
	t_list *ptr;

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

static int		ft_is_sorted(t_list *anchor)
{
	t_list *ptr;

	ptr = anchor;
	while (ptr != NULL)
	{
		if (ptr->next != NULL && ptr->value > ptr->next->value)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

static int		ft_pick_rotate(t_list *anchor)
{
	t_list	*ptr;
	int		size;
	int		min;
	int		gotcha;

	ptr = anchor;
	min = ptr->value;
	size = 1;
	while (ptr != NULL)
	{
		if (ptr->value < min)
			gotcha = size;
		size += 1;
		ptr = ptr->next;
	}
	if (size - gotcha < size / 2)
		return (1);
	else
		return (2);
}

int				main(void)
{
	t_list	*a;
	t_list	*b;
	int		total;

	a = NULL;
	b = NULL;
	total = 0;
	ft_add_node(ft_create_node(1), &a);
	ft_add_node(ft_create_node(0), &a);
	ft_add_node(ft_create_node(19), &a);
	ft_add_node(ft_create_node(9), &a);
	ft_add_node(ft_create_node(7), &a);
	ft_add_node(ft_create_node(11), &a);
	ft_print_stacks(a, b);
	while (a != NULL && !ft_is_sorted(a))
	{
		if (a->next != NULL && a->value > a->next->value)
		{
			printf("swapped first two\n");
			total += 1;
			ft_swap_first_two(&a);
		}
		while (!ft_check_if_min(a))
		{
			total += 1;
			if (ft_pick_rotate(a) == 1)
			{
				printf("reverse rotating\n");
				ft_reverse_rotate(&a);
			}
			else
			{
				printf("rotating\n");
				ft_rotate(&a);
			}
		}
		if (!ft_is_sorted(a))
		{
			total += 1;
			printf("pushing to 'b'\n");
			ft_push_from_to(&a, &b);
		}
	}
	while (b != NULL)
	{
		total += 1;
		printf("pushing to 'a'\n");
		ft_push_from_to(&b, &a);
	}
	ft_print_stacks(a, b);
	printf("\ntotal amount of operations: %d\n\n", total);
	return (0);
}
