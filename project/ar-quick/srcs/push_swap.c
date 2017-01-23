/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 15:49:26 by nhuber            #+#    #+#             */
/*   Updated: 2017/01/23 14:46:45 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap(int ac, char **av)
{
	t_stk	*stk_a;
	t_stk	*stk_b;

	stk_a = stack_construct(av, ac);
	stk_b = stack_construct(NULL, ac);
	if (stk_a->stk->top > 0 && solve_order(stk_a) != 1)
	{
		(ac <= 13) ? soft_solve(stk_a, stk_b) : solve_stack(stk_a, stk_b);
		cmd_print(stk_a);
	}
	clean_stack(&stk_a);
	clean_stack(&stk_b);
}

int			main(int ac, char **av)
{
	av++;
	ac--;
	if (error_nbr(ac, av) != 0)
		return (0);
	else
		push_swap(ac, av);
	return (0);
}
