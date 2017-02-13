/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 18:15:55 by nhuber            #+#    #+#             */
/*   Updated: 2017/02/13 09:00:27 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# define TOP_A stk_a->stk->top
# define TOP_B stk_b->stk->top
# define STK_A stk_a->stk
# define STK_B stk_b->stk

typedef struct	s_item
{
	int			*nb;
	int			top;
}				t_item;

typedef struct	s_stk
{
	void		(*swap)(void *);
	void		(*push)(void *, void *, int);
	void		(*rot)(void *);
	void		(*rev)(void *);
	char		*op;
	t_item		*stk;
}				t_stk;

int				order_reverse(t_stk *stack);
t_stk			*stack_construct(char **param, int top);
t_item			*item_construct(char **param, int top);
int				solve_order(t_stk *stack);
void			solve_order_reverse(t_stk *stk_a, t_stk *stk_b);
void			solve_stack(t_stk *stk_a, t_stk *stk_b);
int				quick_right(t_stk *stk_a, t_stk *stk_b, int nb);
int				quick_left(t_stk *stk_a, t_stk *stk_b, int nb);
int				get_min(t_stk *stack);
int				get_max(t_stk *stack);
int				get_median(t_stk *stack);
int				get_high(int i, int j, int k);
int				get_small(int i, int j, int k);
int				check_median(t_stk *stack, int med, int nb, int sens);
int				check_med(t_stk *stk_a, int nbelem);
void			cmd_add_right(t_stk *stack, int cmd);
void			cmd_add_left(t_stk *stack, int cmd);
void			cmd_join(char **op, char *cmd);
void			cmd_print(t_stk *stack);
int				error_nbr(int ac, char **av);
int				error_instr(char *instr);
int				error_case(char **av);
void			clean_stack(t_stk **stack);

#endif
