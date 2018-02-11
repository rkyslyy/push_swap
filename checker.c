/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:22:05 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/01/24 18:22:06 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./swaplib.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;
	int		add;
	char	**nums;

	if (argc != 2)
		return (1);
	a = NULL;
	b = NULL;
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
	add = 1;
	while (add != 0)
	{
		add = get_next_line(0, &line);
		if (ft_strcmp(line, "sa") == 0)
			ft_swap_first_two(&a);
		if (ft_strcmp(line, "sb") == 0)
			ft_swap_first_two(&b);
		if (ft_strcmp(line, "ss") == 0)
		{
			ft_swap_first_two(&a);
			ft_swap_first_two(&b);
		}
		if (ft_strcmp(line, "pa") == 0)
			ft_push_from_to(&b, &a);
		if (ft_strcmp(line, "pb") == 0)
			ft_push_from_to(&a, &b);
		if (ft_strcmp(line, "ra") == 0)
			ft_rotate(&a);
		if (ft_strcmp(line, "rb") == 0)
			ft_rotate(&b);
		if (ft_strcmp(line, "rr") == 0)
		{
			ft_rotate(&a);
			ft_rotate(&b);
		}
		if (ft_strcmp(line, "rra") == 0)
			ft_reverse_rotate(&a);
		if (ft_strcmp(line, "rrb") == 0)
			ft_reverse_rotate(&b);
		if (ft_strcmp(line, "rrr") == 0)
		{
			ft_reverse_rotate(&a);
			ft_reverse_rotate(&b);
		}
	}
	if (ft_is_sorted(a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}
