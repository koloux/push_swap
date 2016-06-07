/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 18:22:07 by nhuber            #+#    #+#             */
/*   Updated: 2016/06/01 15:10:53 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	error_duplicate(int *nbrs, int ac)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac)
	{
		j = i + 1;
		while (nbrs[i] != nbrs[j] && j < ac)
			j++;
		if (j != ac)
			return (1);
		i++;
	}
	return (0);
}

static int	error_not_int(char *av, int nb)
{
	int	strlen;
	int	nblen;

	strlen = ft_strlen(av);
	if ((nb > 0 && av[0] == '-') || (nb < 0 && av[0] != '-'))
		return (1);
	nblen = (nb > 0 ? 0 : 1);
	while (nb != 0)
	{
		nb /= 10;
		nblen++;
	}
	return (nblen != strlen ? 1 : 0);
}

int			error(int ac, char **av)
{
	int	i;
	int	er;
	int	nbrs[ac];

	i = 0;
	er = 0;
	while (av[i])
	{
		nbrs[i] = ft_atoi(av[i]);
		if (error_not_int(av[i], nbrs[i]))
			er++;
		i++;
	}
	er += error_duplicate(nbrs, ac);
	if (er != 0 || ac < 2)
		ft_putstr_fd("Error\n", 1);
	return (er);
}
