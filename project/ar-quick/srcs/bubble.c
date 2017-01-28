/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 09:43:58 by nhuber            #+#    #+#             */
/*   Updated: 2017/01/28 20:10:34 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	bubble_index(t_stk *stk_a)
{
	int	i;

	i = 0;
	while (i < TOP_A)
	{
		if (STK_A->nb[i] < STK_A->nb[i + 1])
			return (i);
		i++;
	}
	return (0);
}

/*
void		bubble_left(t_stk *stk_a, t_stk *stk_b)
{
	int	i;

	i = 1;
	while (solve_order(stk_a) != 1 && i < TOP_A + 1)
	{
		while (get_max(stk_a) != STK_A->nb[TOP_A - i])
		{
			if (STK_A->nb[TOP_A] < STK_A->nb[TOP_A - 1])
			{
				stk_a->rot(stk_a);
				solve_right(stk_a, stk_b, 3);
			}
			else if (STK_A->nb[TOP_A]  STK_A->nb[TOP_A - 1])
			{
				stk_a->swap(stk_a);
				solve_right(stk_a, stk_b, 2);
			}
			else
			{
				
			}
		}
		i++;
	}
}
*/

void		bubble_left(t_stk *stk_a, t_stk *stk_b)
{
	int i = 0;
	int j = 0;
	while (solve_order(stk_a) != 1)
	{	
		j = 0;
		i = TOP_A - bubble_index(stk_a) + 1;
		while (solve_order(stk_a) != 1 && get_max(stk_a) != STK_A->nb[TOP_A] && j < i)
		{
			if (STK_A->nb[TOP_A] < STK_A->nb[TOP_A - 1])
			{
				cmd_join(&stk_a->op, "b");
				stk_a->rot(stk_a);
				solve_right(stk_a, stk_b, 3);
			}
			else
			{
				cmd_join(&stk_a->op, "b");
				stk_a->swap(stk_a);
				solve_right(stk_a, stk_b, 2);
			}
			j++;
		}
		if (get_max(stk_a) == STK_A->nb[TOP_A]) 
		{
			stk_a->rot(stk_a);
			solve_right(stk_a, stk_b, 2);
		}
	}
}

