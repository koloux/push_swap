/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 11:44:07 by nhuber            #+#    #+#             */
/*   Updated: 2016/06/01 14:10:12 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	int		i;
	t_stack	*stk_a;
	t_stack	*stk_b;

	av++;
	ac--;
	stk_a = stack_construct();
	stk_b = stack_construct();
	if (error(ac, av))
		return (0);
	i = 0;
	while (i < ac)
		stk_a->push_back(stk_a, ft_atoi(av[i++]));
	solve_stack(stk_a, stk_b);
	return (0);
}
