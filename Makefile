NAME = push_swap
LIBFT = libft
CFLAGS = -Wall -Wextra -Werror -lm -D MAIN
CC = gcc
SRC_PATH = ./
OPTIONS = -I./libft 
SRC = main.c board.c parse.c solver.c push_swap_utils.c board_utils.c tiny_sort.c end.c board_lower.c push.c
SRCS = $(addprefix $(SRC_PATH),$(SRC))
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
			make -C $(LIBFT) bonus
			mv ./libft/libft.a libft.a
			ar rcs libft.a ${OBJS} 


%.o: %.c
	$(CC) -Wall -Wextra -Werror  -c $< -o $@ -g

unit: $(OBJS) $(LIBFT)
	$(CC)  -D UNIT -Ilibft -L. -lft $(OBJS) -o $(NAME) -g 

$(NAME): $(OBJS) $(LIBFT)
	$(CC)  -Ilibft -L. -lft $(OBJS) -o $(NAME) -g 

clean:	
		rm -f $(OBJS)
		make -C $(LIBFT) clean

fclean:	clean
		rm -f $(NAME)
		make -C $(LIBFT) fclean

re:		fclean all

.PHONY: re fclean clean all $(LIBFT) $(NAME)
