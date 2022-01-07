/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:46:21 by nprimo            #+#    #+#             */
/*   Updated: 2022/01/07 21:26:18 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_op(t_stack **stc_a, t_stack **stc_b, char *op, char **comm)
{
	char	*tmp;

	tmp = *comm;
	ex_op(stc_a, stc_b, op);
	*comm = ft_strjoin(tmp, op);
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
