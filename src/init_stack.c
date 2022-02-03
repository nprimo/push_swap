/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:35:33 by nprimo            #+#    #+#             */
/*   Updated: 2022/02/03 12:21:23 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_alldigit(char *s);
int	is_in_int_range(char *s);
int	is_in_stack(char *s, t_stack *stack);

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

static t_stack	*init_stack_b(char **av)
{
	t_stack	*stack;
	char	**inputs;
	int		pos;
	int		num;

	stack = NULL;
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

t_stack	*init_stack(int ac, char **av)
{
	t_stack	*stack;
	char	**inputs;
	int		pos;
	int		num;

	stack = NULL;
	if (ac > 2)
	{
		inputs = &av[1];
		pos = -1;
		while (inputs[++pos])
		{
			if (is_alldigit(inputs[pos]) && is_in_int_range(inputs[pos])
				&& !is_in_stack(inputs[pos], stack))
			{
				num = (int) ft_atoi(inputs[pos]);
				ft_stcadd_back(&stack, ft_stcnew(num));
			}
			else
			{
				free_split(inputs);
				ft_stcclear(&stack);
				return (NULL);
			}
		}
	}
	else
		stack = init_stack_b(av);
	return (stack);
}
