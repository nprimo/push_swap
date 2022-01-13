/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:21:19 by nprimo            #+#    #+#             */
/*   Updated: 2022/01/13 21:43:15 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

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
void	ft_stcclear(t_stack **stack);
int		get_stcnum(t_stack *stack, int pos);
int		get_stcpos(t_stack *stc, int num);

// Stack basic functions
t_stack	*init_stack(int ac, char **av);
void	ft_swap(t_stack **stack);
void	ft_push(t_stack **getter, t_stack **giver);
void	ft_rotate(t_stack **stack);
void	ft_rev_rotate(t_stack **stack);

// sort functions
int		is_sorted(t_stack *stack);
int		is_rev_sorted(t_stack *stack);
char	*ex_op(t_stack **a, t_stack **b, char *op);
int		get_pos_min(t_stack *stack);
t_stack	*get_lis(t_stack *stack);
int		sort3(t_stack **stc_a, t_stack **stc_b, char **comm);
int		sort5(t_stack **stc_a, t_stack **stc_b, char **comm);
int		add_op(t_stack **stc_a, t_stack **stc_b, char *op, char **comm);
char	*ins_sort(t_stack *stack);
char	*quick_sort(t_stack *stc_a);

#endif
