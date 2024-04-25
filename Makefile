CC = cc
CCFLAGS = -Wall -Werror -Wextra -I include
SRC =	src/main.c\
		src/parsing.c
OBJ = $(SRC:.c=.o)
NAME = so_long
LIBFT = libft

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C $(LIBFT)
	cc $(CCFLAGS) $(OBJ) -o so_long ./libft/libft.a

clean :
	rm -f $(OBJ)
	@make clean -C $(LIBFT)

fclean : clean
	rm -f $(NAME)
	rm -f $(LIBFT)/libft.a

re : fclean all

.PHONY : all clean fclean re