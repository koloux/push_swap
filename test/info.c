/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 17:23:03 by nhuber            #+#    #+#             */
/*   Updated: 2017/01/16 13:41:06 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	info(t_stk *stk_a, t_stk *stk_b, int ac)
{
	int i;

	i = 0;
	while (i < ac)
	{
		if (i <= stk_a->stk->top)
			printf("A : index [%d] = {%d}\n", i, stk_a->stk->nb[i]);
		i++;
	}
	i = 0;
	while (i < ac)
	{
		if (stk_b->stk->top >= 0 && i <= stk_b->stk->top)
			printf("B : index [%d] = {%d}\n", i, stk_b->stk->nb[i]);
		i++;
	}
	printf("top-a : %d\n", stk_a->stk->top);
	printf("top-b : %d\n", stk_b->stk->top);
}
