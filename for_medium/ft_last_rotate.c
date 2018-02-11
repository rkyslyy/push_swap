#include "../swaplib.h"

void	ft_last_rotate(t_stack **a, t_pack *pack)
{
	t_stack *aptr;

	aptr = *a;
	if (ft_pick_rotate(aptr, ft_get_min(aptr)) == 1)
		while (aptr->value != ft_get_min(aptr))
		{
			ft_rotate_a(a, pack);
			aptr = *a;
		}
	else
		while (aptr->value != ft_get_min(aptr))
		{
			ft_reverse_rotate_a(a, pack);
			aptr = *a;
		}
}