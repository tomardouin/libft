# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: toardoui <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 13:40:23 by toardoui          #+#    #+#              #
#    Updated: 2018/08/20 18:38:26 by toardoui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
INC_DIR = inc
SRC_DIR = src
OBJ_DIR = obj

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

FLAG = -I $(INC_DIR) -Wall -Werror -Wextra

CC = gcc $(FLAG)

RM = /bin/rm -f

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "Make libft.a :\033[0;32m DONE !\033[0m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "\033[0;32m [OK] \033[0m       \033[0;33m Compiling:\033[0m" $<
	@$(CC) -o $@ -c $<

clean:
	@$(RM) $(OBJ)
	@echo "Make libft clean :\033[0;32m DONE !\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@echo "Make libft fclean :\033[0;32m DONE !\033[0m"

re: fclean all

.PHONY: all clean fclean re
