/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rev_sorted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:21:29 by nprimo            #+#    #+#             */
/*   Updated: 2021/12/20 17:24:17 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_rev_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->num < (stack->next)->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}
