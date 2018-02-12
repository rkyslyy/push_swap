DO_ALL = do_all

SWAP_NAME = push_swap

CHECKER_NAME = checker

HEADER = ./swaplib.h

OPTIONS = -Wall -Wextra -Werror

LIBFT =		./libft/libft.a

OPERATORS =	./operators/ft_push_from_to.c	\
			./operators/ft_push_till_big.c	\
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

LISTS =		./lists/ft_print_stacks.c		\
			./lists/ft_add_node.c			\
			./lists/ft_create_node.c

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
			./checkup/ft_pick_rotate.c

FOR_LARGE = ./for_large/ft_deal_with_b.c	\
			./for_large/ft_set_pivot.c		\
			./for_large/ft_final.c			\
			./for_large/ft_quick_sort.c		\
			./for_medium/ft_last_rotate.c	\
			./for_medium/ft_insert_sort.c

SWAPSOURCES =	$(LIBFT) $(OPERATORS) $(LISTS) $(CHECKUP) $(FOR_LARGE)

all: $(DO_ALL)

$(DO_ALL):
				@ make re -C libft
				@ gcc $(OPTIONS) $(SWAPSOURCES) ./push_swap.c -o $(SWAP_NAME)
				@ gcc $(OPTIONS) $(SWAPSOURCES) ./checker.c -o $(CHECKER_NAME)

clean:
				@ make fclean -C libft

fclean: clean
				@ /bin/rm -f $(SWAP_NAME)

re: fclean all
