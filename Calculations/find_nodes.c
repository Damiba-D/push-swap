/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamiba <ddamiba@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:07:01 by ddamiba           #+#    #+#             */
/*   Updated: 2025/07/04 21:03:48 by ddamiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_node_index(t_stack *stack, int node_value)
{
	int	i;

	i = 0;
	while (stack->content != node_value)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int	find_target_node(t_stack *a, t_stack *b)
{
	int		node_b;
	int		target_node;
	t_stack	*b_max;
	t_stack	*a_min;
	t_stack	*a_max;

	b_max = find_max(b);
	a_min = find_min(a);
	a_max = find_max(a);
	node_b = b->content;
	if (node_b == b_max->content && node_b > a_max->content)
		return (a_min->content);
	target_node = INT32_MAX;
	while (a != NULL)
	{
		if (a->content > node_b && a->content < target_node)
			target_node = a->content;
		a = a->next;
	}
	if (target_node == INT32_MAX)
		return (a_min->content);
	return (target_node);
}

void	set_curr_cost(int *curr, int next, int *pos, int i)
{
	if (next < *curr)
	{
		*curr = next;
		*pos = i;
	}
}

int	find_cheapest_node(t_stack *a, t_stack *b)
{
	int		curr_total_cost;
	int		next_total_cost;
	int		pos_cheapest;
	int		i;
	t_stack	*temp_b;

	pos_cheapest = 0;
	curr_total_cost = find_total_cost(a, b);
	temp_b = b->next;
	i = 1;
	while (temp_b != NULL)
	{
		if (i <= ft_stacksize(b) / 2)
			next_total_cost = find_total_cost(a, temp_b) + i;
		else
			next_total_cost = find_total_cost(a, temp_b) \
+ (ft_stacksize(b) - i);
		set_curr_cost(&curr_total_cost, next_total_cost, &pos_cheapest, i);
		i++;
		temp_b = temp_b->next;
	}
	return (pos_cheapest);
}
