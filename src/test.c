/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:23:08 by nprimo            #+#    #+#             */
/*   Updated: 2021/12/20 17:23:22 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

void	print_stack(t_stack *head)
{
	while (head)
	{
		printf("%d\n", head->num);
		head = head->next;
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac > 1)
	{
		// Check init_stack
		printf("--Check init_stack--\n");
		stack_a = init_stack(ac, av);
		print_stack(stack_a); 
		// Check is_sorted
		printf("--Check is_sorted--\n");
		printf("is sorted? %d\n", is_sorted(stack_a));
		// Check is_rev_sorted
		printf("--Check is_rev_sorted--\n");
		printf("is sorted (reverse)? %d\n", is_rev_sorted(stack_a));
		// Check swap
		printf("--Check ft_swap--\n");
		ft_swap(&stack_a);
		print_stack(stack_a);
		// Check push
		printf("--Check ft_push (1)--\n");
		ft_push(&stack_b, &stack_a);
		print_stack(stack_a);
		printf("--\n");
		print_stack(stack_b);
		// Check rotate
		printf("--Check ft_rotate (a)--\n");
		ft_rotate(&stack_a);
		print_stack(stack_a);
		// Check rev rotate
		printf("--Check ft_rev_rotate (b)--\n");
		ft_rev_rotate(&stack_b);
		print_stack(stack_b);
		printf("--Check ft_rev_rotate (a)--\n");
		ft_rev_rotate(&stack_a);
		print_stack(stack_a);
	}
}
