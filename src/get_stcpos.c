/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stcpos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 19:57:51 by nprimo            #+#    #+#             */
/*   Updated: 2021/12/25 19:59:41 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stcpos(t_stack *stack, int pos)
{
	int	i;

	i = 0;
	while (stack && i < pos)
	{
		i++;
		stack = stack->next;
	}
	return (stack->num);
}
