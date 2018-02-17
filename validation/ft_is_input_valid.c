#include "../swaplib.h"

static void	ft_deal(t_pack *pack, char *num, char **filename)
{
	if (ft_strcmp(num, "-v") == 0)
		pack->visual = 1;
	if (ft_strcmp(num, "-o") == 0)
		pack->output = 1;
	if (ft_strcmp(num, "-t") == 0)
		pack->result = 1;
	if (ft_strcmp(num, "-h") == 0)
		pack->highlight = 1;
	if (ft_strcmp(num, "-r") == 0 && pack->no != 1)
	{
		ft_printf("Please enter instructions file name: ");
		while (get_next_line(1, filename) != 1)
			;
		pack->read = open(*filename, O_RDONLY);
		free(*filename);
	}
	if (ft_strcmp(num, "-i") == 0)
	{
		pack->input = 1;
		pack->read = 1;
	}
}

static int	ft_checko(char **nums, size_t n, size_t ptr)
{
	if (!ft_isdigit(nums[ptr][n]) && nums[ptr][n] != '+' &&
		nums[ptr][n] != '-' && ft_strcmp(nums[ptr], "-v") != 0 &&
		ft_strcmp(nums[ptr], "-o") != 0 && ft_strcmp(nums[ptr], "-t") != 0
		&& ft_strcmp(nums[ptr], "-h") != 0 && ft_strcmp(nums[ptr], "-r") != 0
		&& ft_strcmp(nums[ptr], "-i") != 0)
		return (0);
	return (1);
}

int	ft_is_input_valid(char **nums, t_pack *pack)
{
	size_t	n;
	size_t	ptr;
	char	*filename;

	ptr = 0;
	while (nums[ptr] != 0)
	{
		n = 0;
		while (nums[ptr][n] != '\0')
			if (!ft_checko(nums, n++, ptr))
				return (0);
		if (ft_strcmp(nums[ptr], "-v") == 0 || ft_strcmp(nums[ptr], "-o") == 0 ||
			ft_strcmp(nums[ptr], "-t") == 0 || ft_strcmp(nums[ptr], "-h") == 0 ||
			(ft_strcmp(nums[ptr], "-r") == 0 && pack->no != 1) ||
			ft_strcmp(nums[ptr], "-i") == 0)
		{
			ft_deal(pack, nums[ptr], &filename);
			break ;
		}
		if (ft_atoi(nums[ptr]) > 2147483647 ||
			ft_atoi(nums[ptr]) < -2147483648)
			return (0);
		ptr += 1;
	}
	return (1);
}