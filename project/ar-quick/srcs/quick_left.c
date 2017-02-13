/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_left.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 15:06:38 by nhuber            #+#    #+#             */
/*   Updated: 2017/02/10 11:00:50 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	quick_left_med(t_stk *stk_a, t_stk *stk_b, int nb)
{
	int	i;
	int	c;
	int	med;

	med = check_med(stk_a, nb);
	i = 0;
	c = 0;
	while (i <= nb && check_median(stk_a, med, nb, 0) != 0)
	{
		if (STK_A->nb[TOP_A] >= med)
		{
			stk_a->rot(stk_a);
			cmd_add_right(stk_a, 3);
			c++;
		}
		else
			stk_a->push(stk_a, stk_b, 1);
		i++;
	}
	while (c > 0 && (nb / 2 + nb % 2) != TOP_A + 1)
	{
		stk_a->rev(stk_a);
		cmd_add_right(stk_a, 1);
		c--;
	}
}

int			quick_left(t_stk *stk_a, t_stk *stk_b, int nb)
{
	if (nb <= 2)
	{
		if (nb == 2 && STK_A->nb[TOP_A] > STK_A->nb[TOP_A - 1])
		{
			stk_a->swap(stk_a);
			cmd_add_right(stk_a, 2);
		}
		return (1);
	}
	quick_left_med(stk_a, stk_b, nb);
	quick_left(stk_a, stk_b, nb / 2 + nb % 2);
	quick_right(stk_a, stk_b, nb / 2);
	return (0);
}
