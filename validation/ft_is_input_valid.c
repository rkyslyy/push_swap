#include "../swaplib.h"

int	ft_is_input_valid(char **nums, t_pack *pack)
{
	size_t	n;
	size_t	ptr;

	ptr = 0;
	while (nums[ptr] != 0)
	{
		n = 0;
		while (nums[ptr][n] != '\0')
		{
			if (!ft_isdigit(nums[ptr][n]) && nums[ptr][n] != '+' &&
				nums[ptr][n] != '-' && ft_strcmp(nums[ptr], "-v") != 0 &&
				ft_strcmp(nums[ptr], "-o") != 0 && ft_strcmp(nums[ptr], "-t") != 0
				&& ft_strcmp(nums[ptr], "-h") != 0)
				return (0);
			n += 1;
		}
		if (ft_strcmp(nums[ptr], "-v") == 0)
		{
			pack->visual = 1;
			break ;
		}
		if (ft_strcmp(nums[ptr], "-o") == 0)
		{
			pack->output = 1;
			break ;
		}
		if (ft_strcmp(nums[ptr], "-t") == 0)
		{
			pack->result = 1;
			break ;
		}
		if (ft_strcmp(nums[ptr], "-h") == 0)
		{
			pack->highlight = 1;
			break ;
		}
		if (ft_atoi(nums[ptr]) > 2147483647 ||
			ft_atoi(nums[ptr]) < -2147483648)
			return (0);
		ptr += 1;
	}
	return (1);
}