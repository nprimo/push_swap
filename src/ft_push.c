/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:21:00 by nprimo            #+#    #+#             */
/*   Updated: 2021/12/20 11:51:30 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack **getter, t_stack **giver)
{
	t_stack	*curr_head;
	t_stack	*new_head;

	if (!(*giver))
		return ;
	curr_head = *giver;
	new_head = (*giver)->next;
	curr_head->next = NULL;
	ft_stcadd_front(getter, curr_head);
	*giver = new_head;
}
