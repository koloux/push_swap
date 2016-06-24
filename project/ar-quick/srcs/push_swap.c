/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 15:49:26 by nhuber            #+#    #+#             */
/*   Updated: 2016/06/24 17:19:17 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_stk	*stk_a;
	t_stk	*stk_b;

	av++;
	ac--;
	stk_a = stack_construct(av, ac);
	stk_b = stack_construct(NULL, ac);
	solve_stack(stk_a, stk_b);
	cmd_print(stk_a);
	info(stk_a, stk_b, ac);
	return (0);
}
