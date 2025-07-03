/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamiba <ddamiba@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:13:40 by ddamiba           #+#    #+#             */
/*   Updated: 2025/07/03 21:03:00 by ddamiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	to_top_cost(t_stack *stack, int node_index)
{
	int	cost;
	int	stacksize;

	stacksize = ft_stacksize(stack);
	if (node_index <= stacksize / 2)
		cost = node_index;
	else
		cost = stacksize - node_index;
	return (cost);
}

int	find_total_cost(t_stack *a, t_stack *b)
{
	int	total_cost;
	int	target_node;

	target_node = find_target_node(a, b);
	total_cost = to_top_cost(a, find_node_index(a, target_node));
	return (total_cost);
}
