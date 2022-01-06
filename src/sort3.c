/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:26:26 by nprimo            #+#    #+#             */
/*   Updated: 2022/01/06 15:47:34 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*sort3(t_stack *stack)
{
	t_list	*comm;

	comm = NULL;
	if (ft_stcsize(stack) == 2)
	{
		ft_lstadd_back(&comm, ft_lstnew("sa"));
		return (comm);
	}
	if (is_rev_sorted(stack))
	{
		ft_lstadd_back(&comm, ft_lstnew("ra"));
		ft_lstadd_back(&comm, ft_lstnew("sa"));
	}
	else if (pos_min(stack) == 0)
	{
		ft_lstadd_back(&comm, ft_lstnew("sa"));
		ft_lstadd_back(&comm, ft_lstnew("ra"));
	}
	else if (pos_min(stack) == 2)
		ft_lstadd_back(&comm, ft_lstnew("rra"));
	else if (stack->num > ft_stclast(stack)->num)
		ft_lstadd_back(&comm, ft_lstnew("ra"));
	else
		ft_lstadd_back(&comm, ft_lstnew("sa"));
	return (comm);
}
