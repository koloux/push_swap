/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 09:35:37 by nhuber            #+#    #+#             */
/*   Updated: 2016/06/01 15:18:18 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_push_back(void *stack, int val)
{
	t_item	*new;
	t_stack	*stk;

	stk = (t_stack *)stack;
	if ((new = (t_item *)ft_memalloc(sizeof(t_item))) != NULL)
	{
		new->val = val;
		new->next = new;
		new->prev = new;
		if (stk->items)
		{
			new->next = stk->items;
			new->prev = stk->items->prev;
			stk->items->prev->next = new;
			stk->items->prev = new;
		}
		else
			stk->items = new;
	}
}

static void	stack_push_front(void *stack, int val)
{
	t_stack	*stk;

	stk = (t_stack *)stack;
	stack_push_back(stack, val);
	stk->items = stk->items->prev;
}

static void	stack_pop(void *stack)
{
	t_stack	*stk;
	t_item	*tmp;

	stk = (t_stack *)stack;
	if (stk->items)
	{
		if (stk->items == stk->items->next)
			ft_memdel((void *)&(stk->items));
		else
		{
			tmp = stk->items;
			stk->items->prev->next = stk->items->next;
			stk->items->next->prev = stk->items->prev;
			stk->items = stk->items->next;
			free(tmp);
		}
	}
}

static void	stack_shift(void *stack)
{
	t_stack	*stk;

	ft_putstr("ra");
	stk = (t_stack *)stack;
	if (stk->items)
		stk->items = stk->items->next;
}

t_stack		*stack_construct(void)
{
	t_stack	*stk;

	if ((stk = (t_stack *)ft_memalloc(sizeof(t_stack))) != NULL)
	{
		stk->push_back = &stack_push_back;
		stk->push_front = &stack_push_front;
		stk->pop = &stack_pop;
		stk->shift = &stack_shift;
		stk->items = NULL;
	}
	return (stk);
}
