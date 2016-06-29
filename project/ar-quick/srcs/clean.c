/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 09:32:12 by nhuber            #+#    #+#             */
/*   Updated: 2016/06/29 14:11:05 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	clean_item(t_item **item)
{
	ft_memdel((void *)&(*item)->nb);
	ft_memdel((void *)&(*item));
	return (0);
}

void		clean_stack(t_stk **stack)
{
	t_item	**tmp;

	tmp = &(*stack)->stk;
	clean_item(tmp);
	ft_memdel((void *)&(*stack)->op);
	ft_memdel((void *)&(*stack));
}
