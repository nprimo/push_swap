/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:49:56 by nprimo            #+#    #+#             */
/*   Updated: 2021/12/16 12:03:48 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rev_rotate(t_list **stack)
{
	t_list	*new_last;
	t_list	*curr_last;
	int		size;

	size = ft_lstsize(*stack);
	if (size < 2 || !(*stack))
		return ;
	curr_last = ft_lstlast(*stack);
	new_last = *stack;
	while (new_last->next != curr_last)
		new_last = new_last->next;
	new_last->next = NULL;
	curr_last->next = *stack;
	*stack = curr_last;
}
