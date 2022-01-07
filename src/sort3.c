/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:26:26 by nprimo            #+#    #+#             */
/*   Updated: 2022/01/07 19:00:43 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*sort3(t_stack *stack)
{
	char	*comm;

	if (ft_stcsize(stack) == 2)
	{
		comm = ft_strdup("sa\n");
		if (!(comm))
			return (NULL);
		return (comm);
	}
	if (is_rev_sorted(stack))
		comm = ft_strdup("ra\nsa\n");
	else if (pos_min(stack) == 0)
		comm = ft_strdup("sa\nra\n");
	else if (pos_min(stack) == 2)
		comm = ft_strdup("rra\n");
	else if (stack->num > ft_stclast(stack)->num)
		comm = ft_strdup("ra\n");
	else
		comm = ft_strdup("sa\n");
	if (!(comm))
		return (NULL);
	return (comm);
}
