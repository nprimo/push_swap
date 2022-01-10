/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 15:48:42 by nprimo            #+#    #+#             */
/*   Updated: 2022/01/07 17:58:20 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	partition(t_stack **stc_a, t_stack **stc_b, char **comm)
{
	t_stack	*pivot;

	pivot = ft_stclast(*stc_a);
	while (*stc_a != pivot)
	{
		if ((*stc_a)->num < pivot->num)
		{
			if (!add_op(stc_a, stc_b, "pb", comm))
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
	return (1);
}

static int	get_pos_max(t_stack *stack)
{
	int	pos;
	int	pos_max;
	int	max;

	pos_max = -1;
	max = INT_MIN;
	pos = 0;
	while (stack)
	{
		if (stack->num >= max)
		{
			pos_max = pos;
			max = stack->num;
		}
		stack = stack->next;
		pos++;
	}
	return (pos_max);
}

static int	put_back(t_stack **stc_a, t_stack **stc_b, char **comm)
{
	int		size;

	size = ft_stcsize(*stc_b);
	if (get_pos_max(*stc_b) == 0)
	{
		if (!add_op(stc_a, stc_b, "pa", comm))
			return (0);
		return (1);
	}
	if (get_pos_max(*stc_b) > size / 2)
	{
		if (!add_op(stc_a, stc_b, "rrb", comm))
			return (0);
	}
	else
	{
		if (!add_op(stc_a, stc_b, "rb", comm))
			return (0);
	}
	put_back(stc_a, stc_b, comm);
	return (1);
}

char	*quick_sort(t_stack *stc_a)
{
	t_stack	*stc_b;
	char	*comm;

	comm = ft_strdup("");
	if (!comm)
		return (NULL);
	stc_b = NULL;
	while (stc_a)
	{
		if (!partition(&stc_a, &stc_b, &comm))
			return (NULL);
	}
	while (stc_b)
	{
		if (!put_back(&stc_a, &stc_b, &comm))
			return (NULL);
	}
	return (comm);
}
