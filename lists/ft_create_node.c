#include "../swaplib.h"

t_list	*ft_create_node(int value)
{
	t_list *new;

	new = (t_list*)malloc(sizeof(t_list));
	new->value = value;
	new->next = NULL;
	return (new);
}