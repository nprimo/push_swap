/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stcadd_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 18:19:06 by nprimo            #+#    #+#             */
/*   Updated: 2022/01/15 18:39:56 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stcadd_pos(t_stack **stc, t_stack *new, int pos)
{
	t_stack	*head;
	t_stack	*curr_prev;
	t_stack	*curr;
	int		count;

	if (pos == 0)
	{
		ft_stcadd_front(stc, new);
		return ;
	}
	count = 0;
	head = *stc;
	while (count != pos && head)
	{
		curr_prev = head;
		head = head->next;
		curr = head;
		count++;
	}
	curr_prev->next = new;
	new->next = curr;
}

/*
#include <stdio.h>

int	main()
{
	t_stack *head;
	t_stack *h;

	head = NULL;
	ft_stcadd_back(&head, ft_stcnew(0));
	ft_stcadd_back(&head, ft_stcnew(1));
	ft_stcadd_back(&head, ft_stcnew(2));
	ft_stcadd_back(&head, ft_stcnew(3));
	h = head;
	while (head)
	{
		printf("%d -- ", head->num);
		head = head->next;
	}
	printf("\n\n");
	ft_stcadd_pos(&h, ft_stcnew(9), 0);
	while (h)
	{
		printf("%d -- ", h->num);
		h = h->next;
	}
}
*/
