/*
***	Takes a new node as first argument and adds it to a linked stack which is pointed on by second argument
 */

#include "../swaplib.h"

void	ft_add_node(t_stack *new, t_stack **anchor)
{
	new->next = *anchor;
	*anchor = new;
}
