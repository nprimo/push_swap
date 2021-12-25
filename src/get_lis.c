/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 19:19:40 by nprimo            #+#    #+#             */
/*   Updated: 2021/12/25 20:29:04 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*init_array(int num, int size)
{
	int	pos;
	int	*array;

	array = malloc(sizeof(*array) * size);
	if (!array)
		return (NULL);
	pos = 0;
	while (pos < size)
	{
		array[pos] = num;
		pos++;
	}
	return (array);
}

static int	*get_len_lis(t_stack *stack)
{
	int	*len_lis;
	int	size;
	int	i;
	int	j;

	size = ft_stcsize(stack);
	len_lis = init_array(1, size);
	if (!len_lis)
		return (NULL);
	i = size;
	while (i > 0)
	{
		i--;
		j = i + 1;
		while (j < size)
		{
			if (get_stcpos(stack, i) < get_stcpos(stack, j)
				&& (len_lis[j] + 1) > len_lis[i])
				len_lis[i] = len_lis[j] + 1;
			j++;
		}
	}
	return (len_lis);
}

static int	get_max(int *arr, int size)
{
	int	pos;
	int	max;

	max = INT_MIN;
	pos = 0;
	while (pos < size)
	{
		if (arr[pos] > max)
			max = arr[pos];
		pos++;
	}
	return (max);
}

static int	get_id_len_lis(int *len_lis, int size, int num)
{
	int	pos;

	pos = 0;
	while (pos < size)
	{
		if (len_lis[pos] == num)
			return (pos);
		pos++;
	}
	return (-1);
}

t_stack	*get_lis(t_stack *stack)
{
	int		*len_lis;
	t_stack	*lis;
	int		size_lis;
	int		num;
	int		pos;

	lis = NULL;
	len_lis = get_len_lis(stack);
	if (!len_lis)
		return (NULL);
	size_lis = get_max(len_lis, ft_stcsize(stack));
	pos = 0;
	while (pos < size_lis)
	{
		num = get_stcpos(stack,
				get_id_len_lis(len_lis, ft_stcsize(stack), size_lis - pos));
		ft_stcadd_back(&lis, ft_stcnew(num));
		pos++;
	}
	free(len_lis);
	return (lis);
}

/*
int	main(int ac, char **av)
{
	t_stack	*stack_a;
	int		*len_lis;
	t_stack	*lis;
	int		pos;
	int		size;

	if (ac > 1)
	{
		stack_a = init_stack(ac, av);
		len_lis = get_len_lis(stack_a);
		size = ft_stcsize(stack_a);
		pos = 0;
		while (pos < size)
		{
			ft_putnbr_fd(len_lis[pos], 1);
			ft_putchar_fd('\n', 1);
			pos++;
		}
		lis = get_lis(stack_a);
		while(lis)
		{
			ft_putnbr_fd(lis->num, 1);
			ft_putchar_fd('\n', 1);
			lis = lis->next;
		}
	}
	return (1);
}
*/
