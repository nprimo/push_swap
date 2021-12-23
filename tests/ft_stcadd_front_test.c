/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stcadd_front_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 12:56:15 by nprimo            #+#    #+#             */
/*   Updated: 2021/12/23 13:00:48 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stcadd_front_test(void)
{
	t_stack *stc;

	stc = ft_stcnew(1);
	ft_stcadd_front(&stc, ft_stcnew(2));
	ft_stcadd_front(&stc, ft_stcnew(3));
	ft_stcadd_front(&stc, ft_stcnew(4));
	ft_stcadd_front(&stc, ft_stcnew(5));
	ft_putstr_fd("--test ft_stcadd_front:\n", 1);
	/*1*/
	if (stc->num != 5)
		ft_putstr_fd("1.KO\t", 1);
	else
		ft_putstr_fd("1.OK\t", 1);
	stc = stc->next;
	/*2*/
	if (stc->num != 4)
		ft_putstr_fd("2.KO\t", 1);
	else
		ft_putstr_fd("2.OK\t", 1);
	stc = stc->next;
	/*3*/
	if (stc->num != 3)
		ft_putstr_fd("3.KO\t", 1);
	else
		ft_putstr_fd("3.OK\t", 1);
	stc = stc->next;
	/*4*/
	if (stc->num != 2)
		ft_putstr_fd("4.KO\t", 1);
	else
		ft_putstr_fd("4.OK\t", 1);
	stc = stc->next;
	ft_putstr_fd("\n", 1);
}
