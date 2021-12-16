/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:23:08 by nprimo            #+#    #+#             */
/*   Updated: 2021/12/16 11:31:51 by nprimo           ###   ########.fr       */
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
	printf("---\n");
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac > 1)
	{
		// Check init_stack
		printf("--Check init_stack--\n");
		stack_a = init_stack(ac, av);
		print_stack(stack_a); 
		// Check swap
		printf("--Check ft_swap--\n");
		ft_swap(&stack_a);
		print_stack(stack_a);
		// Check push
		printf("--Check ft_push (1)--\n");
		ft_push(&stack_b, &stack_a);
		print_stack(stack_a);
		print_stack(stack_b);
		printf("--Check ft_push (2)--\n");
		ft_push(&stack_b, &stack_a);
		print_stack(stack_a);
		print_stack(stack_b);
	}
}
