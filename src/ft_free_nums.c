/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_nums.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 14:15:47 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/02/20 14:15:47 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

int	ft_free_nums(char **nums, int ret)
{
	size_t ptr;

	ptr = 0;
	while (nums[ptr] != 0)
	{
		free(nums[ptr]);
		ptr += 1;
	}
	free(nums);
	return (ret);
}
