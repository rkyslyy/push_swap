#ifndef SWAPLIB_H
# define SWAPLIB_H

typedef struct		s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

# include <stdio.h>
# include <stdlib.h>

int 	ft_get_next(t_stack *node, int mem, int pivot);
int		ft_scout(t_stack *node, int mem, int pivot);
int		ft_get_pivot(t_stack *a, int val);
int		ft_get_biggest(t_stack *b, int val);
int		ft_find_some(t_stack *b, int min, int max, t_stack *a);
int		ft_got_less(t_stack *a, int median);
void	ft_print_stacks(t_stack *a, t_stack *b);
int		ft_check_front(t_stack *node, int median);
int		ft_get_size(t_stack *a);
int		ft_get_median(t_stack *anchor);
int		ft_get_last_value(t_stack *anchor);
int		ft_get_min(t_stack *anchor);
int		ft_get_max(t_stack *anchor);
int		ft_is_swap_good(t_stack *anchor);
int		ft_find_unsorted(t_stack *anchor, int min, int max, int *mem);
char	**ft_get_ints(char const *arg);
int 	ft_range(t_stack **a, int first_b);
int		ft_is_sorted(t_stack *anchor);
int		ft_pick_rotate(t_stack *anchor, int to_find);
void	ft_add_node(t_stack *new, t_stack **anchor);
t_stack	*ft_create_node(int value);
void	ft_push_from_to(t_stack **from, t_stack **to);
void	ft_push_till_big(t_stack *a, t_stack *b, int mem);
void	ft_reverse_rotate(t_stack **anchor);
void	ft_rotate(t_stack **anchor);
void	ft_swap_first_two(t_stack **anchor);

#endif