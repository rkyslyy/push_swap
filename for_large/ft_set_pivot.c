#include "../swaplib.h"

void ft_set_pivot(t_stack *a, t_pack *pack)
{
	if (ft_get_size(a) <= 50)
		pack->pivot = ft_get_pivot(a, ft_get_size(a) / 2);
	else if (ft_get_size(a) <= 100)
		pack->pivot = ft_get_pivot(a, ft_get_size(a) / 3);
	else if (ft_get_size(a) <= 250)
		pack->pivot = ft_get_pivot(a, ft_get_size(a) / 4);
	else
		pack->pivot = ft_get_pivot(a, ft_get_size(a) / 8);
}
