/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_right.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 15:24:43 by nhuber            #+#    #+#             */
/*   Updated: 2017/02/08 15:35:13 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	quick_right_med(t_stk *stk_a, t_stk *stk_b, int nb)
{
	int	med;
	int	i;
	int	c;

	med = check_med(stk_b, nb);
	i = 0;
	c = 0;
	while (i <= nb && check_median(stk_b, med, nb, 1) != 0)
	{
		if (STK_B->nb[TOP_B] < med)
		{
			stk_b->rot(stk_b);
			cmd_add_left(stk_a, 3);
			c++;
		}
		if (STK_B->nb[TOP_B] >= med)
			stk_a->push(stk_b, stk_a, 0);
		i++;
	}
	while (c > 0 && (nb / 2 != TOP_B + 1))
	{
		stk_b->rev(stk_b);
		cmd_add_left(stk_a, 1);
		c--;
	}
}

int			quick_right(t_stk *stk_a, t_stk *stk_b, int nb)
{
	if (nb <= 2)
	{
		if (nb == 2 && STK_B->nb[TOP_B] < STK_B->nb[TOP_B - 1])
		{
			stk_b->swap(stk_b);
			cmd_add_left(stk_a, 2);
		}
		while (nb--)
			stk_a->push(stk_b, stk_a, 0);
		return (1);
	}
	quick_right_med(stk_a, stk_b, nb);
	quick_left(stk_a, stk_b, (nb / 2 + nb % 2));
	quick_right(stk_a, stk_b, nb / 2);
	return (0);
}
