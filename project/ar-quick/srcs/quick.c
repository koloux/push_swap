/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 11:29:39 by nhuber            #+#    #+#             */
/*   Updated: 2017/01/20 15:12:54 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 	solve_quick_left(t_stk *stk_a, t_stk *stk_b, int nb)
{
	int	i;
	int	med;

	i = 0;
	if (stk_a->stk->top < 2 || solve_order(stk_a) == 1)
	{
		if (stk_a->stk->nb[1] > stk_a->stk->nb[0])
		{
			stk_a->swap(stk_a);
			cmd_add(stk_a, 2);
		}
		return (0);
	}
	med = get_median(stk_a);
	while (solve_order(stk_a) != 1 || i < nb)
	{
		if (stk_a->stk->nb[i] < med)
		{
			stk_a->rot(stk_a);
			cmd_add(stk_a, 3);
		}
		if (stk_a->stk->nb[i] > med)
		{
			stk_a->push(stk_a, stk_b, 1);
			i--;
		}
		i++;
	}
	solve_quick_left(stk_a, stk_b, nb / 2 + nb % 2);
	return (1);
}
/*
int 	solve_quick_right(t_stk *stk_a, t_stk *stk_b, int nb)
{
	int	i;
	int	med;

	i = 0;
	if (stk_a->stk->top < 2 || solve_order(stk_a) == 1)
	{
		if (stk_a->stk->nb[1] < stk_a->stk->nb[0])
		{
			stk_a->swap(stk_a);
			cmd_add(stk_a, 2);
		}
		return (0);
	}
	med = get_median(stk_a);
	while (solve_order(stk_a) != 1 || i < stk_a->stk->top)
	{
		if (stk_a->stk->nb[i] < med)
		{
			stk_a->rot(stk_a);
			cmd_add(stk_a, 3);
		}
		if (stk_a->stk->nb[i] > med)
		{
			stk_a->push(stk_a, stk_b, 1);
			i--;
		}
		i++;
	}
	solve_quick_right(stk_a, stk_b, );
	return (1);
}
*/
void	solve_stack(t_stk *stk_a, t_stk *stk_b)
{
	solve_quick_left(stk_a, stk_b, stk_a->stk->top + 1);
	info(stk_a, stk_b, 100);	
}
