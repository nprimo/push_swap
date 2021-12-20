/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stcclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 19:41:56 by nprimo            #+#    #+#             */
/*   Updated: 2021/12/20 19:46:43 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stcclear(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		free(head);
		head = tmp->next;
	}
}
