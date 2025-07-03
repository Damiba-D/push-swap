/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_funcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamiba <ddamiba@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:18:21 by ddamiba           #+#    #+#             */
/*   Updated: 2025/07/03 21:33:45 by ddamiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	a_bring_node_to_top(t_stack **stack, int node_index, int rev_flag)
{
	if (!rev_flag)
	{
		while (node_index--)
			rotate_a(stack, 1);
	}
	else
	{
		while (node_index--)
			revrot_a(stack, 1);
	}
}

void	b_bring_node_to_top(t_stack **stack, int node_index, int rev_flag)
{
	if (!rev_flag)
	{
		while (node_index--)
			rotate_b(stack, 1);
	}
	else
	{
		while (node_index--)
			revrot_b(stack, 1);
	}
}

void	bring_nodes_to_top(t_stack **a, t_stack **b, int a_n_i, int b_n_i)
{
	int	a_rev;
	int	b_rev;

	a_rev = 0;
	b_rev = 0;
	set_rot_dir(&a_n_i, &a_rev, ft_stacksize(*a));
	set_rot_dir(&b_n_i, &b_rev, ft_stacksize(*b));
	while (a_n_i && b_n_i && !a_rev && !b_rev)
	{
		rotate_a_b(a, b);
		a_n_i--;
		b_n_i--;
	}
	while (a_n_i && b_n_i && a_rev && b_rev)
	{
		revrot_a_b(a, b);
		a_n_i--;
		b_n_i--;
	}
	a_bring_node_to_top(a, a_n_i, a_rev);
	b_bring_node_to_top(b, b_n_i, b_rev);
}
