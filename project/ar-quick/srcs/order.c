/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 18:01:12 by nhuber            #+#    #+#             */
/*   Updated: 2016/06/23 18:10:55 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	solve_order(t_stk *stack)
{
	int	i;

	i = stack->stk->top;
	while (i > 0)
	{
		if (stack->stk->nb[i] > stack->stk->nb[i - 1])
			return (0);
		i--;
	}
	return (1);
}
