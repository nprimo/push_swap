/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 14:55:58 by nprimo            #+#    #+#             */
/*   Updated: 2021/12/23 15:06:25 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack_test(void)
{
	t_stack *stc = NULL;
	char	**av;

	av = ft_split("something 1 2 3 4 5", ' ');
	ft_putstr_fd("--test init_stack:\n", 1);
	stc = init_stack(5, av);
	/*1*/
	if (ft_stcsize(stc) != 5)
		ft_putstr_fd("1.KO\t", 1);
	else
		ft_putstr_fd("1.OK\t", 1);
	/*2*/
	if (stc->num != 1)
		ft_putstr_fd("2.KO\t", 1);
	else
		ft_putstr_fd("2.OK\t", 1);
	stc = stc->next->next;
	/*3*/
	if (stc->num != 3)
		ft_putstr_fd("1.KO\t", 1);
	else
		ft_putstr_fd("1.OK\t", 1);
	ft_putstr_fd("\n", 1);
}
