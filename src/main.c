/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:20:32 by nprimo            #+#    #+#             */
/*   Updated: 2021/12/23 15:34:30 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	return_error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
//	t_stack *stack_b;

	if (ac > 1)
	{
		stack_a = init_stack(ac, av);
		if (!stack_a)
			return (return_error());
	//	stack_b = NULL;
	//	stack_b = init_stack(ac, av);
	}
	ft_putstr_fd("\n", 1);
	return (1);
}
