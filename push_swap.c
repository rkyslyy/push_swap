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

static void ft_swap_rotate(t_stack **a, t_pack *pack)
{
	t_stack *ptr;

	ptr = *a;
	if (ptr->value > ptr->next->value && !ft_is_sorted(ptr))
		ft_swap_a(a, pack);
	ptr = *a;
	if (ft_pick_rotate(ptr, ft_get_min(ptr)) == 1)
		while (ptr->value != ft_get_min(ptr))
		{
			ft_rotate_a(a, pack);
			ptr = *a;
		}
	else
		while (ptr->value != ft_get_min(ptr))
		{
			ft_reverse_rotate_a(a, pack);
			ptr = *a;
		}
}

static int	ft_return_usage(void)
{
	ft_printf("Error\n____________________________________\n");
	ft_printf("usage: ./push_swap [values] [flags] |\n");
	ft_printf("                      ^^       ^    |\n");
	ft_printf("   Range of integer only      -v    |\n");
	ft_printf("Digits, '-' and '+' only      -o    |\n");
	ft_printf("____________________________________|\n");
	return (1);
}

static int	ft_build_stack(t_stack **a, t_pack *pack, char **argv, int argc)
{
	char	**nums;

	pack->add = 0;
	nums = ft_strsplit(argv[argc - 1], ' ');
	if (!ft_is_input_valid(nums, pack))
		return (1);
	if (ft_strcmp(nums[0], "-v") == 0 || ft_strcmp(nums[0], "-o") == 0)
		return (0);
	while (nums[pack->add] != 0)
		pack->add += 1;
	pack->add -= 1;
	while (pack->add >= 0)
	{
		ft_add_node(ft_create_node(ft_atoi(nums[pack->add])), a);
		pack->add -= 1;
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_pack	pack;

	a = NULL;
	b = NULL;
	pack.total = 0;
	pack.print = 1;
	pack.visual = 0;
	while (argc > 1)
		if (ft_build_stack(&a, &pack, argv, argc--))
			return (ft_return_usage());
	if (ft_get_size(a) <= 3)
		ft_swap_rotate(&a, &pack);
	else if (ft_get_size(a) <= 10)
		ft_insert_swap(&a, &b, &pack);
	else
		ft_quick_sort(&a, &b, &pack);
	// ft_print_stacks(a, b);
	// ft_printf("\nTotal amount of operations: %d\n", pack.total);
	return (0);
}
