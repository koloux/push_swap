/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 15:49:26 by nhuber            #+#    #+#             */
/*   Updated: 2016/06/07 20:15:21 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	info(t_stk *stk_a, t_stk *stk_b, int ac)
{
	int i = 0;
	while (i < ac)
	{
		if (i <= stk_a->stk->top)
			printf("A : index [%d] = {%d}\n", i, stk_a->stk->nb[i]);
		if (stk_b->stk->top >= 0 && i <= stk_b->stk->top)
			printf("B : index [%d] = {%d}\n", i, stk_b->stk->nb[i]);
		i++;
	}
	printf("top-a : %d\n", stk_a->stk->top);
	printf("top-b : %d", stk_b->stk->top);

}

int		main(int ac, char **av)
{
	t_stk	*stk_a;
	t_stk	*stk_b;

	av++;
	ac--;
	stk_a = stack_construct(av, ac);
	stk_b = stack_construct(NULL, ac);
	info(stk_a, stk_b, ac);
	return (0);
}
