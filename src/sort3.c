/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:26:26 by nprimo            #+#    #+#             */
/*   Updated: 2022/01/13 22:00:41 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort3(t_stack **stc_a, t_stack **stc_b, char **comm)
{
	if (is_sorted(*stc_a))
		return (1);
	if (ft_stcsize(*stc_a) == 2)
	{
		if (!add_op(stc_a, stc_b, "sa", comm))
			return (0);
		return (1);
	}
	if (is_rev_sorted(*stc_a) && add_op(stc_a, stc_b, "ra\nsa", comm))
		return (1);
	else if (get_pos_min(*stc_a) == 0 && add_op(stc_a, stc_b, "sa\nra", comm))
		return (1);
	else if (get_pos_min(*stc_a) == 2 && add_op(stc_a, stc_b, "rra", comm))
		return (1);
	else if ((*stc_a)->num > ft_stclast(*stc_a)->num
		&& add_op(stc_a, stc_b, "ra", comm))
		return (1);
	if (add_op(stc_a, stc_b, "sa", comm))
		return (1);
	return (0);
}
