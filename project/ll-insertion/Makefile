#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/03/07 09:32:29 by nhuber            #+#    #+#             *#
#*   Updated: 2016/04/07 17:41:23 by nhuber           ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = push_swap
HEADER = push_swap.h
F_DIR = ./
L_DIR = libft
FILES = stack.c main.c solve.c error.c 
TMP = Makefile~  $(F_DIR)/header.h~ $(NAME)~ $(FILES:.c=.c~)

all : $(NAME)

$(NAME) :
	@cd $(L_DIR) && $(MAKE)
	@echo Project : $(NAME)
	@echo "\t"- Compiler : $(CC)
	@echo "\t"- Flags : $(FLAGS)
	@$(CC) -o $(NAME) $(FLAGS) $(FILES) -I $(L_DIR) -L $(L_DIR) -lft

clean :
	@echo clean :"\n\tTemporary and binary files deteleted"
	@rm -f $(TMP) $(OBJ)
	@cd $(L_DIR) && $(MAKE) $@

fclean : clean
	@echo fclean :"\n\t"$(NAME) deleted
	@rm -f $(NAME)
	@cd $(L_DIR) && $(MAKE) $@
	@rm -f libft.a

test :
	@cd $(L_DIR) && $(MAKE)
	@echo Project : $(NAME)
	@echo "\t"- Compiler : $(CC)
	@echo "\t"- Flags : $(FLAGS)
	@$(CC) -o $(NAME) $(FLAGS) $(FILES) -I $(L_DIR) -L $(L_DIR) -lft
	@./$(NAME) 2 1 3 6 5 8

norme :
	@echo "\t\tNORME ERROR\n\tif no error nothing will appear\n----------------------------------------------"
	@norminette | grep -B1 "Error" || true > checking
	@cat checking

re : fclean all

.PHONY : all clean fclean re
