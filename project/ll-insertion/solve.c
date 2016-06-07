/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 11:05:10 by nhuber            #+#    #+#             */
/*   Updated: 2016/06/01 15:21:22 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	solve_get_min(t_stack *stack)
{
	t_item	*tmp;
	int		min;

	min = stack->items->val;
	tmp = stack->items->next;
	while (tmp != stack->items)
	{
		if (min > tmp->val)
			min = tmp->val;
		tmp = tmp->next;
	}
	return (min);
}

static int	solve_sort(t_stack *stack)
{
	int		flag;
	int		prev;
	t_item	*tmp;

	flag = 0;
	tmp = stack->items->prev;
	prev = stack->items->val;
	while (tmp != stack->items)
	{
		if (!flag)
			tmp = stack->items;
		flag = 1;
		if (tmp->val < prev)
			return (0);
		prev = tmp->val;
		tmp = tmp->next;
	}
	return (1);
}

static void	solve_init(t_stack *stk_a, t_stack *stk_b)
{
	int		flag;
	int		min;
	t_item	*tmp;

	min = solve_get_min(stk_a);
	flag = 0;
	while (stk_a->items && !solve_sort(stk_a))
	{
		if (flag)
			ft_putchar(' ');
		flag = 1;
		tmp = stk_a->items;
		if (tmp->val == min)
		{
			ft_putstr("pb");
			stk_b->push_front(stk_b, tmp->val);
			stk_a->pop(stk_a);
			min = solve_get_min(stk_a);
		}
		else
			stk_a->shift(stk_a);
	}
}

void		solve_stack(t_stack *stk_a, t_stack *stk_b)
{
	solve_init(stk_a, stk_b);
	while (stk_b->items)
	{
		ft_putstr(" pa");
		stk_a->push_front(stk_a, stk_b->items->val);
		stk_b->pop(stk_b);
	}
	ft_putchar('\n');
}
