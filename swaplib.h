#ifndef SWAPLIB_H
# define SWAPLIB_H

typedef struct		s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

# include <stdio.h>
# include <stdlib.h>

char	**ft_get_ints(char const *arg);
int		ft_check_if_min(t_stack *anchor);
int		ft_is_sorted(t_stack *anchor);
int		ft_pick_rotate(t_stack *anchor, int next);
void	ft_add_node(t_stack *new, t_stack **anchor);
t_stack	*ft_create_node(int value);
void	ft_push_from_to(t_stack **from, t_stack **to);
void	ft_reverse_rotate(t_stack **anchor);
void	ft_rotate(t_stack **anchor);
void	ft_swap_first_two(t_stack **anchor);

#endif