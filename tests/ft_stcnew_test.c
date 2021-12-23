/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stcnew_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 12:23:50 by nprimo            #+#    #+#             */
/*   Updated: 2021/12/23 12:43:16 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stcnew_test(void)
{
	t_stack	*stc;

	ft_putstr_fd("--test ft_stcnew:\n", 1);
	stc = ft_stcnew(1);
	/*1*/
	if (stc->num != 1)
		ft_putstr_fd("1.KO\t", 1);
	else
		ft_putstr_fd("1.OK\t", 1);
	/*2*/
	if (stc->next != NULL)
		ft_putstr_fd("2.KO\t", 1);
	else
		ft_putstr_fd("2.OK\t", 1);
	/*3*/
	if (!stc)
		ft_putstr_fd("3.KO\t", 1);
	else
		ft_putstr_fd("3.OK\t", 1);
	ft_putstr_fd("\n", 1);
}
