# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cluby <cluby@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/31 16:19:28 by cluby             #+#    #+#              #
#    Updated: 2024/07/05 11:20:33 by cluby            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --silent
C = cc
CFLAGS = -Wall -Werror -Wextra -Iinclude -g
SRC =	src/main.c\
		src/parsing.c\
		src/errors.c\
		src/pathfinding.c\
		src/missing.c\
		src/utils.c\
		src/check_arg.c\
		src/game.c\
		src/utils2.c\
		src/keyfunc.c
OBJ = $(SRC:.c=.o)
NAME = so_long
LIBFT = libft

# ------------------------------ Colors ------------------------------

BOLD_PURPLE	=	\033[1;35m
BOLD_CYAN	=	\033[1;36m
BOLD_YELLOW	=	\033[1;33m
NO_COLOR	=	\033[0m

# ------------------------------ Messages ------------------------------

COMP_START	=	echo "\n🚧 $(BOLD_YELLOW)Make: $(NO_COLOR)Starting the compilation...\n"
COMP_END	=	echo "\n🏗️ $(BOLD_YELLOW)Make: $(NO_COLOR)Compilation done\n"
CLEANED		=	echo "\n💧 $(BOLD_YELLOW)Clean: $(NO_COLOR)Removed all the \".o\" files \n"
FCLEANED	=	echo "\n🧼 $(BOLD_YELLOW)Fclean: $(NO_COLOR)Removed the executables \n"

all : $(NAME)

$(NAME) : $(OBJ)
	@$(COMP_START)
	@make -C $(LIBFT)
	cc $(CFLAGS) $(OBJ) -o so_long ./libft/libft.a -ldl -lm -lpthread -LMLX42/build -lmlx42 -IMLX42/include -lglfw
	@$(COMP_END)

clean :
	rm -f $(OBJ)
	@make clean -C $(LIBFT)
	@$(CLEANED)

fclean : clean
	rm -f $(NAME)
	rm -f $(LIBFT)/libft.a
	@$(FCLEANED)

re : fclean all

.PHONY : all clean fclean re