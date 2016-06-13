/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 15:49:26 by nhuber            #+#    #+#             */
/*   Updated: 2016/06/13 17:48:39 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	info(t_stk *stk_a, t_stk *stk_b, int ac)
{
	int i;

	i = 0;
	while (i < ac)
	{
		if (i <= stk_a->stk->top)
			printf("A : index [%d] = {%d}\n", i, stk_a->stk->nb[i]);
		if (stk_b->stk->top >= 0 && i <= stk_b->stk->top)
			printf("B : index [%d] = {%d}\n", i, stk_b->stk->nb[i]);
		i++;
		//hi
	}
	printf("top-a : %d\n", stk_a->stk->top);
	printf("top-b : %d\n", stk_b->stk->top);
}

int		main(int ac, char **av)
{
	t_stk	*stk_a;
	t_stk	*stk_b;

	av++;
	ac--;
	stk_a = stack_construct(av, ac);
	stk_b = stack_construct(NULL, ac);
	solve_stack(stk_a, stk_b);
	info(stk_a, stk_b, ac);
	return (0);
}
