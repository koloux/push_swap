/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 18:22:07 by nhuber            #+#    #+#             */
/*   Updated: 2017/02/09 16:53:21 by nhuber           ###   ########.fr       */
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
		while (j < ac && nbrs[i] != nbrs[j])
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

static int	error_digit(char *nbr)
{
	int	er;
	int	i;

	i = (nbr[0] == '-' ? 1 : 0);
	er = 0;
	while (nbr[i])
	{
		if (!ft_isdigit(nbr[i]))
			er++;
		i++;
	}
	return (er);
}

int			error_nbr(int ac, char **av)
{
	int	i;
	int	er;
	int	nbrs[ac];

	i = 0;
	er = 0;
	while (av[i])
	{
		nbrs[i] = ft_atoi(av[i]);
		if (error_not_int(av[i], nbrs[i]) || error_digit(av[i]))
			er++;
		i++;
	}
	er += error_duplicate(nbrs, ac);
	er += error_case(av);
	if (er != 0)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		er++;
	}
	return (er);
}

int			error_instr(char *instr)
{
	int	er;

	er = 0;
	if (instr == NULL)
		return (1);
	if (ft_strlen(instr) == 2 && instr[0] == 's'
				&& (instr[1] == 'a' || instr[1] == 'b'
				|| instr[1] == 's'))
		er++;
	if (ft_strlen(instr) == 2 && instr[0] == 'p'
				&& (instr[1] == 'a' || instr[1] == 'b'))
		er++;
	if (instr[0] == 'r')
	{
		if (ft_strlen(instr) == 2 &&
				(instr[1] == 'a' || instr[1] == 'b' || instr[1] == 'r'))
			er++;
		if (ft_strlen(instr) == 3 && instr[1] == 'r' &&
				(instr[1] == 'a' || instr[1] == 'b' || instr[1] == 'r'))
			er++;
	}
	if (er == 0 && instr[0] != '\0')
		ft_putstr_fd("Error\n", STDERR_FILENO);
	return (er);
}
