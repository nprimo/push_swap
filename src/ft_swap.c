/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:54:11 by nprimo            #+#    #+#             */
/*   Updated: 2021/12/20 15:55:09 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **stack)
{
	t_stack	*curr_head;
	t_stack	*new_head;

	if (!(*stack))
		return ;
	curr_head = *stack;
	new_head = (*stack)->next;
	curr_head->next = new_head->next;
	new_head->next = curr_head;
	*stack = new_head;
}
