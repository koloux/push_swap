/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 15:49:26 by nhuber            #+#    #+#             */
/*   Updated: 2016/05/31 16:05:09 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int		main(int ac, char **av)
{
	int		stk[ac];
	t_stack	*stk_a;

	(void)av;
	stk[0] = 1;
	stk[1] = 2;
	stk[2] = 3;
	stk[3] = 4;
	stk_a = (t_stack *)malloc(sizeof(t_stack));
	stk_a->nb = stk;
	stk_a->top = 3;

	printf("%d", stk_a->nb[stk_a->top]);
	return (0);
}
