/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 15:48:42 by nprimo            #+#    #+#             */
/*   Updated: 2022/01/14 19:00:33 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_in_stc(int num, t_stack *stc)
{
	while (stc)
	{
		if (stc->num == num)
			return (1);
		stc = stc->next;
	}
	return (0);
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

static int	partition(t_stack **stc_a, t_stack **stc_b, char **comm,
		t_stack **sorted)
{
	int		pivot;
	int		count;
	int		size;
	char	*op;

	while (is_in_stc((*stc_a)->num, *sorted) || get_pos_min(*stc_a) == 0)
	{
		if (!add_op(stc_a, stc_b, "pb", comm))
			return (0);
	}
	pivot = (*stc_a)->num;
	if (!add_op(stc_a, stc_b, "pb\nrb", comm))
		return (0);
	count = 0;
	size = ft_stcsize(*stc_a);
	while (count < size && !is_in_stc((*stc_a)->num, *sorted))
	{
		if ((*stc_a)->num < pivot)
		{
			if (!add_op(stc_a, stc_b, "pb", comm))
				return (0);
		}
		else
		{
			if (!add_op(stc_a, stc_b, "ra", comm))
				return (0);
		}
		count++;
	}
	if (*stc_a && is_in_stc((*stc_a)->num, *sorted))
		op = ft_strdup("rrb\npb");
	else
		op = ft_strdup("rrb");
	if (!add_op(stc_a, stc_b, op, comm))
		return (0);
	ft_stcadd_back(sorted, ft_stcnew(pivot));
	free(op);
	return (1);
}

static int	partition_rev(t_stack **stc_a, t_stack **stc_b, char **comm,
		t_stack **sorted)
{
	int		pivot;
	int		count;
	int		size;
	char	*op;

	while (is_in_stc((*stc_b)->num, *sorted) || get_pos_max(*stc_b) == 0)
	{
		if (!add_op(stc_a, stc_b, "pa", comm))
			return (0);
	}
	pivot = (*stc_b)->num;
	if (!add_op(stc_a, stc_b, "pa\nra", comm))
		return (0);
	count = 0;
	size = ft_stcsize(*stc_b);
	while (count < size && !is_in_stc((*stc_b)->num, *sorted))
	{
		if ((*stc_b)->num > pivot)
		{
			if (!add_op(stc_a, stc_b, "pa", comm))
				return (0);
		}
		else
		{
			if (!add_op(stc_a, stc_b, "rb", comm))
				return (0);
		}
		count++;
	}
	if (*stc_b && is_in_stc((*stc_b)->num, *sorted))
		op = ft_strdup("rra\npa");
	else
		op = ft_strdup("rra");
	if (!add_op(stc_a, stc_b, op, comm))
		return (0);
	ft_stcadd_back(sorted, ft_stcnew(pivot));
	free(op);
	return (1);
}

int	quick_sort(t_stack **stc_a, t_stack **stc_b, char **comm)
{
	t_stack	*sorted;

	sorted = NULL;
	while (!is_sorted(*stc_a))
	{
		while (*stc_a && !is_sorted(*stc_a))
		{
			if (!partition(stc_a, stc_b, comm, &sorted))
				return (0);
		}
		while (*stc_b && !is_rev_sorted(*stc_b))
		{
			if (!partition_rev(stc_a, stc_b, comm, &sorted))
				return (0);
		}
		while (is_sorted(*stc_a) && is_rev_sorted(*stc_b) && *stc_b)
		{
			if (!add_op(stc_a, stc_b, "pa", comm))
				return (0);
		}
	}
	ft_stcclear(&sorted);
	return (1);
}
