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

static t_list	*ft_create_node(int value, t_list *anchor)
{
	t_list *new;

	new = (t_list*)malloc(sizeof(t_list));
	new->value = value;
	new->next = NULL;
	return (new);
}

static t_list	*ft_add_node(t_list *new, t_list *anchor)
{
	new->next = anchor;
	anchor = new;
	return (anchor);
}

static t_list	*ft_swap_first_two(t_list *anchor)
{
	t_list *tmp;

	tmp = anchor;
	anchor = anchor->next;
	tmp->next = tmp->next->next;
	anchor->next = tmp;
	return (anchor);
}

static t_list	*ft_push_on_other_top(t_list *from, t_list *to)
{
	t_list *tmp;

	tmp = NULL;
	if (from != NULL)
	{
		tmp = from;
		from = from->next;
		tmp->next = to;
		to = tmp;
	}
	return (to);
}

static void		ft_print_stacks(t_list *a, t_list *b)
{
	t_list *aptr;
	t_list *bptr;

	aptr = a;
	bptr = b;
	printf("\n_____\n");
	while (aptr != NULL || bptr != NULL)
	{
		if (aptr != NULL)
			printf("%d ", aptr->value);
		if (bptr != NULL)
			printf("%d\n", bptr->value);
		if (aptr != NULL)
			aptr = aptr->next;
		if (bptr != NULL)
			bptr = bptr->next;
	}
	printf("\n_____\na   b\n");
}

int				main(void)
{
	t_list *a;
	t_list *b;

	a = NULL;
	b = NULL;
	a = ft_add_node(ft_create_node(42, a), a);
	a = ft_add_node(ft_create_node(24, a), a);
	a = ft_add_node(ft_create_node(11, a), a);
	b = ft_add_node(ft_create_node(1, b), b);
	b = ft_add_node(ft_create_node(3, b), b);
	ft_print_stacks(a, b);
	a = ft_swap_first_two(a);
	ft_print_stacks(a, b);
	return (0);
}
