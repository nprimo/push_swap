/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 19:07:19 by nprimo            #+#    #+#             */
/*   Updated: 2022/01/07 21:34:33 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push_min(t_stack **stc_a, t_stack **stc_b, char **comm)
{
	int	size;

	size = ft_stcsize(*stc_a);
	while (pos_min(*stc_a) != 0)
	{
		if (pos_min(*stc_a) > size / 2)
		{
			if (!add_op(stc_a, stc_b, "rra", comm))
				return (0);
		}
		else
		{
			if (!add_op(stc_a, stc_b, "ra", comm))
				return (0);
		}
	}
	if (!add_op(stc_a, stc_b, "pb", comm))
		return (0);
	if (ft_stcsize(*stc_a) > 1)
		push_min(stc_a, stc_b, comm);
	return (1);
}

char	*ins_sort(t_stack *stc_a)
{
	t_stack	*stc_b;
	char	*comm;

	comm = ft_strdup("");
	if (!comm)
		return (NULL);
	stc_b = NULL;
	if (!push_min(&stc_a, &stc_b, &comm))
		return (NULL);
	while (stc_b)
	{
		if (!add_op(&stc_a, &stc_b, "pa", &comm))
			return (NULL);
	}
	return (comm);
}
