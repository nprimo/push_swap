/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:16:55 by nprimo            #+#    #+#             */
/*   Updated: 2022/01/24 12:18:24 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_alldigit(char *s)
{
	if (!s)
		return (0);
	if (ft_strlen(s) > 1 && (*s == '-' || *s == '+'))
		s++;
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

int	is_in_int_range(char *s)
{
	long	num;

	num = ft_atoi(s);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	else
		return (1);
}

int	is_in_stack(char *s, t_stack *stack)
{
	int	num;

	num = (int) ft_atoi(s);
	while (stack)
	{
		if (num == stack->num)
			return (1);
		stack = stack->next;
	}
	return (0);
}
