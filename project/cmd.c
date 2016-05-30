/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 10:48:55 by nhuber            #+#    #+#             */
/*   Updated: 2016/05/30 11:35:04 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd_add(t_stack *stack, char *cmd)
{
	char	*tmp;
	char	*tmp2;

	if (stack->cmd == NULL)
	{
		if ((tmp = ft_strdup(cmd)) != NULL)
			stack->cmd = tmp;
	}
	else
	{
		tmp = stack->cmd;		
		if ((tmp2 = ft_strjoin(tmp, cmd)) != NULL)
			stack->cmd = tmp2;
		free(tmp);
	}
}

void	cmd_print(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack->cmd[i])
		i++;
	write(1, &(stack->cmd), i);
}
