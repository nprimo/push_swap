/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:35:33 by nprimo            #+#    #+#             */
/*   Updated: 2021/12/16 10:40:25 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*init_stack(int ac, char **av)
{
	t_list	*stack;
	int		pos;

	stack = NULL;
	pos = 1;
	while (pos < ac)
	{
		ft_lstadd_back(&stack, ft_lstnew(av[pos]));
		pos++;
	}
	return (stack);
}
