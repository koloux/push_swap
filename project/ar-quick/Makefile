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
		$(F_DIR)/check.c \
		$(F_DIR)/error.c \
		$(F_DIR)/error2.c \
		$(F_DIR)/get.c \
		$(F_DIR)/item.c \
		$(F_DIR)/quick_left.c \
		$(F_DIR)/quick_right.c \
		$(F_DIR)/soft_solve.c \
		$(F_DIR)/stack.c \
		$(F_DIR)/get_next_line.c \
		$(F_DIR)/order.c \
		$(F_DIR)/info.c \
		$(F_DIR)/clean.c
CHECKER = $(FILES) $(F_DIR)/checker.c
PUSH_SWAP = $(FILES) $(F_DIR)/push_swap.c 
TMP = Makefile~ $(NAME2)~ $(NAME)~ $(FILES:.c=.c~)

all : $(NAME) $(NAME2)

$(NAME) :
	@cd $(L_DIR) && $(MAKE)
	@echo Project : $(NAME) and $(NAME2)
	@echo "\t"- Compiler : $(CC)
	@echo "\t"- Flags : $(FLAGS)
	@$(CC) -o $(NAME) $(FLAGS) $(PUSH_SWAP) -I $(H_DIR) -L $(L_DIR) -lft

$(NAME2) :
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
	@echo testing with : 0 1 2 3 4
	@./$(NAME) 0 1 2 3 4 | ./$(NAME2) 0 1 2 3 4
	@echo testing with : -1 0 1 2 3
	@./$(NAME) -1 0 1 2 3 | ./$(NAME2) -1 0 1 2 3
	@echo test with : 27 60 71 73 25 28 48 76 83 34 0 5 80 50 55 35 53 52 92 30 15 62 12 88 3 32 66 64 42 69 79 29 56 39 45 94 47 46 16 75 54 72 44 61 89 26 14 13 58 24 37 22 82 90 51 93 10 85 23 77 18 81 57 41 78 84 40 36 74 95 96 65 49 7 98 20 68 2 17 59 31 99 91 8 19 4 6 87 21 1 67 9 38 63 97 43 86 11 70 33
	@./$(NAME) 27 60 71 73 25 28 48 76 83 34 0 5 80 50 55 35 53 52 92 30 15 62 12 88 3 32 66 64 42 69 79 29 56 39 45 94 47 46 16 75 54 72 44 61 89 26 14 13 58 24 37 22 82 90 51 93 10 85 23 77 18 81 57 41 78 84 40 36 74 95 96 65 49 7 98 20 68 2 17 59 31 99 91 8 19 4 6 87 21 1 67 9 38 63 97 43 86 11 70 33 | ./$(NAME2) 27 60 71 73 25 28 48 76 83 34 0 5 80 50 55 35 53 52 92 30 15 62 12 88 3 32 66 64 42 69 79 29 56 39 45 94 47 46 16 75 54 72 44 61 89 26 14 13 58 24 37 22 82 90 51 93 10 85 23 77 18 81 57 41 78 84 40 36 74 95 96 65 49 7 98 20 68 2 17 59 31 99 91 8 19 4 6 87 21 1 67 9 38 63 97 43 86 11 70 33

error : re
	@echo testing with : 1
	@./$(NAME) 1 | ./$(NAME2) 1
	@echo testing with : a
	@./$(NAME) a | ./$(NAME2) a
	@echo testing with : 21474836499
	@./$(NAME) 21474836499 | ./$(NAME2) 21474836499

norme :
	@echo "\t\tNORME ERROR\n----------------------------------------------"
	@norminette > checking
	@cat checking

re : fclean all

.PHONY : all clean fclean re
