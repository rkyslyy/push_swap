#include "../swaplib.h"

void	ft_deal_with_b(t_stack **b, t_stack **a, t_pack *pack)
{
	t_stack *bptr;
	t_stack *aptr;

	bptr = *b;
	aptr = *a;
	if (bptr != NULL && ft_pick_rotate(bptr, ft_get_biggest(bptr, aptr->value)) == 1)
		while (bptr->value != ft_get_biggest(bptr, aptr->value))
		{
			ft_rotate_b(b, pack);
			bptr = *b;
		}
	else
		while (bptr != NULL && bptr->value != ft_get_biggest(bptr, aptr->value))
		{
			ft_reverse_rotate_b(b, pack);
			bptr = *b;
		}
	ft_push_from_a_to_b(a, b, pack);
}
