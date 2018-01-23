/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 17:14:23 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/22 17:14:48 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_list
{
	int		value;
	struct s_list	*next;
}				t_list;

#include <stdio.h>
#include <stdlib.h>

static t_list	*ft_create_node(int value)
{
	t_list *new;

	new = (t_list*)malloc(sizeof(t_list));
	new->value = value;
	new->next = NULL;
	return (new);
}

static void		ft_add_node(t_list *new, t_list **anchor)
{
	new->next = *anchor;
	*anchor = new;
}

static void		ft_swap_first_two(t_list **anchor)
{
	t_list *ptr;
	t_list *tmp;

	ptr = *anchor;
	if (ptr != NULL && ptr->next != NULL)
	{
		tmp = *anchor;
		*anchor = ptr->next;
		tmp->next = tmp->next->next;
		ptr = *anchor;
		ptr->next = tmp;
	}
}

static void		ft_push_on_other_top(t_list **from, t_list **to)
{
	t_list *tmp;
	t_list *ptr;

	if (*from != NULL && *to != NULL)
	{
		tmp = *from;
		ptr = *from;
		*from = ptr->next;
		tmp->next = *to;
		*to = tmp;
	}
}

static void		ft_rotate(t_list **anchor)
{
	t_list *ptr;
	t_list *tmp;

	ptr = *anchor;
	if (ptr != NULL && ptr->next != NULL)
	{
		tmp = *anchor;
		*anchor = ptr->next;
		ptr = *anchor;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = tmp;
		tmp->next = NULL;
	}
}

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

int				main(void)
{
	t_list *a;
	t_list *b;
	t_list *ptr;

	a = NULL;
	b = NULL;
	ft_add_node(ft_create_node(42), &a);
	ft_add_node(ft_create_node(11), &a);
	ft_add_node(ft_create_node(50), &b);
	ft_add_node(ft_create_node(33), &b);
	ft_print_stacks(a, b);
	printf("\nSwapping first two in 'a'\n");
	ft_swap_first_two(&a);
	ft_print_stacks(a, b);
	ft_push_on_other_top(&b, &a);
	printf("\nMoving first from 'a' to 'b'\n");
	ft_print_stacks(a, b);
	ft_rotate(&a);
	printf("\nRotating 'a'\n");
	ft_print_stacks(a, b);
	return (0);
}
