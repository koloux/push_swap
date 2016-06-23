/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 18:15:55 by nhuber            #+#    #+#             */
/*   Updated: 2016/06/23 17:01:22 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_item
{
	int			*nb;
	int			top;
}				t_item;

typedef struct	s_stk
{
	void		(*swap)(void *);
	void		(*push)(void *, void *);
	void		(*rot)(void *);
	void		(*rev)(void *);
	char		*op;
	t_item		*stk;
}				t_stk;

t_stk			*stack_construct(char **param, int top);
t_item			*item_construct(char **param, int top);
void			solve_stack(t_stk *stk_a, t_stk *stk_b);
int				solve_order(t_stk *stack);
int				get_min(t_stk *stack);
int				get_max(t_stk *stack);
void			cmd_add(t_stk *stack, char *cmd);
void			cmd_print(t_stk *stack);
int				error_nbr(int ac, char **av);
int				error_instr(char *instr);

void			info(t_stk *stk_a, t_stk *stk_b, int ac);
#endif
