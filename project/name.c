/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 13:19:10 by nhuber            #+#    #+#             */
/*   Updated: 2016/05/25 11:14:03 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill(t_stack *stk, char **nb, int len)
{
	while (nb[len] && len > 0)
	{
		if (error_nbr(nb[len]))
			return ;
		else
			stk->stack[++stk->top] = ft_atoi(nb[len]);
		len--;
	}
}

int		error_nbr(char *nbr)
{
	int	i;

	i = 0;
	if (*nbr == '-')
		nbr++;
	while (nbr[i])
	{
		if (!(ft_isdigit(nbr[i])) || i > 10)
			return (-1);
		i++;
	}
	return (0);
}
