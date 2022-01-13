/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:59:51 by nprimo            #+#    #+#             */
/*   Updated: 2022/01/13 22:34:16 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_stc_max(t_stack *stc)
{
	int	max;

	max = INT_MIN;
	while (stc)
	{
		if (stc->num > max)
			max = stc->num;
		stc = stc->next;
	}
	return (max);
}

static int	get_rel_pos(t_stack *stc, int num)
{
	int	rel_pos;
	int	pos_max;

	rel_pos = -1;
	pos_max = get_stcpos(stc, get_stc_max(stc));
	while ((pos_max + rel_pos) >= 0)
	{
		if (get_stcnum(stc, pos_max + rel_pos) < num
			&& get_stcnum(stc, pos_max + rel_pos + 1) > num)
			return (rel_pos);
		rel_pos--;
	}
	rel_pos = 1;
	while ((pos_max + rel_pos + 1) < ft_stcsize(stc))
	{
		if (get_stcnum(stc, pos_max + rel_pos) < num
			&& get_stcnum(stc, pos_max + rel_pos + 1) > num)
			return (rel_pos);
		rel_pos++;
	}
	return (0);
}

static int	do_move(t_stack **stc_a, t_stack **stc_b, int move, char **comm)
{
	if (move == 0 && (*stc_a)->num > ft_stclast(*stc_a)->num)
	{
		if (!add_op(stc_a, stc_b, "ra", comm))
			return (0);
	}
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
	pos = get_stcpos(*stc_a, get_stc_max(*stc_a)) + rel_pos;
	if (pos == 0 || pos == (ft_stcsize(*stc_a) - 1))
		move = 0;
	else
	{
		if (pos > (ft_stcsize(*stc_a) / 2 - 1))
			move = ft_stcsize(*stc_a) / 2 - 1 - pos;
		else
			move = pos;
	}
	if (!do_move(stc_a, stc_b, move, comm))
		return (0);
	if (*stc_b)
		return (push2(stc_a, stc_b, comm));
	return (1);
}

int	sort5(t_stack **stc_a, t_stack **stc_b, char **comm)
{
	while (ft_stcsize(*stc_a) > 3)
	{
		if (!add_op(stc_a, stc_b, "pb", comm))
			return (0);
	}
	if (!sort3(stc_a, stc_b, comm))
		return (0);
	if (!push2(stc_a, stc_b, comm))
		return (0);
	while ((*stc_a)->num > ft_stclast(*stc_a)->num)
	{
		if (!add_op(stc_a, stc_b, "ra", comm))
			return (0);
	}	
	return (1);
}
