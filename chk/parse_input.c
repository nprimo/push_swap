/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:44:12 by nprimo            #+#    #+#             */
/*   Updated: 2022/01/19 14:37:21 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_all_digit(char *s)
{
	if (!s)
		return (0);
	if (*s == '-' || *s == '+')
		s++;
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

static int	get_len_stack_in(int ac, char **av)
{
	int		count;

	count = 1;
	while (is_all_digit(av[count]) && count < ac)
		count++;
	return (count - 1);
}

char	**get_stc_in(int ac, char **av)
{
	char	**stc_in;
	int		pos;
	int		len;

	len = get_len_stack_in(ac, av);
	stc_in = malloc(sizeof(*stc_in) * (len + 2));
	if (!stc_in)
		return (NULL);
	pos = 0;
	while (pos <= len)
	{
		stc_in[pos] = ft_strdup(av[pos]);
		if (!stc_in[pos])
			return (NULL);
		pos++;
	}
	stc_in[pos] = NULL;
	return (stc_in);
}

char	**get_rules_in(int ac, char **av)
{
	char	**rules_in;
	int		pos;
	int		len;

	len = get_len_stack_in(ac, av);
	rules_in = malloc(sizeof(*rules_in) * (ac - len));
	if (!rules_in)
		return (NULL);
	if (ac - len == 1)
	{
		rules_in[0] = NULL;
		return (rules_in);
	}
	pos = 0;
	while (pos < (ac - len - 1))
	{
		rules_in[pos] = ft_strdup(av[len + 1 + pos]);
		if (!rules_in[pos])
			return (NULL);
		pos++;
	}
	return (rules_in);
}

/*
#include <stdio.h>

int main(int ac, char **av)
{
	char	**rules_in;
	char	**stc_in;

	if (ac > 1)
	{
		rules_in = get_rules_in(ac, av);
		stc_in = get_stc_in(ac, av);
		while (*stc_in)
		{
			printf("stc_in: %s\n", *stc_in);
			stc_in++;
		}
		while (*rules_in)
		{
			printf("rule: %s\n", *rules_in);
			rules_in++;
		}
	}
	return (1);
}
*/
