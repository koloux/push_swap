/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 14:53:07 by nhuber            #+#    #+#             */
/*   Updated: 2016/06/29 17:51:36 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*item_nb(char **param, int top)
{
	int	i;
	int	*nb;

	i = 0;
	if ((nb = (int *)ft_memalloc(sizeof(int) * top)) != NULL)
	{
		if (param != NULL)
		{
			while (param[i])
				nb[--top] = ft_atoi(param[i++]);
		}
		else
		{
			while (i < top - 1)
				nb[i++] = 0;
		}
	}
	return (nb);
}

t_item		*item_construct(char **param, int top)
{
	t_item	*new;

	if ((new = (t_item *)ft_memalloc(sizeof(t_item))) != NULL)
	{
		new->nb = item_nb(param, top);
		new->top = (param == NULL ? -1 : --top);
	}
	return (new);
}
