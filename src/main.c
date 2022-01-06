/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:20:32 by nprimo            #+#    #+#             */
/*   Updated: 2022/01/06 16:18:53 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	return_error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (0);
}

static void	print_comm(t_list *comm)
{
	t_list	*head;

	head = comm;
	while (head)
	{
		ft_putstr_fd(head->content, 1);
		ft_putchar_fd('\n', 1);
		head = head->next;
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_list	*comm;

	comm = NULL;
	if (ac > 1)
	{
		stack_a = init_stack(ac, av);
		if (!stack_a)
			return (return_error());
		if (is_sorted(stack_a))
			return (1);
		if (ft_stcsize(stack_a) <= 3)
			comm = sort3(stack_a);
		print_comm(comm);
	}
	return (1);
}
