/*
***	Takes integer value as a parameter, allocates a new t_stack node containing this value and returns it
 */

#include "../swaplib.h"

t_stack	*ft_create_node(int value)
{
	t_stack *new;

	new = (t_stack*)malloc(sizeof(t_stack));
	new->value = value;
	new->next = NULL;
	return (new);
}