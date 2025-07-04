/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamiba <ddamiba@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 15:38:18 by ddamiba           #+#    #+#             */
/*   Updated: 2025/07/04 21:17:40 by ddamiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_3(t_stack **a)
{
	int	pos1;
	int	pos2;
	int	pos3;

	pos1 = (*a)->content;
	pos2 = (*a)->next->content;
	pos3 = (*a)->next->next->content;
	if ((pos1 > pos2 && pos2 > pos3))
		return (rotate_a(a, 1), swap_a(a, 1));
	else if (pos1 < pos3 && pos2 > pos3)
		return (revrot_a(a, 1), swap_a(a, 1));
	else if (pos1 > pos2 && pos2 < pos3)
	{
		if (pos1 < pos3)
			return (swap_a(a, 1));
		else
			return (rotate_a(a, 1));
	}
	else if (pos1 < pos2 && pos2 > pos3)
		return (revrot_a(a, 1));
}

void	sort_to_b(t_stack **a, t_stack **b)
{
	int		cheapest_node_pos;
	int		target_node_pos;
	t_stack	*temp_b;
	int		i;

	while (ft_stacksize(*a) > 3 && !a_is_sorted(*a))
		push_b(a, b);
	if (ft_stacksize(*a) == 3)
		sort_stack_3(a);
	while (*b != NULL)
	{
		cheapest_node_pos = find_cheapest_node(*a, *b);
		i = 0;
		temp_b = *b;
		while (i < cheapest_node_pos)
		{
			temp_b = temp_b->next;
			i++;
		}
		target_node_pos = find_node_index(*a, find_target_node(*a, temp_b));
		bring_nodes_to_top(a, b, target_node_pos, cheapest_node_pos);
		push_a(a, b);
	}
}

void	turk_algo(t_stack **a, t_stack **b)
{
	int	a_min_pos;
	int	rev_flag;
	int	a_size;

	a_size = ft_stacksize(*a);
	if (a_size == 1)
		return ;
	else if (a_size == 2)
	{
		if (!a_is_sorted(*a))
			return (swap_a(a, 1));
		return ;
	}
	else if (a_size == 3)
		return (sort_stack_3(a));
	if (!a_is_sorted(*a))
		sort_to_b(a, b);
	a_min_pos = find_min_pos(*a);
	rev_flag = 0;
	set_rot_dir(&a_min_pos, &rev_flag, a_size);
	if (!a_is_sorted(*a))
		a_bring_node_to_top(a, a_min_pos, rev_flag);
}
