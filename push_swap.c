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

#include <stdlib.h>
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

int				main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		total;
	int		add;

	a = NULL;
	b = NULL;
	total = 0;
	add = argc - 1;
	while (add >= 1)
	{
		ft_add_node(ft_create_node(atoi(argv[add])), &a);
		add -= 1;
	}
	//printf("_______________________________");
	//ft_print_stacks(a, b);
	//printf("\n");
	while (a != NULL && !ft_is_sorted(a))
	{
		if (a->next != NULL && a->value > a->next->value)
		{
			printf("sa\n");
			total += 1;
			ft_swap_first_two(&a);
		}
		while (!ft_check_if_min(a))
		{
			total += 1;
			if (ft_pick_rotate(a) == 1)
			{
				printf("rra\n");
				ft_reverse_rotate(&a);
			}
			else
			{
				printf("ra\n");
				ft_rotate(&a);
			}
		}
		if (!ft_is_sorted(a))
		{
			total += 1;
			printf("pb\n");
			ft_push_from_to(&a, &b);
		}
	}
	while (b != NULL)
	{
		total += 1;
		printf("pa\n");
		ft_push_from_to(&b, &a);
	}
	//ft_print_stacks(a, b);
	//printf("_______________________________\n");
	//printf("Total amount of operations: %d\n\n", total);
	return (0);
}
