/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rel_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 13:21:00 by nprimo            #+#    #+#             */
/*   Updated: 2022/01/14 15:23:22 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_stc_min(t_stack *stc)
{
	int	min;

	min = INT_MAX;
	while (stc)
	{
		if (stc->num < min)
			min = stc->num;
		stc = stc->next;
	}
	return (min);
}

int	get_rel_pos(t_stack *stc, int num)
{
	int		size;
	int		rel_pos;
	int		pos_min;
	t_stack	*last;

	size = ft_stcsize(stc);
	pos_min = get_stcpos(stc, get_stc_min(stc));
	last = ft_stclast(stc);
	last->next = stc;
	rel_pos = 1;
	while (rel_pos <= size)
	{
		if (get_stcnum(stc, pos_min + rel_pos) > num
			&& get_stcnum(stc, pos_min + rel_pos - 1) < num)
		{
			last->next = NULL;
			return (rel_pos);
		}
		rel_pos++;
	}
	last->next = NULL;
	return (0);
}
