/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 18:42:29 by nprimo            #+#    #+#             */
/*   Updated: 2022/01/15 19:14:04 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*ins_sort(t_stack *stc)
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

/*
#include <stdio.h>

int main(int ac, char **av)
{
	t_stack *sorted;
	t_stack *stc;

	if (ac > 1)
	{
		stc = init_stack(ac, av);	
		sorted = ins_sort(stc);
	}
	ft_stcclear(&sorted);
	ft_stcclear(&stc);
}
*/
