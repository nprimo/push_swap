/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:26:26 by nprimo            #+#    #+#             */
/*   Updated: 2022/01/07 15:25:21 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort3(t_stack *stack, char **comm)
{
	char	*tmp;

	tmp = *comm;
	if (ft_stcsize(stack) == 2)
	{
		*comm = ft_strjoin(*comm, "sa\n");
		free(tmp);
		if (!(*comm))
			return (0);
		return (1);
	}
	if (is_rev_sorted(stack))
		*comm = ft_strjoin(*comm, "ra\nsa\n");
	else if (pos_min(stack) == 0)
		*comm = ft_strjoin(*comm, "sa\nra\n");
	else if (pos_min(stack) == 2)
		*comm = ft_strjoin(*comm, "rra\n");
	else if (stack->num > ft_stclast(stack)->num)
		*comm = ft_strjoin(*comm, "ra\n");
	else
		*comm = ft_strjoin(*comm, "sa\n");
	free(tmp);
	if (!(*comm))
		return (0);
	return (1);
}
