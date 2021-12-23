/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stclast_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 12:48:37 by nprimo            #+#    #+#             */
/*   Updated: 2021/12/23 12:54:31 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stclast_test(void)
{
	t_stack	*stc;

	stc = ft_stcnew(1);
	ft_stcadd_back(&stc, ft_stcnew(2));
	ft_stcadd_back(&stc, ft_stcnew(3));
	ft_stcadd_back(&stc, ft_stcnew(4));
	ft_putstr_fd("--test ft_stclast:\n", 1);
	/*1*/
	if ((ft_stclast(stc)->num) != 4)
		ft_putstr_fd("1.KO\t", 1);
	else
		ft_putstr_fd("1.OK\t", 1);
	/*2*/
	if ((ft_stclast(stc)->next) != NULL)
		ft_putstr_fd("2.KO\t", 1);
	else
		ft_putstr_fd("2.OK\t", 1);
	ft_putstr_fd("\n", 1);
}
