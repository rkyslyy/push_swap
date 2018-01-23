#ifndef SWAPLIB_H
# define SWAPLIB_H

typedef struct		s_list
{
	int				value;
	struct s_list	*next;
}					t_list;

# include <stdio.h>
# include <stdlib.h>

int		ft_check_if_min(t_list *anchor);
int		ft_is_sorted(t_list *anchor);
int		ft_pick_rotate(t_list *anchor);
void	ft_add_node(t_list *new, t_list **anchor);
t_list	*ft_create_node(int value);
void	ft_push_from_to(t_list **from, t_list **to);
void	ft_reverse_rotate(t_list **anchor);
void	ft_rotate(t_list **anchor);
void	ft_swap_first_two(t_list **anchor);

#endif