/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 18:22:07 by nhuber            #+#    #+#             */
/*   Updated: 2016/05/31 19:38:26 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	error_min_max(char *av)
{
	int	nb;

	nb = ft_atoi(av);
	if ((nb > 0 && av[0] == '-') || (nb < 0 && av[0] != '-'))
		return (1);
	return (0);
}

static int	error_not_int(char *av)
{
	int	len;
	int	i;

	len = ft_strlen(av);
	i = 0;
	if (av[0] == '-')
	{
		len--;
		i++;
	}
	if (len == 10)
		len += error_min_max(av);
	if (len < 10)
	{
		while (ft_isdigit(av[i]))
			i++;
		len += (i != len + 1 ? 1 : 0);
	}
	return (len > 10 ? 1 : 0);
}

int			error(int ac, char **av)
{
	int	i;
	int	er;

	i = 0;
	er = 0;
	while (av[i])
	{
		if (error_not_int(av[i]))
			er++;
		i++;
	}
	if (er != 0 || ac < 2)
		ft_putstr_fd("Error\n", 1);
	return (er);
}
