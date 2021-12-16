/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:34:09 by nprimo            #+#    #+#             */
/*   Updated: 2021/12/16 11:38:41 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_list **stack)
{
	t_list	*curr_head;
	t_list	*curr_last;
	int		len;

	len = ft_lstsize(*stack);
	if (len < 2 || !(*stack))
		return ;
	curr_head = *stack;
	curr_last = ft_lstlast(*stack);
	*stack = (*stack)->next;
	curr_head->next = NULL;
	curr_last->next = curr_head;
}
