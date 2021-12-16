/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:35:33 by nprimo            #+#    #+#             */
/*   Updated: 2021/12/16 16:39:30 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*init_stack(int ac, char **av)
{
	t_list	*stack;
	int		pos;
	char	**inputs;

	stack = NULL;
	if (ac > 2)
	{
		pos = 1;
		while (pos < ac)
		{
			ft_lstadd_back(&stack, ft_lstnew(av[pos]));
			pos++;
		}
	}
	else
	{
		inputs = ft_split(av[1], ' ');
		pos = 0;
		while (inputs[pos])
		{
			ft_lstadd_back(&stack, ft_lstnew(inputs[pos]));
			pos++;
		}
	}
	return (stack);
}
