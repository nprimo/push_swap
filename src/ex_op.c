/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:30:29 by nprimo            #+#    #+#             */
/*   Updated: 2021/12/20 17:44:32 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ex_op(t_stack **a, t_stack **b, char *op)
{
	if (ft_strncmp(op, "sa", 2) == 0)
		ft_swap(a);
	else if (ft_strncmp(op, "sb", 2) == 0)
		ft_swap(b);
	else if (ft_strncmp(op, "pa", 2) == 0)
		ft_push(a, b);
	else if (ft_strncmp(op, "pb", 2) == 0)
		ft_push(b, a);
	else if (ft_strncmp(op, "ra", 2) == 0)
		ft_rotate(a);
	else if (ft_strncmp(op, "rb", 2) == 0)
		ft_rotate(b);
	else if (ft_strncmp(op, "rra", 3) == 0)
		ft_rev_rotate(a);
	else if (ft_strncmp(op, "rrb", 3) == 0)
		ft_rev_rotate(b);
	else
		op = NULL;
	return (op);
}
