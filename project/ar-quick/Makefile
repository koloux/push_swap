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
		$(F_DIR)/get.c \
		$(F_DIR)/item.c \
		$(F_DIR)/solve.c \
		$(F_DIR)/quick.c \
		$(F_DIR)/bubble.c \
		$(F_DIR)/soft_solve.c \
		$(F_DIR)/stack.c \
		$(F_DIR)/get_next_line.c \
		$(F_DIR)/order.c \
		$(F_DIR)/info.c \
		$(F_DIR)/clean.c
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
	@echo testing with : 0 1 2 3 4
	@./$(NAME) 0 1 2 3 4 | ./$(NAME2) 0 1 2 3 4
	@echo testing with : -1 0 1 2 3
	@./$(NAME) -1 0 1 2 3 | ./$(NAME2) -1 0 1 2 3
	@echo test with : 27 60 71 73 25 28 48 76 83 34 0 5 80 50 55 35 53 52 92 30 15 62 12 88 3 32 66 64 42 69 79 29 56 39 45 94 47 46 16 75 54 72 44 61 89 26 14 13 58 24 37 22 82 90 51 93 10 85 23 77 18 81 57 41 78 84 40 36 74 95 96 65 49 7 98 20 68 2 17 59 31 99 91 8 19 4 6 87 21 1 67 9 38 63 97 43 86 11 70 33
	@./$(NAME) 48 50 41 12 91 52 0 54 59 3 39 92 76 30 86 28 13 47 82 5 83 61 97 84 16 65 96 55 56 44 21 88 98 19 58 68 80 22 87 4 81 8 64 6 53 17 60 99 51 67 37 94 25 9 46 77 27 62 36 42 15 85 70 66 45 40 95 78 1 24 11 71 7 26 69 57 93 75 43 31 74 2 35 29 63 38 20 89 32 23 72 79 49 33 18 73 90 10 34 14 | ./$(NAME2) 48 50 41 12 91 52 0 54 59 3 39 92 76 30 86 28 13 47 82 5 83 61 97 84 16 65 96 55 56 44 21 88 98 19 58 68 80 22 87 4 81 8 64 6 53 17 60 99 51 67 37 94 25 9 46 77 27 62 36 42 15 85 70 66 45 40 95 78 1 24 11 71 7 26 69 57 93 75 43 31 74 2 35 29 63 38 20 89 32 23 72 79 49 33 18 73 90 10 34 14
	@./$(NAME) 30 98 88 27 21 80 13 12 81 38 53 99 5 24 59 41 91 89 7 96 32 75 92 55 77 94 79 73 2 45 61 36 52 68 37 90 4 16 57 18 39 9 19 56 64 86 15 76 31 83 50 71 22 11 51 26 28 1 67 69 60 70 6 87 17 47 93 35 25 85 78 58 72 49 74 44 14 65 0 43 42 23 46 10 34 40 33 48 63 82 95 3 54 97 62 8 20 84 66 29 | ./$(NAME2) 30 98 88 27 21 80 13 12 81 38 53 99 5 24 59 41 91 89 7 96 32 75 92 55 77 94 79 73 2 45 61 36 52 68 37 90 4 16 57 18 39 9 19 56 64 86 15 76 31 83 50 71 22 11 51 26 28 1 67 69 60 70 6 87 17 47 93 35 25 85 78 58 72 49 74 44 14 65 0 43 42 23 46 10 34 40 33 48 63 82 95 3 54 97 62 8 20 84 66 29

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
