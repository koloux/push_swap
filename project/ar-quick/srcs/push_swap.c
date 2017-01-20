/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 15:49:26 by nhuber            #+#    #+#             */
/*   Updated: 2017/01/20 18:37:53 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_stk	*stk_a;
	t_stk	*stk_b;

	av++;
	ac--;
	if (error_nbr(ac, av) != 0)
		return (0);
	else
	{
		stk_a = stack_construct(av, ac);
		stk_b = stack_construct(NULL, ac);
		if (stk_a->stk->top > 0 && solve_order(stk_a) != 1)
		{
			solve_stack(stk_a, stk_b);
			cmd_print(stk_a);
		}
		clean_stack(&stk_a);
		clean_stack(&stk_b);
	}
	return (0);
}
