DO_ALL = push_swap checker
SRCDIR = ./src/
MAINDR = ./mains/
SRCDO_ALLS = $(shell ls $(SRCDIR) | grep -E ".+\.c")
INC = ./swaplib.h
BUILDDIR = ./obj/
BUILDOBJS = $(addprefix $(BUILDDIR), $(SRCDO_ALLS:.c=.o))
LIBDIR = ./libft/
LIBFT = ./libft/libft.a
LIBINC = ./libft/

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(MAINDR) $(BUILDDIR) $(DO_ALL) 

$(BUILDDIR):
	@ mkdir obj

$(BUILDDIR)%.o:$(MAINDR)%.c
	@ $(CC) $(CFLAGS) -I$(LIBINC) -I$(INC) -o $@ -c $<

$(BUILDDIR)%.o:$(SRCDIR)%.c
	@ $(CC) $(CFLAGS) -I$(LIBINC) -I$(INC) -o $@ -c $<

$(DO_ALL): $(LIBFT) ./obj/push_swap.o ./obj/checker.o $(BUILDOBJS) 
	@ $(CC) $(CFLAGS) -o push_swap $(BUILDOBJS) ./obj/push_swap.o $(LIBFT)
	@ $(CC) $(CFLAGS) -o checker $(BUILDOBJS) ./obj/checker.o $(LIBFT)

$(LIBFT):
	@ make -C $(LIBDIR)

clean:
	@ rm -rf $(BUILDDIR)
	@ make clean -C $(LIBDIR)

fclean: clean
	@ rm -rf $(DO_ALL)
	@ rm -f log.txt
	@ make fclean -C $(LIBDIR)

re: fclean all

.PHONY: all fclean clean re