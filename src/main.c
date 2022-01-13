/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:20:32 by nprimo            #+#    #+#             */
/*   Updated: 2022/01/13 21:48:25 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	return_error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (0);
}

static int	ft_sort(t_stack **stc_a, t_stack **stc_b, char **comm)
{
	if (is_sorted(*stc_a))
		return (1);
	if (ft_stcsize(*stc_a) <= 3)
	{
		if (!sort3(stc_a, stc_b, comm))
			return (0);
	}
	else if (ft_stcsize(*stc_a) <= 5)
	{
		if (!sort5(stc_a, stc_b, comm))
			return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*stc_a;
	t_stack	*stc_b;
	char	*comm;

	stc_b = NULL;
	if (ac > 1)
	{
		stc_a = init_stack(ac, av);
		comm = ft_strdup("");
		if (!stc_a || !comm)
			return (return_error());
		if (!ft_sort(&stc_a, &stc_b, &comm))
			return (0);
		ft_putstr_fd(comm, 1);
		ft_stcclear(&stc_a);
		free(comm);
	}
	return (1);
}
