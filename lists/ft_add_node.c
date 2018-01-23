#include "../swaplib.h"

void	ft_add_node(t_list *new, t_list **anchor)
{
	new->next = *anchor;
	*anchor = new;
}
