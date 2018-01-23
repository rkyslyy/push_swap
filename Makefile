SWAP_NAME = push_swap

HEADER = ./swaplib.h

OPTIONS = -c -I $(HEADER)

OPERATORS =	./operators/ft_push_from_to.c	\
			./operators/ft_reverse_rotate.c	\
			./operators/ft_rotate.c			\
			./operators/ft_swap_first_two.c	\
			./push_swap.c

LISTS =		./lists/ft_add_node.c			\
			./lists/ft_create_node.c

CHECKUP =	./checkup/ft_check_if_min.c		\
			./checkup/ft_is_sorted.c		\
			./checkup/ft_pick_rotate.c

OBJECTS =	./ft_push_from_to.o				\
			./ft_reverse_rotate.o			\
			./ft_rotate.o					\
			./ft_swap_first_two.o			\
			./ft_add_node.o					\
			./ft_create_node.o				\
			./ft_check_if_min.o				\
			./ft_is_sorted.o				\
			./ft_pick_rotate.o				\
			./push_swap.o

all: $(SWAP_NAME)

$(SWAP_NAME):
				@ gcc $(FLAGS) $(OPTIONS) $(OPERATORS) $(LISTS) $(CHECKUP)
				@ gcc $(OBJECTS) -o $(SWAP_NAME)
				@ /bin/rm -f $(OBJECTS)
clean:
				@ /bin/rm -f $(OBJECTS)

fclean:	clean
				@ /bin/rm -f $(SWAP_NAME)

re: fclean all
