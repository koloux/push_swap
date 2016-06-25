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
NAME2 = checker
H_DIR = header
F_DIR = srcs
L_DIR = libft
FILES = $(F_DIR)/cmd.c \
		$(F_DIR)/error.c \
		$(F_DIR)/get.c \
		$(F_DIR)/item.c \
		$(F_DIR)/solve.c \
		$(F_DIR)/stack.c \
		$(F_DIR)/get_next_line.c \
		$(F_DIR)/order.c \
		$(F_DIR)/info.c
CHECKER = $(FILES) $(F_DIR)/checker.c
PUSH_SWAP = $(FILES) $(F_DIR)/push_swap.c 
TMP = Makefile~ $(NAME2)~ $(NAME)~ $(FILES:.c=.c~)

all : $(NAME)

$(NAME) :
	@cd $(L_DIR) && $(MAKE)
	@echo Project : $(NAME) and $(NAME2)
	@echo "\t"- Compiler : $(CC)
	@echo "\t"- Flags : $(FLAGS)
	@$(CC) -o $(NAME) $(FLAGS) $(PUSH_SWAP) -I $(H_DIR) -L $(L_DIR) -lft
	@$(CC) -o $(NAME2) $(FLAGS) $(CHECKER) -I $(H_DIR) -L $(L_DIR) -lft

clean :
	@echo clean :"\n\tTemporary and binary files deleted"
	@rm -f $(TMP) $(OBJ)
	@cd $(L_DIR) && $(MAKE) $@

fclean : clean
	@echo fclean :"\n\t"$(NAME) and $(NAME2) deleted
	@rm -f $(NAME)
	@rm -f $(NAME2)
	@cd $(L_DIR) && $(MAKE) $@
	@rm -f libft.a

test : re
	@echo testing with : 3 7 4 9 5 2 6 1
	@./$(NAME) 3 7 4 9 5 2 6 1 | ./$(NAME2) 3 7 4 9 5 2 6 1
	@echo testing with : 3 2 1 0
	@./$(NAME) 3 2 1 0 | ./$(NAME2) 3 2 1 0
	@echo testing with : 2 1 3 6 5 8
	@./$(NAME) 2 1 3 6 5 8 | ./$(NAME2) 2 1 3 6 5 8
	@echo testing with : 4 67 3 87 23
	@./$(NAME) 4 67 3 87 23 | ./$(NAME2) 4 67 3 87 23

norme :
	@echo "\t\tNORME ERROR\n\tif no error nothing will appear\n----------------------------------------------"
	@norminette > ../../test/checking && cat ../../test/checking | grep -B1 "Error"

re : fclean all

.PHONY : all clean fclean re
