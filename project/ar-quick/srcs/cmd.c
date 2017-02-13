/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 14:47:27 by nhuber            #+#    #+#             */
/*   Updated: 2017/02/13 09:00:43 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd_add_right(t_stk *stack, int cmd)
{
	if (cmd % 3 == 1)
		cmd == 1 ? cmd_join(&stack->op, "rra\n") :
			cmd_join(&stack->op, "rrr\n");
	if (cmd % 3 == 2)
		cmd == 2 ? cmd_join(&stack->op, "sa\n") : cmd_join(&stack->op, "ss\n");
	if (cmd % 3 == 0)
		cmd == 3 ? cmd_join(&stack->op, "ra\n") : cmd_join(&stack->op, "rr\n");
}

void	cmd_add_left(t_stk *stack, int cmd)
{
	if (cmd % 3 == 1)
		cmd == 1 ? cmd_join(&stack->op, "rrb\n") :
			cmd_join(&stack->op, "rrr\n");
	if (cmd % 3 == 2)
		cmd == 2 ? cmd_join(&stack->op, "sb\n") : cmd_join(&stack->op, "ss\n");
	if (cmd % 3 == 0)
		cmd == 3 ? cmd_join(&stack->op, "rb\n") : cmd_join(&stack->op, "rr\n");
}

void	cmd_join(char **op, char *cmd)
{
	char	*tmp;

	if (*op == NULL)
		*op = ft_strdup(cmd);
	else
	{
		tmp = *op;
		*op = ft_strjoin(tmp, cmd);
		ft_memdel((void *)&tmp);
	}
}

void	cmd_print(t_stk *stack)
{
	int	i;

	i = 0;
	while (stack->op[i])
		i++;
	write(1, stack->op, i);
}
