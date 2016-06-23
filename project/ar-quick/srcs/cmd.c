/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 14:47:27 by nhuber            #+#    #+#             */
/*   Updated: 2016/06/23 16:56:48 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd_add(t_stk *stack, char *cmd)
{
	char	*tmp;
	char	*tmp2;

	if (stack->op == NULL)
	{
		if ((tmp = ft_strdup(cmd)) != NULL)
			stack->op = tmp;
	}
	else
	{
		tmp = stack->op;
		if ((tmp2 = ft_strjoin(tmp, cmd)) != NULL)
			stack->op = tmp2;
		free(tmp);
	}
}

void	cmd_print(t_stk *stack)
{
	int	i;

	i = 0;
	while (stack->op[i])
		i++;
	write(1, &(stack->op), i);
}
