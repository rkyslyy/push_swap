DO_ALL = do_all

SWAP_NAME = push_swap

CHECKER_NAME = checker

HEADER = ./swaplib.h

OPTIONS = -Wall -Wextra -Werror

LIBFT =		./libft/libft.a

OPERATORS =	./operators/ft_push_from_to.c	\
			./operators/ft_reverse_rotate.c	\
			./operators/ft_rotate.c			\
			./operators/ft_swap_first_two.c

LISTS =		./lists/ft_add_node.c			\
			./lists/ft_create_node.c

CHECKUP =	./checkup/ft_check_if_min.c		\
			./checkup/ft_is_sorted.c		\
			./checkup/ft_pick_rotate.c

SWAPSOURCES =	$(LIBFT) $(OPERATORS) $(LISTS) $(CHECKUP)

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
