# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cluby <cluby@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/31 16:19:28 by cluby             #+#    #+#              #
#    Updated: 2024/05/31 16:19:29 by cluby            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = cc
CCFLAGS = -Wall -Werror -Wextra -I include -g3
SRC =	src/main.c\
		src/parsing.c\
		src/errors.c\
		src/pathfinding.c\
		src/missing.c\
		src/utils.c
OBJ = $(SRC:.c=.o)
NAME = so_long
LIBFT = libft

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C $(LIBFT)
	cc $(CCFLAGS) $(OBJ) -o so_long ./libft/libft.a -ldl -lglfw -lm -lpthread -LMLX42/build -lmlx42 -IMLX42/include

clean :
	rm -f $(OBJ)
	@make clean -C $(LIBFT)

fclean : clean
	rm -f $(NAME)
	rm -f $(LIBFT)/libft.a

re : fclean all

.PHONY : all clean fclean re