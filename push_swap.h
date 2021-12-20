/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:21:19 by nprimo            #+#    #+#             */
/*   Updated: 2021/12/20 09:47:50 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int		num;
	t_stack	*next;
}	t_stack;

t_list	*init_stack(int ac, char **av);
void	ft_swap(t_list **stack);
void	ft_push(t_list **getter, t_list **giver);
void	ft_rotate(t_list **stack);
void	ft_rev_rotate(t_list **stack);

#endif
