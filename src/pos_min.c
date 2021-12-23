/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 17:09:08 by nprimo            #+#    #+#             */
/*   Updated: 2021/12/23 17:25:07 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pos_min(t_stack *stack)
{
	int	pos;
	int	pos_min;
	int	min;

	pos_min = -1;
	min = INT_MAX;
	pos = 0;
	while (stack)
	{
		if (stack->num <= min)
		{
			pos_min = pos;
			min = stack->num;
		}
		stack = stack->next;
		pos++;
	}
	return (pos_min);
}
