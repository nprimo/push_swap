/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stcadd_back_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 12:36:26 by nprimo            #+#    #+#             */
/*   Updated: 2021/12/23 12:40:51 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stcadd_back_test(void)
{
	t_stack	*stc;

	stc = ft_stcnew(2);
	ft_putstr_fd("--test ft_stcadd_back:\n", 1);
	ft_stcadd_back(&stc, ft_stcnew(1));
	/*1*/
	if ((stc->next)->num != 1)
		ft_putstr_fd("1.KO\t", 1);
	else
		ft_putstr_fd("1.OK\t", 1);
	/*2*/
	if ((stc->next)->next != NULL)
		ft_putstr_fd("2.KO\t", 1);
	else
		ft_putstr_fd("2.OK\t", 1);
	/*3*/
	if ((ft_stcsize(stc))!= 2)
		ft_putstr_fd("3.KO\t", 1);
	else
		ft_putstr_fd("3.OK\t", 1);
	ft_putstr_fd("\n", 1);

}
