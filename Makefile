NAME			=	push_swap
NAME_BONUS		=	checker
HEADER			=	push_swap.h
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
SRCS			=	indexing.c lists_utils.c lists.c main.c more_operations.c operations.c \
					parse_args.c stack.c start_sorting.c utils.c targets.c cost.c handle_sizes.c
SRCS_BONUS		=	indexing.c lists_utils.c lists.c more_operations.c operations.c \
					parse_args.c stack.c start_sorting.c utils.c targets.c cost.c handle_sizes.c checker.c
LIBS			=	./libs/ft_printf/libftprintf.a ./libs/libft/libft.a ./libs/get_next_line/get_next_line.c \
					./libs/get_next_line/get_next_line_utils.c
OBJ				=	$(SRCS:.c=.o)
OBJ_BONUS		=	$(SRCS_BONUS:.c=.o)

all:		$(NAME)

comp_start:
	@echo "Preparing libraries ..."
	@cd ./libs/libft && make
	@cd ./libs/ft_printf && make

$(NAME): comp_start $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LINKS) $(LIBS) -o $(NAME)

bonus: comp_start $(OBJ_BONUS)
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(LINKS) $(LIBS) -o $(NAME_BONUS)

%.o: %.c $(HEADER)
	@echo "Making object file .."
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning ..."
	@rm -f $(OBJ)
	@cd ./libs/libft && make clean
	@cd ./libs/ft_printf && make clean
	@echo "Cleaning Done"

fclean : clean
	@echo "Full Cleaning ..."
	@rm -f $(OBJ) $(NAME)
	@cd ./libs/libft && make fclean
	@cd ./libs/ft_printf && make fclean
	@echo "Full Cleaning Done"

re: fclean all

.PHONY: comp_start clean