/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 11:14:07 by nhuber            #+#    #+#             */
/*   Updated: 2016/05/25 13:22:27 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve(t_stack *stk_a, t_stack *stk_b)
{
	int	max;

	max = -2147483648;
	while (stk_a->top >= 0)
	{
		max = (max < stk_a->stack[stk_a->top] ? stk_a->stack[stk_a->top]: max);
		if (stk_b->stack[stk_b->max] != stk_a->stack[stk_a->top])
			operate_push(stk_a, stk_b);
		else
			stk_a->stack[stk_a->top--] = 0;
	}
	while (stk_b->top >= 0 && stk_b->stack[stk_b->top] > stk_b->max)
		operate_push(stk_b, stk_a);
	stk_b->stack[++stk_b->max] = max;
	stk_b->top++;
}
