/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 18:15:55 by nhuber            #+#    #+#             */
/*   Updated: 2016/06/07 17:31:37 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <stdlib.h>
# include <stdio.h>

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
void			cmd_add(t_stk *stack, char *cmd);
void			cmd_print(t_stk *stack);
int				error(int ac, char **av);


#endif
