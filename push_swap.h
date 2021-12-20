/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:21:19 by nprimo            #+#    #+#             */
/*   Updated: 2021/12/20 12:18:48 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}	t_stack;

// linked list with stack struct
t_stack	*ft_stcnew(int num);
void	ft_stcadd_back(t_stack **stack, t_stack *new);
t_stack	*ft_stclast(t_stack *stack);
void	ft_stcadd_front(t_stack **stack, t_stack *new);
int		ft_stcsize(t_stack *stack);

// Stack basics
t_stack	*init_stack(int ac, char **av);
void	ft_swap(t_stack **stack);
void	ft_push(t_stack **getter, t_stack **giver);
void	ft_rotate(t_stack **stack);
void	ft_rev_rotate(t_list **stack);

#endif
