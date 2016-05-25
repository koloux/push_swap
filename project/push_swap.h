/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 18:15:55 by nhuber            #+#    #+#             */
/*   Updated: 2016/05/25 11:40:38 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_stack
{
	int			*stack;
	int			top;
	int			max;
}				t_stack;

/*
**	STACK
*/

t_stack	*stack_construct(int size);
void	stack_destruct(t_stack *stack);

void	fill(t_stack *stk, char **nb, int len);
int		error_nbr(char *nbr);

/*
**	SOLVE
*/

void	solve(t_stack *stk_a, t_stack *stk_b);

/*
**	OPERATE
*/

void	operate_swap(t_stack *stk);
void	operate_push(t_stack *stk_a, t_stack *stk_b);

#endif
