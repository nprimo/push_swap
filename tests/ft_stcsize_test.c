/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stcsize_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 13:06:10 by nprimo            #+#    #+#             */
/*   Updated: 2021/12/23 13:10:11 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stcsize_test(void)
{
	t_stack *stc = ft_stcnew(1);

	ft_stcadd_front(&stc, ft_stcnew(2));
	ft_stcadd_front(&stc, ft_stcnew(2));
	ft_stcadd_front(&stc, ft_stcnew(2));
	ft_stcadd_front(&stc, ft_stcnew(2));
	ft_putstr_fd("--test ft_stcsize:\n", 1);
	/*1*/
	if (ft_stcsize(stc) != 5)
		ft_putstr_fd("1.KO\t", 1);
	else
		ft_putstr_fd("1.Ok\t", 1);
	ft_putstr_fd("\n", 1);
}
