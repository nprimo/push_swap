/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:34:09 by nprimo            #+#    #+#             */
/*   Updated: 2021/12/20 12:17:36 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **stack)
{
	t_stack	*curr_head;
	t_stack	*curr_last;
	int		size;

	size = ft_stcsize(*stack);
	if (size < 2 || !(*stack))
		return ;
	curr_head = *stack;
	curr_last = ft_stclast(*stack);
	*stack = (*stack)->next;
	curr_head->next = NULL;
	curr_last->next = curr_head;
}
