/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 18:15:55 by nhuber            #+#    #+#             */
/*   Updated: 2016/06/01 14:06:51 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_item
{
	int				val;
	struct s_item	*next;
	struct s_item	*prev;
}					t_item;

typedef struct		s_stack
{
	void			(*push_back)(void *, int);
	void			(*push_front)(void *, int);
	void			(*pop)(void *);
	void			(*shift)(void *);
	t_item			*items;
}					t_stack;

t_stack				*stack_construct(void);
void				solve_stack(t_stack *stk_a, t_stack *stk_b);
int					error(int ac, char **av);

#endif
