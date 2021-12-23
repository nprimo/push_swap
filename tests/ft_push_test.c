/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:12:33 by nprimo            #+#    #+#             */
/*   Updated: 2021/12/23 15:17:50 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_test(void)
{
	t_stack *giver = NULL;
	t_stack *getter = NULL;
	char	**av;

	ft_putstr_fd("--test ft_push:\n", 1);
	av = ft_split("0 1 2 3 4 5", ' ');
	giver = init_stack(5, av);
	ft_push(&getter, &giver);
	/*1*/
	if (getter->num != 1)
		ft_putstr_fd("1.KO\t", 1);
	else
		ft_putstr_fd("1.OK\t", 1);
	/*2*/
	if (giver->num != 2)
		ft_putstr_fd("2.KO\t", 1);
	else
		ft_putstr_fd("2.OK\t", 1);
	/*3*/
	if (getter->next != NULL)
		ft_putstr_fd("3.KO\t", 1);
	else
		ft_putstr_fd("3.OK\t", 1);
	ft_putstr_fd("\n", 1);
}
