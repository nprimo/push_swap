/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:07:30 by nprimo            #+#    #+#             */
/*   Updated: 2021/12/23 15:11:55 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_test(void)
{
	t_stack	*stc = NULL;
	char	**av;

	av = ft_split("0 1 2 3 4 5", ' ');
	ft_putstr_fd("--test ft_swap:\n", 1);
	stc = init_stack(5, av);
	ft_swap(&stc);
	/*1*/
	if (stc->num != 2)
		ft_putstr_fd("1.KO\t", 1);
	else
		ft_putstr_fd("1.OK\t", 1);
	/*2*/
	if (stc->next->num != 1)
		ft_putstr_fd("2.KO\t", 1);
	else
		ft_putstr_fd("2.OK\t", 1);
	ft_putstr_fd("\n", 1);
}
