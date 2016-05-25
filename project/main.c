/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 13:09:59 by nhuber            #+#    #+#             */
/*   Updated: 2016/05/25 13:22:25 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pstk(t_stack *stk, int op)
{
	int i = stk->top;
	printf("======%c======\n", (op == 1 ? 'A': 'B'));
	while (i >= 0)
	{
		printf("|%d|", stk->stack[i]);
		i--;
	}
	printf("\nposition(top)(max) :{%d}{%d}", stk->top, stk->max);
	printf("\n=============\n");
}

int		main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack *stack_b;

	stack_a = stack_construct(ac - 1);
	stack_b = stack_construct(ac - 1);
	fill(stack_a, av, (ac - 1));
	int i = 3;
	while (i < 7)
	{	
		if (i > 2)
		{
			pstk(stack_a, 1);
			pstk(stack_b, 2);
		}
		solve(stack_a, stack_b);
			i++;
	}
}
