/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 14:51:14 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/02/02 14:51:15 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

// static void		ft_print_stacks(t_stack *a, t_stack *b)
// {
// 	t_stack *ptr;

// 	ptr = a;
// 	printf("\na: ");
// 	while (ptr != NULL)
// 	{
// 		printf("%d - ", ptr->value);
// 		ptr = ptr->next;
// 	}
// 	printf("NULL\nb: ");
// 	ptr = b;
// 	while (ptr != NULL)
// 	{
// 		printf("%d - ", ptr->value);
// 		ptr = ptr->next;
// 	}
// 	printf("NULL\n");
// }

static int	ft_get_last_value(t_stack *anchor)
{
	int ret;

	t_stack *ptr;
	ptr = anchor;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ret = ptr->value;
	return (ret);
}

int	ft_range(t_stack **a, int first_b)
{
	t_stack *ptr;
	t_stack *anchor;
	int before;
	int after;
	int	max;
	int	min;
	int	size;
	int	before_ro;
	int	before_rro;
	int	after_ro;
	int	after_rro;

	anchor = *a;
	ptr = anchor;
	max = ft_get_max(anchor);
	min = ft_get_min(anchor);
	before = min;
	after = max;
	if (first_b < min || first_b > max)
	{
		before = max;
		after = min;
	}
	else
	{
		while (ptr != NULL)
		{
			if (ptr->value < first_b && ptr->value > before)
				before = ptr->value;
			ptr = ptr->next;
		}
		ptr = anchor;
		while (ptr != NULL)
		{
			if (ptr->value > first_b && ptr->value < after)
					after = ptr->value;
			ptr = ptr->next;
		}
	}
	//printf("before = %d after = %d\n", before, after);
	size = 0;
	min = 1;
	max = 1;
	ptr = anchor;
	while (ptr != NULL)
	{
		size += 1;
		ptr = ptr->next;
	}
	ptr = anchor;
	while (ptr != NULL)
	{
		if (ptr->value == before)
			break ;
		min += 1;
		ptr = ptr->next;
	}
	ptr = anchor;
	while (ptr != NULL)
	{
		if (ptr->value == after)
			break ;
		max += 1;
		ptr = ptr->next;
	}
	before_ro = min;
	before_rro = size - min;
	after_ro = max - 1;
	after_rro = size - (max - 1);
	ptr = *a;
	if (before_ro <= before_rro && before_ro <= after_ro && before_ro <= after_rro)
		while (ft_get_last_value(ptr) != before)
		{
			printf("ra\n");
			ft_rotate(&*a);
			ptr = *a;
		}
	else if (before_rro <= before_ro && before_rro <= after_ro && before_ro <= after_rro)
		while (ft_get_last_value(ptr) != before)
		{
			printf("rra\n");
			ft_reverse_rotate(&*a);
			ptr = *a;
		}
	else if (after_ro <= before_ro && after_ro <= after_rro && after_ro <= before_rro)
		while (ptr->value != after)
		{
			printf("ra\n");
			ft_rotate(&*a);
			ptr = *a;
		}
	else if (after_rro <= before_rro && after_rro <= after_ro && after_ro <= before_ro)
		while (ptr->value != after)
		{
			printf("rra\n");
			ft_reverse_rotate(&*a);
			ptr = *a;
		}
	return (0);
}
