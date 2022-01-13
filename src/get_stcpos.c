/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stcpos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 20:05:08 by nprimo            #+#    #+#             */
/*   Updated: 2022/01/13 20:06:12 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stcpos(t_stack *stc, int num)
{
	int	pos;

	pos = 0;
	while (stc)
	{
		if (stc->num == num)
			return (pos);
		pos++;
		stc = stc->next;
	}
	return (-1);
}
