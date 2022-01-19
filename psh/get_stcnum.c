/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stcnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 19:57:51 by nprimo            #+#    #+#             */
/*   Updated: 2022/01/13 20:03:10 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stcnum(t_stack *stack, int pos)
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
