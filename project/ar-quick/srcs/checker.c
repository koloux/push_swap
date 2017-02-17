/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 09:11:19 by nhuber            #+#    #+#             */
/*   Updated: 2017/02/17 10:41:34 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_instrr(char *instr, t_stk *sa, t_stk *sb)
{
	if (ft_strlen(instr) == 2)
	{
		if (instr[1] == 'r')
		{
			sb->rot(sb);
			sa->rot(sa);
		}
		else
			instr[1] == 'b' ? sb->rot(sb) : sa->rot(sa);
	}
	else
	{
		if (instr[2] == 'r')
		{
			sb->rev(sb);
			sa->rev(sa);
		}
		else
			instr[2] == 'b' ? sb->rev(sb) : sa->rev(sa);
	}
}

static void	do_instr(char *instr, t_stk *sa, t_stk *sb)
{
	if (instr[0] == 'p')
		instr[1] == 'b' ? sa->push(sa, sb, -1) : sa->push(sb, sa, -1);
	if (instr[0] == 's')
	{
		if (instr[1] == 's')
		{
			sb->swap(sb);
			sa->swap(sa);
		}
		else
			instr[1] == 'b' ? sb->swap(sb) : sa->swap(sa);
	}
	if (instr[0] == 'r')
		do_instrr(instr, sa, sb);
}

static int	checker(t_stk *stk_a, t_stk *stk_b)
{
	char	*buff;

	buff = NULL;
	while (get_next_line(STDIN_FILENO, &buff) > 0)
	{
		if (error_instr(buff) == 0)
		{
			free(buff);
			return (0);
		}
		else
			do_instr(buff, stk_a, stk_b);
		free(buff);
	}
	if (TOP_B == -1)
		(solve_order(stk_a) == 1 ? write(1, "OK\n", 3) : write(1, "KO\n", 3));
	else
		write(1, "KO\n", 3);
	return (1);
}

int			main(int ac, char **av)
{
	t_stk	*stk_a;
	t_stk	*stk_b;

	ac--;
	av++;
	if (ac == 0 || error_nbr(ac, av) != 0)
		return (0);
	else
	{
		stk_a = stack_construct(av, ac);
		stk_b = stack_construct(NULL, ac);
		checker(stk_a, stk_b);
		clean_stack(&stk_a);
		clean_stack(&stk_b);
	}
	return (0);
}
