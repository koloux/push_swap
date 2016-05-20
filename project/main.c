/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 13:09:59 by nhuber            #+#    #+#             */
/*   Updated: 2016/05/20 15:21:54 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack *stack_b;

	stack_a = stack_construct(ac - 1);
	stack_b = stack_construct(ac - 1);
	fill(stack_a, av, (ac - 1));
	printf("|%d|%d|%d|%d|\n", stack_a->stack[0], stack_a->stack[1], stack_a->stack[2], stack_a->stack[3]);
	operate_swap(stack_a);
	//operate_push(stack_a, stack_b);
}
