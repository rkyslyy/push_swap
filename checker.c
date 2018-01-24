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

#include "./libft/libft.h"
#include "./swaplib.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;
	int		add;

	a = NULL;
	b = NULL;
	add = argc - 1;
	while (add >= 1)
	{
		ft_add_node(ft_create_node(ft_atoi(argv[add])), &a);
		add -= 1;
	}
	add = 1;
	while (add != 0)
	{
		add = get_next_line(1, &line);
		ft_printf("line is %s\n", line);
	}
	return (0);
}
