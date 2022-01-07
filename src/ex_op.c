/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:30:29 by nprimo            #+#    #+#             */
/*   Updated: 2022/01/07 14:58:48 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_op(char *op)
{
	if (ft_strncmp(op, "sa", 2) == 0
		|| ft_strncmp(op, "sb", 2) == 0
		|| ft_strncmp(op, "ss", 2) == 0
		|| ft_strncmp(op, "ra", 2) == 0
		|| ft_strncmp(op, "rb", 2) == 0
		|| ft_strncmp(op, "rr", 2) == 0
		|| ft_strncmp(op, "pb", 2) == 0
		|| ft_strncmp(op, "pa", 2) == 0
		|| ft_strncmp(op, "rra", 3) == 0
		|| ft_strncmp(op, "rrb", 3) == 0
		|| ft_strncmp(op, "rrr", 3) == 0)
		return (1);
	else
		return (0);
}

char	*ex_op(t_stack **a, t_stack **b, char *op)
{
	if (!is_valid_op(op))
		return (NULL);
	if (ft_strncmp(op, "sa", 2) == 0 || ft_strncmp(op, "ss", 2) == 0)
		ft_swap(a);
	if (ft_strncmp(op, "sb", 2) == 0 || ft_strncmp(op, "ss", 2) == 0)
		ft_swap(b);
	if (ft_strncmp(op, "pa", 2) == 0)
		ft_push(a, b);
	if (ft_strncmp(op, "pb", 2) == 0)
		ft_push(b, a);
	if (ft_strncmp(op, "ra", 2) == 0 || ft_strncmp(op, "rr", 2) == 0)
		ft_rotate(a);
	if (ft_strncmp(op, "rb", 2) == 0 || ft_strncmp(op, "rr", 2) == 0)
		ft_rotate(b);
	if (ft_strncmp(op, "rra", 3) == 0 || ft_strncmp(op, "rrr", 3) == 0)
		ft_rev_rotate(a);
	if (ft_strncmp(op, "rrb", 3) == 0 || ft_strncmp(op, "rrr", 3) == 0)
		ft_rev_rotate(b);
	return (op);
}
