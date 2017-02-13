/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 10:14:57 by nhuber            #+#    #+#             */
/*   Updated: 2017/02/10 11:18:56 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_swap(void *stack)
{
	int		tmp;
	t_stk	*s;

	s = (t_stk *)stack;
	if (s->stk->top > 0)
	{
		tmp = s->stk->nb[s->stk->top];
		s->stk->nb[s->stk->top] = s->stk->nb[s->stk->top - 1];
		s->stk->nb[s->stk->top - 1] = tmp;
	}
}

static void	stack_push(void *stack_a, void *stack_b, int sens)
{
	t_stk	*sa;
	t_stk	*sb;

	sa = (t_stk *)stack_a;
	sb = (t_stk *)stack_b;
	if (sa->stk->top != -1)
		sb->stk->nb[sb->stk->top++ + 1] = sa->stk->nb[sa->stk->top--];
	if (sens >= 0)
		(sens == 1) ? cmd_join(&sa->op, "pb\n") : cmd_join(&sb->op, "pa\n");
}

static void	stack_rotate(void *stack)
{
	t_stk	*this;
	int		tmp;
	int		i;

	this = (t_stk *)stack;
	if (this->stk->top > 0)
	{
		i = this->stk->top;
		tmp = this->stk->nb[this->stk->top];
		while (i > 0)
		{
			this->stk->nb[i] = this->stk->nb[i - 1];
			i--;
		}
		this->stk->nb[0] = tmp;
	}
}

static void	stack_reverse(void *stack)
{
	t_stk	*this;
	int		i;
	int		tmp;

	this = (t_stk *)stack;
	if (this->stk->nb != NULL)
	{
		if (this->stk->top > 0)
		{
			i = 0;
			tmp = this->stk->nb[0];
			while (i <= this->stk->top)
			{
				this->stk->nb[i] = this->stk->nb[i + 1];
				i++;
			}
			this->stk->nb[this->stk->top] = tmp;
		}
	}
}

t_stk		*stack_construct(char **param, int top)
{
	t_stk	*stack;

	if ((stack = (t_stk *)ft_memalloc(sizeof(t_stk))) != NULL)
	{
		stack->swap = &stack_swap;
		stack->push = &stack_push;
		stack->rot = &stack_rotate;
		stack->rev = &stack_reverse;
		stack->op = NULL;
		stack->stk = item_construct(param, top);
	}
	return (stack);
}
