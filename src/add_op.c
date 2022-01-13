/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:46:21 by nprimo            #+#    #+#             */
/*   Updated: 2022/01/13 17:49:10 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
