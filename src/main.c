/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:20:32 by nprimo            #+#    #+#             */
/*   Updated: 2022/01/07 15:42:18 by nprimo           ###   ########.fr       */
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
	char	*comm;

	if (ac > 1)
	{
		comm = ft_strdup("");
		stack_a = init_stack(ac, av);
		if (!stack_a || !comm)
			return (return_error());
		if (is_sorted(stack_a))
			return (1);
		if (ft_stcsize(stack_a) <= 3)
		{
			if (!sort3(stack_a, &comm))
				return (return_error());
		}
		ft_putstr_fd(comm, 1);
		free(comm);
	}
	return (1);
}
