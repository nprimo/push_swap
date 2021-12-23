/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stcclear_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 13:11:40 by nprimo            #+#    #+#             */
/*   Updated: 2021/12/23 13:14:36 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stcclear_test(void)
{
	t_stack	*stc;

	stc = ft_stcnew(1);
	ft_putstr_fd("--test ft_stcclear:\n", 1);
	ft_stcclear(&stc);
	/*1*/
	if (stc)
		ft_putstr_fd("1.KO", 1);
	else
		ft_putstr_fd("1.OK", 1);
	ft_putstr_fd("\n", 1);
}
