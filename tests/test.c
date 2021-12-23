/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:23:08 by nprimo            #+#    #+#             */
/*   Updated: 2021/12/23 15:00:41 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "test.h"

#include <stdio.h>

void	print_status(t_stack *a, t_stack *b)
{
	int	size_a;
	int size_b;
	int	size_max;

	size_a = ft_stcsize(a);
	size_b = ft_stcsize(b);
	if (size_a > size_b)
		size_max = size_a;
	else
		size_max = size_b;
	while (size_max > 0)
	{
		if (size_a >= size_max)
		{
			ft_putnbr_fd(a->num, 1);
			a = a->next;
		}
		else
			ft_putstr_fd(" ", 1);
		ft_putchar_fd('\t', 1);
		if (size_b >= size_max)
		{
			ft_putnbr_fd(b->num, 1);
			b = b->next;
		}
		else
			ft_putstr_fd(" ", 1);
		ft_putchar_fd('\n', 1);
		size_max--;
	}
	ft_putstr_fd("-\t-\n", 1);
	ft_putstr_fd("a\tb\n", 1);
}

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

	ft_stcnew_test();
	ft_stcadd_back_test();
	ft_stclast_test();
	ft_stcadd_front_test();
	ft_stcsize_test();
	ft_stcclear_test();
	init_stack_test();
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
		// Check ex_op
		printf("--check ex_op--\n");
		printf("op: %s\n", ex_op(&stack_a, &stack_b, "pb"));
		print_status(stack_a, stack_b);
		printf("op: %s\n", ex_op(&stack_a, &stack_b, "pb"));
		print_status(stack_a, stack_b);
		printf("op: %s\n", ex_op(&stack_a, &stack_b, "pb"));
		print_status(stack_a, stack_b);
		printf("op: %s\n", ex_op(&stack_a, &stack_b, "sb"));
		print_status(stack_a, stack_b);
		printf("op: %s\n", ex_op(&stack_a, &stack_b, "sa"));
		print_status(stack_a, stack_b);
		printf("op: %s\n", ex_op(&stack_a, &stack_b, "ra"));
		print_status(stack_a, stack_b);
		printf("op: %s\n", ex_op(&stack_a, &stack_b, "rb"));
		print_status(stack_a, stack_b);
		printf("op: %s\n", ex_op(&stack_a, &stack_b, "rra"));
		print_status(stack_a, stack_b);
		printf("op: %s\n", ex_op(&stack_a, &stack_b, "rrb"));
		print_status(stack_a, stack_b);
		ft_stcclear(&stack_a);
		ft_stcclear(&stack_b);
	}
}
