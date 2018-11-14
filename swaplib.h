/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaplib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 13:17:43 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/02/20 13:17:44 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAPLIB_H
# define SWAPLIB_H

# include "./libft/libft.h"

typedef struct		s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_pack
{
	int				total;
	int				pivot;
	int				mem;
	int				add;
	int				print;
	int				visual;
	int				output;
	int				result;
	int				highlight;
	int				read;
	int				input;
	int				no;
	int				ac;
}					t_pack;

int					ft_free_nums(char **nums, int ret);
void				ft_check_conf(char **argv, int argc, t_pack *pack);
int					ft_get_insts(t_pack *pack, char **line);
void				ft_shmatok(t_pack *pack, int *fd, t_stack *a, t_stack *b);
int					ft_valid_com(char *line);
void				ft_vis_stacks(t_pack pack, char *line, t_stack *a,
								t_stack *b);
void				ft_make_header(int *fd, t_stack *a);
int					ft_result(t_pack pack, int fd, t_stack *a, t_stack *b);
int					ft_return_error(int argc);
int					ft_is_input_valid(char **nums, t_pack *pack);
void				ft_set_pivot(t_stack *a, t_pack *pack);
void				ft_deal_with_a(t_stack **a, t_stack **b, t_pack *pack);

void				ft_deal_with_b(t_stack **b, t_stack **a, t_pack *pack);
void				ft_final(t_stack **a, t_stack **b, t_pack *pack);
int					ft_get_next(t_stack *node, int mem, int pivot);
int					ft_scout(t_stack *node, int mem, int pivot);
int					ft_get_pivot(t_stack *a, int val);
int					ft_get_biggest(t_stack *b, int val);
void				ft_nums_a(t_stack *ptr, t_stack *a, t_pack pack,
								char const *line);
void				ft_nums_b(t_stack *ptr, t_stack *b, t_pack pack,
								char const *line);
void				ft_print_stacks(t_stack *a, t_stack *b, char const *line,
								t_pack pack);
int					ft_get_size(t_stack *a);
int					ft_get_last_value(t_stack *anchor);
int					ft_get_min(t_stack *anchor);
int					ft_get_max(t_stack *anchor);
int					ft_is_swap_good(t_stack *anchor);
int					ft_find_unsorted(t_stack *anchor, int min,
								int max, int *mem);
int					ft_range(t_stack **a, int first_b);
int					ft_is_sorted(t_stack *anchor);
int					ft_pick_rotate(t_stack *anchor, int to_find);
void				ft_add_next(t_stack *new, t_stack **anchor);
void				ft_add_node(t_stack *new, t_stack **anchor);
t_stack				*ft_create_node(int value);
void				ft_push_from_to(t_stack **from, t_stack **to);
void				ft_push_till_big(t_stack *a, t_stack *b, int mem);
void				ft_reverse_rotate(t_stack **anchor);
void				ft_rotate(t_stack **anchor);
void				ft_swap_first_two(t_stack **anchor);
void				ft_push_from_a_to_b(t_stack **a, t_stack **b, t_pack *pack);
void				ft_push_from_b_to_a(t_stack **a, t_stack **b, t_pack *pack);
void				ft_rotate_a(t_stack **a, t_pack *pack);
void				ft_rotate_b(t_stack **b, t_pack *pack);
void				ft_rotate_both(t_stack **a, t_stack **b, t_pack *pack);
void				ft_reverse_rotate_a(t_stack **a, t_pack *pack);
void				ft_reverse_rotate_b(t_stack **b, t_pack *pack);
void				ft_reverse_rotate_both(t_stack **a, t_stack **b,
								t_pack *pack);
void				ft_swap_a(t_stack **a, t_pack *pack);
void				ft_swap_b(t_stack **b, t_pack *pack);
void				ft_swap_both(t_stack **a, t_stack **b, t_pack *pack);
void				ft_quick_sort(t_stack **a, t_stack **b, t_pack *pack);
void				ft_first_break(t_stack **a, t_stack **b, t_pack *pack,
								t_stack **pivots);
void				ft_break_b(t_stack **a, t_stack **b, t_pack *pack,
								t_stack **pivots);
void				ft_break_a(t_stack **a, t_stack **b, t_pack *pack,
								t_stack **pivots);
void				ft_fast_af_boi(t_stack **a, t_stack **b, t_pack *pack);
void				ft_insert_swap(t_stack **a, t_stack **b, t_pack *pack);
void				ft_last_rotate(t_stack **a, t_pack *pack);
void				ft_del_node(t_stack **anchor);
void				ft_free_lists(t_stack *a, t_stack *b);
int					ft_new_pivot(t_stack *a, int tail);
int					ft_find_size(t_stack *b, int pivot);
int					ft_find_size_a(t_stack *a, int pivot);
int					ft_find_next(t_stack *b, int pivot);
int					ft_find_next_a(t_stack *a, int pivot);
int					ft_min(t_stack *a);
int					ft_max(t_stack *a);
int					ft_is_left(t_stack *stack, int end, int pivot, int mem);
int					ft_is_left_a(t_stack *stack, int end, int pivot);
void				ft_swap_three(t_stack **a, t_stack **b, t_pack *pack);
void				ft_rev_quick_sort(t_stack **b, t_stack **a, t_pack *pack);
void				ft_rev_deal_with_b(t_stack **a, t_stack **b, t_pack *pack);

#endif
