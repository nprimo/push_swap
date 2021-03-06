/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:59:51 by nprimo            #+#    #+#             */
/*   Updated: 2022/01/24 12:20:08 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sort3(t_stack **stc_a, t_stack **stc_b, char **comm)
{
	if (is_sorted(*stc_a))
		return (1);
	if (ft_stcsize(*stc_a) == 2)
	{
		if (!add_op(stc_a, stc_b, "sa", comm))
			return (0);
		return (1);
	}
	if (is_rev_sorted(*stc_a) && add_op(stc_a, stc_b, "ra\nsa", comm))
		return (1);
	else if (get_pos_min(*stc_a) == 0 && add_op(stc_a, stc_b, "sa\nra", comm))
		return (1);
	else if (get_pos_min(*stc_a) == 2 && add_op(stc_a, stc_b, "rra", comm))
		return (1);
	else if ((*stc_a)->num > ft_stclast(*stc_a)->num
		&& add_op(stc_a, stc_b, "ra", comm))
		return (1);
	if (add_op(stc_a, stc_b, "sa", comm))
		return (1);
	return (0);
}

static int	do_move(t_stack **stc_a, t_stack **stc_b, int move, char **comm)
{
	while (move != 0)
	{
		if (move > 0)
		{
			if (!add_op(stc_a, stc_b, "ra", comm))
				return (0);
			move--;
		}
		else
		{
			if (!add_op(stc_a, stc_b, "rra", comm))
				return (0);
			move++;
		}
	}
	if (!add_op(stc_a, stc_b, "pa", comm))
		return (0);
	return (1);
}

static int	push2(t_stack **stc_a, t_stack **stc_b, char **comm)
{
	int	pos;
	int	rel_pos;
	int	move;

	rel_pos = get_rel_pos(*stc_a, (*stc_b)->num);
	pos = get_pos_min(*stc_a) + rel_pos;
	if (pos > ft_stcsize(*stc_a))
		pos = pos - ft_stcsize(*stc_a);
	if (pos > (ft_stcsize(*stc_a) - 1) / 2)
		move = pos - ft_stcsize(*stc_a);
	else
		move = pos;
	if (!do_move(stc_a, stc_b, move, comm))
		return (0);
	if (*stc_b)
		return (push2(stc_a, stc_b, comm));
	return (1);
}

static int	put_min_top(t_stack **stc_a, t_stack **stc_b, char **comm)
{
	int		pos_min;
	char	*op;

	pos_min = get_pos_min(*stc_a);
	if (pos_min > ((ft_stcsize(*stc_a) - 1) / 2))
		op = ft_strdup("rra");
	else
		op = ft_strdup("ra");
	if (!op)
		return (0);
	while ((*stc_a)->num > ft_stclast(*stc_a)->num)
	{
		if (!add_op(stc_a, stc_b, op, comm))
			return (0);
	}	
	free(op);
	return (1);
}

int	sort_small_stc(t_stack **stc_a, t_stack **stc_b, char **comm)
{
	while (ft_stcsize(*stc_a) > 3)
	{
		if (!add_op(stc_a, stc_b, "pb", comm))
			return (0);
	}
	if (!sort3(stc_a, stc_b, comm))
		return (0);
	if (*stc_b && !push2(stc_a, stc_b, comm))
		return (0);
	if (!put_min_top(stc_a, stc_b, comm))
		return (0);
	return (1);
}
