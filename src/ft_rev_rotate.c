/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:49:56 by nprimo            #+#    #+#             */
/*   Updated: 2021/12/20 12:22:56 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rev_rotate(t_stack **stack)
{
	t_stack	*new_last;
	t_stack	*curr_last;
	int		size;

	size = ft_stcsize(*stack);
	if (size < 2 || !(*stack))
		return ;
	curr_last = ft_stclast(*stack);
	new_last = *stack;
	while (new_last->next != curr_last)
		new_last = new_last->next;
	new_last->next = NULL;
	curr_last->next = *stack;
	*stack = curr_last;
}
