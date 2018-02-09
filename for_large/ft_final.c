#include "../swaplib.h"

void	ft_final(t_stack **a, t_stack **b, t_pack *pack)
{
	t_stack *aptr;
	t_stack *bptr;

	aptr = *a;
	bptr = *b;
	while (aptr->next != NULL && aptr->value != ft_get_min(aptr))
	{
		ft_rotate_a(a, pack);
		aptr = *a;
	}
	while (bptr != NULL)
	{
		ft_push_from_b_to_a(a, b, pack);
		bptr = *b;
	}
}
