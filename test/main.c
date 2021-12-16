/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:23:08 by nprimo            #+#    #+#             */
/*   Updated: 2021/12/16 11:02:34 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

void	print_stack(t_list *head)
{
	while (head)
	{
		printf("%s\n", head->content);
		head = head->next;
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;

	stack_a = NULL;
	if (ac > 1)
	{
		// Check init_stack
		stack_a = init_stack(ac, av);
		print_stack(stack_a); 
		// Check swap
		ft_swap(&stack_a);
		print_stack(stack_a);
	}
}
