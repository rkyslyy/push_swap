DO_ALL = $(SWAP_NAME) $(CHECKER_NAME)

SWAP_NAME = push_swap

CHECKER_NAME = checker

HEADER = ./swaplib.h

OPTIONS = -Wall -Wextra -Werror

LIBFT =		./libft/libft.a

OPERATORS =	./operators/ft_push_from_to.c	\
			./operators/ft_reverse_rotate.c	\
			./operators/ft_rotate.c			\
			./operators/ft_swap_first_two.c	\
			./operators/ft_push_a_to_b.c	\
			./operators/ft_push_b_to_a.c	\
			./operators/ft_rotate_a.c		\
			./operators/ft_rotate_b.c		\
			./operators/ft_rotate_both.c	\
			./operators/ft_re_rotate_a.c	\
			./operators/ft_re_rotate_b.c	\
			./operators/ft_re_rotate_both.c	\
			./operators/ft_swap_a.c			\
			./operators/ft_swap_b.c			\
			./operators/ft_swap_both.c

LISTS =		./lists/for_h/ft_nums_a.c		\
			./lists/for_h/ft_nums_b.c		\
			./lists/ft_print_stacks.c		\
			./lists/ft_add_node.c			\
			./lists/ft_create_node.c		\
			./lists/ft_free_lists.c			\
			./for_log/ft_make_header.c		\
			./for_log/ft_result.c

CHECKUP =	./checkup/ft_get_next.c			\
			./checkup/ft_find_unsorted.c	\
			./checkup/ft_scout.c			\
			./checkup/ft_get_pivot.c		\
			./checkup/ft_get_biggest.c		\
			./checkup/ft_get_size.c			\
			./checkup/ft_get_last_value.c	\
			./checkup/ft_get_min.c			\
			./checkup/ft_get_max.c			\
			./checkup/ft_is_swap_good.c		\
			./checkup/ft_is_sorted.c		\
			./checkup/ft_pick_rotate.c		\
			./validation/ft_return_usage.c	\
			./validation/ft_is_input_valid.c

FOR_LARGE = ./for_large/ft_deal_with_b.c	\
			./for_large/ft_set_pivot.c		\
			./for_large/ft_final.c			\
			./for_large/ft_quick_sort.c		\
			./for_medium/ft_last_rotate.c	\
			./for_medium/ft_insert_sort.c	\
			./main_files/ft_check_conf.c	\
			./main_files/ft_get_insts.c		\
			./main_files/ft_shmatok.c		\
			./main_files/ft_valid_com.c		\
			./main_files/ft_vis_stacks.c	\
			./main_files/ft_free_nums.c		\
			./for_large_2/ft_fast_af_boi.c	\
			./for_large_2/ft_rev_quick.c	\
			./for_large_2/ft_rev_deal_with_b.c


SWAPSOURCES = $(LIBFT) $(OPERATORS) $(LISTS) $(CHECKUP) $(FOR_LARGE)

all: $(DO_ALL)

$(DO_ALL):
				@ make -C libft
				@ gcc $(OPTIONS) $(SWAPSOURCES) ./main_files/push_swap.c -o $(SWAP_NAME)
				@ gcc $(OPTIONS) $(SWAPSOURCES) ./main_files/checker.c -o $(CHECKER_NAME)

clean:
				@ make clean -C libft
				@ rm -f log.txt

fclean: clean
				@ /bin/rm -f $(SWAP_NAME) $(CHECKER_NAME)
				@ make fclean -C libft

re: fclean all

.PHONY: clean all fclean re
