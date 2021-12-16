/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:23:08 by nprimo            #+#    #+#             */
/*   Updated: 2021/12/16 10:42:26 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*head;

	stack_a = NULL;
	if (ac > 1)
	{
		// Check init_stack
		stack_a = init_stack(ac, av);
		head = stack_a;
		while (head)
		{
			printf("%s\n", head->content);
			head = head->next;
		}
	}
}
