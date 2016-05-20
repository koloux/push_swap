/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 19:10:14 by nhuber            #+#    #+#             */
/*   Updated: 2016/05/20 14:28:29 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_construct(int size)
{
	t_stack	*new;
	int		*stack;

	if (size != 0 &&
			(new = (t_stack *)malloc(sizeof(t_stack))) != NULL)
	{
		if ((stack = (int *)malloc(sizeof(int) * size)) != NULL)
		{
			new->stack = stack;
			new->top = 0;
			new->max = size;
		}
		else
			ft_memdel((void *)&new);
		return (new);
	}
	return (NULL);
}

