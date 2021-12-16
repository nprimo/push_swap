/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:21:00 by nprimo            #+#    #+#             */
/*   Updated: 2021/12/16 11:29:51 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_list **getter, t_list **giver)
{
	t_list	*curr_head;
	t_list	*new_head;

	if (!(*giver))
		return ;
	curr_head = *giver;
	new_head = (*giver)->next;
	curr_head->next = NULL;
	ft_lstadd_front(getter, curr_head);
	*giver = new_head;
}
