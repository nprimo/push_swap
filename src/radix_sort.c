/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 18:42:29 by nprimo            #+#    #+#             */
/*   Updated: 2022/01/15 19:50:26 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*sort_stc(t_stack *stc)
{
	t_stack	*sorted;
	int		num;

	sorted = ft_stcnew(stc->num);
	stc = stc->next;
	while (stc)
	{
		num = stc->num;
		ft_stcadd_pos(&sorted, ft_stcnew(num), get_rel_pos(sorted, num));
		stc = stc->next;
	}
	return (sorted);
}

t_stack	*init_w_stc(t_stack *stc)
{
	t_stack	*sorted;
	t_stack	*w_stc;

	sorted = sort_stc(stc);
	w_stc = NULL;
	while (stc)
	{
		ft_stcadd_back(&w_stc, ft_stcnew(get_stcpos(sorted, stc->num)));
		stc = stc->next;
	}
	ft_stcclear(&sorted);
	return (w_stc);
}

int	radix_sort(t_stack **stc_a, t_stack **stc_b, char **comm, int count)
{
	int		size;

	size = ft_stcsize(*stc_a);
	while (size > 0)
	{
		if ((((*stc_a)->num >> count) & 1) == 0)
		{
			if (!add_op(stc_a, stc_b, "pb", comm))
				return (0);
		}
		else
		{
			if (!add_op(stc_a, stc_b, "ra", comm))
				return (0);
		}
		size--;
	}
	while (*stc_b)
	{
		if (!add_op(stc_a, stc_b, "pa", comm))
			return (0);
	}
	if (is_sorted(*stc_a))
		return (1);
	return (radix_sort(stc_a, stc_b, comm, count + 1));
}

/*
#include <stdio.h>

int main(int ac, char **av)
{
	t_stack *sorted;
	t_stack *stc;
	t_stack	*w_stc;
	t_stack *head;

	if (ac > 1)
	{
		stc = init_stack(ac, av);	
		sorted = sort_stc(stc);
		w_stc = init_w_stc(stc);	
	}
	head = w_stc;
	while (head)
	{
		printf("%d -- ", head->num);
		head = head->next;
	}
	ft_stcclear(&sorted);
	ft_stcclear(&stc);
	ft_stcclear(&w_stc);
}
*/
