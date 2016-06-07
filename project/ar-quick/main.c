/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 15:49:26 by nhuber            #+#    #+#             */
/*   Updated: 2016/06/07 11:14:37 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	int		stk[ac];
	t_stk	*stk_a;

	(void)av;
	stk[0] = 1;
	stk[1] = 2;
	stk[2] = 3;
	stk[3] = 4;
	stk_a = (t_stk *)malloc(sizeof(t_stk));

	return (0);
}
