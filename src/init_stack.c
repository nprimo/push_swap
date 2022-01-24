/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:35:33 by nprimo            #+#    #+#             */
/*   Updated: 2022/01/24 10:41:20 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_alldigit(char *s)
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

static int	is_in_int_range(char *s)
{
	long	num;

	num = ft_atoi(s);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	else
		return (1);
}

static int	is_in_stack(char *s, t_stack *stack)
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

static void	free_split(char **av)
{
	char	**head;

	head = av;
	while (*av)
	{
		free(*av);
		av++;
	}
	free(head);
}

t_stack	*init_stack(int ac, char **av)
{
	t_stack	*stack;
	char	**inputs;
	int		pos;
	int		num;

	stack = NULL;
	if (ac > 2)
		inputs = &av[1];
	else
		inputs = ft_split(av[1], ' ');
	pos = 0;
	while (inputs[pos])
	{
		if (is_alldigit(inputs[pos]) && is_in_int_range(inputs[pos])
			&& !is_in_stack(inputs[pos], stack))
		{
			num = (int) ft_atoi(inputs[pos]);
			ft_stcadd_back(&stack, ft_stcnew(num));
			pos++;
		}
		else
			return (NULL);
	}
	free_split(inputs);
	return (stack);
}
