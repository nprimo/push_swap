/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_min_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 17:13:14 by nprimo            #+#    #+#             */
/*   Updated: 2021/12/23 17:21:14 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pos_min_test(void)
{
	t_stack	*stc;

	ft_putstr_fd("--test pos_min:\n", 1);
	/*1*/
	stc = init_stack(5, ft_split("0 5 3 2 1 4", ' '));
	if (pos_min(stc) != 3)
		ft_putstr_fd("1.KO\t", 1);
	else
		ft_putstr_fd("1.OK\t", 1);
	ft_stcclear(&stc);
	/*2*/
	stc = init_stack(5, ft_split("0 1 3 2 5 4", ' '));
	if (pos_min(stc) != 0)
		ft_putstr_fd("2.KO\t", 1);
	else
		ft_putstr_fd("2.OK\t", 1);
	ft_stcclear(&stc);
	/*3*/
	stc = init_stack(5, ft_split("0 2 3 1 5 4", ' '));
	if (pos_min(stc) != 2)
		ft_putstr_fd("3.KO\t", 1);
	else
		ft_putstr_fd("3.OK\t", 1);
	ft_stcclear(&stc);
	/*4*/
	stc = init_stack(5, ft_split("0 2 3 4 5 1", ' '));
	if (pos_min(stc) != 4)
		ft_putstr_fd("3.KO\t", 1);
	else
		ft_putstr_fd("3.OK\t", 1);
	ft_stcclear(&stc);
	ft_putstr_fd("\n", 1);
}
