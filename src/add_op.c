/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:46:21 by nprimo            #+#    #+#             */
/*   Updated: 2022/01/13 17:57:37 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
