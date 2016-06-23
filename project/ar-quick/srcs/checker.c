/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 09:11:19 by nhuber            #+#    #+#             */
/*   Updated: 2016/06/23 17:58:29 by nhuber           ###   ########.fr       */
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
		instr[1] == 'b' ? sa->push(sa, sb) : sa->push(sb, sa);
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

int			main(int ac, char **av)
{
	char	*buff;
	t_stk	*stk_a;
	t_stk	*stk_b;

	buff = NULL;
	ac--;
	av++;
	if (error_nbr(ac, av) != 0)
		return (0);
	else
	{
		stk_a = stack_construct(av, ac);
		stk_b = stack_construct(NULL, ac);
		while (get_next_line(STDIN_FILENO, &buff) > 0)
		{
			if (error_instr(buff) == 0)
				return (0);
			else
				do_instr(buff, stk_a, stk_b);
		}
		(solve_order(stk_a) == 1 ? write(1, "OK\n", 3) : write(1, "KO\n", 3));
	}
	info(stk_a, stk_b, ac);
	return (0);
}
