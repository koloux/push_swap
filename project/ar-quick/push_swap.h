/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 18:15:55 by nhuber            #+#    #+#             */
/*   Updated: 2016/05/31 16:38:21 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
//# include "libft.h"
# include <stdlib.h>

typedef struct	s_item
{
	int			*nb;
	int			top;
}				t_item;

typedef struct	s_stk
{
	//functions
	t_item		*stk;
}				t_stk;

#endif
