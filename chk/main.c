/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:24:01 by nprimo            #+#    #+#             */
/*   Updated: 2022/01/19 11:51:31 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**get_rules_in(int len, char **av);
char	**get_stc_in(int len, char **av);

static int	return_msg(int n)
{
	if (n == 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	else if (n == 1)
	{
		ft_putstr_fd("KO\n", 2);
		return (0);
	}
	else if (n == 2)
	{
		ft_putstr_fd("OK\n", 1);
		return (1);
	}
	return (0);
}

static int	is_valid_op(char *op)
{
	if (ft_strncmp(op, "sa", 3) == 0
		|| ft_strncmp(op, "sb", 3) == 0
		|| ft_strncmp(op, "ss", 3) == 0
		|| ft_strncmp(op, "ra", 3) == 0
		|| ft_strncmp(op, "rb", 3) == 0
		|| ft_strncmp(op, "rr", 3) == 0
		|| ft_strncmp(op, "pb", 3) == 0
		|| ft_strncmp(op, "pa", 3) == 0
		|| ft_strncmp(op, "rra", 4) == 0
		|| ft_strncmp(op, "rrb", 4) == 0
		|| ft_strncmp(op, "rrr", 4) == 0)
		return (1);
	else
		return (0);
}

static int	check_rules(t_stack **stc_a, t_stack **stc_b, char **rules_in,
		char **comm)
{
	while (*rules_in)
	{
		if (!is_valid_op(*rules_in) || !add_op(stc_a, stc_b, *rules_in, comm))
			return (0);
		rules_in++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*stc_a;
	t_stack	*stc_b;
	char	*comm;
	char	**rules_in;
	char	**stc_in;

	stc_b = NULL;
	if (ac > 1)
	{
		stc_in = get_stc_in(ac, av);
		rules_in = get_rules_in(ac, av);
		comm = ft_strdup("");
		if (!stc_in || !rules_in || !comm)
			return (return_msg(0));
		stc_a = init_stack(3, stc_in);
		if (!stc_a || !check_rules(&stc_a, &stc_b, rules_in, &comm))
			return (return_msg(0));
		if (is_sorted(stc_a) && !stc_b)
			return (return_msg(2));
		else
			return (return_msg(1));
	}
}
