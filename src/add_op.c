/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:46:21 by nprimo            #+#    #+#             */
/*   Updated: 2022/01/16 16:09:02 by nprimo           ###   ########.fr       */
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

static char	*ex_op(t_stack **a, t_stack **b, char *op)
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
	if (ft_strlen(op) == 2
		&& (ft_strncmp(op, "ra", 2) == 0 || ft_strncmp(op, "rr", 2) == 0))
		ft_rotate(a);
	if (ft_strlen(op) == 2
		&& (ft_strncmp(op, "rb", 2) == 0 || ft_strncmp(op, "rr", 2) == 0))
		ft_rotate(b);
	if (ft_strncmp(op, "rra", 3) == 0 || ft_strncmp(op, "rrr", 3) == 0)
		ft_rev_rotate(a);
	if (ft_strncmp(op, "rrb", 3) == 0 || ft_strncmp(op, "rrr", 3) == 0)
		ft_rev_rotate(b);
	return (op);
}

static void	free_ops_list(char **av)
{
	int	count;

	if (!av)
		return ;
	count = 0;
	while (av[count])
	{
		free(av[count]);
		count++;
	}
	free(av);
}

int	add_op(t_stack **stc_a, t_stack **stc_b, char *ops, char **comm)
{
	char	*tmp;
	char	**ops_list;
	int		count;

	tmp = *comm;
	ops_list = ft_split(ops, '\n');
	if (!ops_list)
		return (0);
	count = 0;
	while (ops_list[count])
	{
		ex_op(stc_a, stc_b, ops_list[count]);
		count++;
	}
	free_ops_list(ops_list);
	*comm = ft_strjoin(tmp, ops);
	if (!(*comm))
		return (0);
	free(tmp);
	tmp = *comm;
	*comm = ft_strjoin(tmp, "\n");
	if (!(*comm))
		return (0);
	free(tmp);
	return (1);
}
