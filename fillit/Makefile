# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ale-naou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/30 12:43:22 by ale-naou          #+#    #+#              #
#    Updated: 2015/12/31 18:05:01 by fgiraud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH	= ./src/
OBJ_PATH	= lib/obj/
INC_PATH	= ./include/
LIB_PATH	= ./lib

NAME		= fillit
CC			= gcc
CFLAGS		= -Wall -Werror	-Wextra

SRC_NAME	= ft_error.c ft_mapopti.c ft_resolve.c ft_tetrovalid.c main.c
OBJ_NAME	= $(SRC_NAME.c=.o)
LIB_NAME	= libft.a

SRC			= $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ			= $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC			= $(addprefix -I, $(INC_PATH))
LIB			= $(LIB_PATH)$(LIB_NAME)


all : $(NAME)

$(NAME) :
		@make -C lib $(OBJ)
		$(CC) $(CFLAGS) -L$(LIB_PATH) -lft $(SRC) $(INC) -o $(NAME) $(OBJ)

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
		@mkdir $(OBJ_PATH) 2> /dev/null || true
		$(CC) $(CFLAGS) $(LIB) $(INC) -o $@ -c $<
clean :
		rm -rf $(OBJ_PATH)
		@make clean -C lib

fclean : clean
		rm -fv $(NAME)
		@make fclean -C lib

re : fclean all

norme :
		norminette $(SRC)
		norminette $(INC_PATH)*.h
		norminette $(LIB_PATH)

.PHONY : all clean fclean re norme lib
