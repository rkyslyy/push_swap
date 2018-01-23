/*
***	Takes a new node as first argument and adds it to a linked list which is pointed on by second argument
 */

#include "../swaplib.h"

void	ft_add_node(t_list *new, t_list **anchor)
{
	new->next = *anchor;
	*anchor = new;
}
