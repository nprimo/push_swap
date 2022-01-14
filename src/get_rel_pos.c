/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rel_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 13:21:00 by nprimo            #+#    #+#             */
/*   Updated: 2022/01/14 15:01:25 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_stc_min(t_stack *stc)
{
	int	min;

	min = INT_MAX;
	while (*stc)
	{
		if (stc->num < min)
			min = stc->num;
		stc = stc->next;
	}
	return (min);
}

int	get_rel_pos(t_stack *stc, int num)
{
	int	size;
	int	rel_pos;
	int	pos_min;

	size = ft_stcsize(stc);
	pos_min = get_stcpos(stc, get_stc_min(stc));
	ft_stclast(stc)->next = stc;
	rel_pos = 1;
	while (rel_pos <= size)
	{
		if (get_stcnum(stc, pos_min + pos_rel) > num
			&& get_stcnum(stc, pos_min + pos_rel - 1) < num)
			return (rel_pos);
		rel_pos++;
	}
	return (0);
}
