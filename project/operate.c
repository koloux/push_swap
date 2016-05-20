/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 13:57:38 by nhuber            #+#    #+#             */
/*   Updated: 2016/05/20 14:50:13 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	operate_swap(t_stack *stk)
{
	int	tmp;

	if (stk->top > 1)
	{
		tmp = stk->stack[stk->top - 1];
		stk->stack[stk->top - 1] = stk->stack[stk->top];
		stk->stack[stk->top] = tmp;
	}
}

void	operate_push(t_stack *stk_a, t_stack *stk_b)
{
	int	tmp;

	if (stk_a->top > 1)
	{
		tmp = stk_a->stack[stk_a->top];
		stk_a->stack[stk_a->top--] = 0;
		stk_b->stack[stk_a->top++] = tmp;
	}

}
