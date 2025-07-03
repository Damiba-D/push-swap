/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamiba <ddamiba@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 15:38:18 by ddamiba           #+#    #+#             */
/*   Updated: 2025/07/03 14:08:13 by ddamiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_min(t_stack *stack)
{
	t_stack	*temp;
	t_stack	*min;

	min = stack;
	while (stack != NULL)
	{
		temp = stack->next;
		while (temp != NULL)
		{
			if (temp->content < min->content)
				min = temp;
			temp = temp->next;
		}
		stack = stack->next;
	}
	return (min);
}

int	find_min_pos(t_stack *stack)
{
	int		i;
	t_stack	*min;

	min = find_min(stack);
	i = 0;
	while (stack->content != min->content)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

t_stack	*find_max(t_stack *stack)
{
	t_stack	*temp;
	t_stack	*max;

	max = stack;
	while (stack != NULL)
	{
		temp = stack->next;
		while (temp != NULL)
		{
			if (temp->content > max->content)
				max = temp;
			temp = temp->next;
		}
		stack = stack->next;
	}
	return (max);
}

int	find_max_pos(t_stack *stack)
{
	int		i;
	t_stack	*max;

	max = find_max(stack);
	i = 0;
	while (stack->content != max->content)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int find_node_index(t_stack *stack, int node_value)
{
	int i;

	i = 0;
	while(stack->content != node_value)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int to_top_cost(t_stack *stack, int node_index)
{
	int cost;
	int stacksize;

	stacksize = ft_stacksize(stack);
	if (node_index <= stacksize / 2)
  		cost = node_index;
	else
  		cost = stacksize - node_index;
	return (cost);
}

int find_total_cost(t_stack *a, t_stack *b)
{
	int total_cost;
	int target_node;

	target_node = find_target_node(a, b);
	total_cost = to_top_cost(a, find_node_index(a, target_node));
	return (total_cost);
}


int	a_is_sorted(t_stack *a)
{
	while (a->next != NULL)
	{
		if (a->content > a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}

int	b_is_sorted(t_stack *b)
{
	while (b->next != NULL)
	{
		if (b->content < b->next->content)
			return (0);
		b = b->next;
	}
	return (1);
}

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

int find_target_node(t_stack *a, t_stack *b)
{
	int node_b;
	int target_node;
	int node_a;
	t_stack *b_max;
	t_stack *a_min;
	t_stack *a_max;

	b_max = find_max(b);
	a_min = find_min(a);
	a_max = find_max(a);
	node_b = b->content;
	if (node_b == b_max->content && node_b > a_max->content)
		return (a_min->content);
	target_node = INT32_MAX;
	while(a != NULL)
	{
		node_a = a->content;
		if (node_a > node_b && node_a < target_node)
			target_node = node_a;
		a = a->next;
	}
	if (target_node == INT32_MAX)
		return (a_min->content);
	return (target_node);
}

int find_cheapest_node(t_stack *a, t_stack *b)
{
	int curr_total_cost;
	int next_total_cost;
	int pos_cheapest;
	t_stack *temp_b;
	int i;

	pos_cheapest = 0;
	curr_total_cost = find_total_cost(a, b);
	temp_b = b->next;
	i = 1;
	while (temp_b != NULL)
	{
		next_total_cost = find_total_cost(a, temp_b) + i;
		if (next_total_cost < curr_total_cost)
		{
			curr_total_cost = next_total_cost;
			pos_cheapest = i;
		}
		i++;
		temp_b = temp_b->next;
	}
	return (pos_cheapest);
}

void	a_bring_node_to_top(t_stack **stack, int node_index, int rev_flag)
{
	if (!rev_flag)
  	{
		while(node_index--)
			rotate_a(stack, 1);
	}
	else
	{
  		while(node_index--)
			revrot_a(stack, 1);
	}
}

void	b_bring_node_to_top(t_stack **stack, int node_index, int rev_flag)
{
	if (!rev_flag)
  	{
		while(node_index--)
			rotate_b(stack, 1);
	}
	else
	{
  		while(node_index--)
			revrot_b(stack, 1);
	}
}

void set_rot_dir(int *node_i, int *rev_flag, int stack_size)
{
	if (*node_i > stack_size / 2)
	{
		*rev_flag = 1;
		*node_i = stack_size - *node_i;
	}
}

void bring_nodes_to_top(t_stack **a, t_stack **b, int a_n_i, int b_n_i)
{
	int a_rev;
	int b_rev;

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


void sort_to_b(t_stack **a, t_stack **b)
{
	int cheapest_node_pos;
	int target_node_pos;
	t_stack *temp_b;
	int i;

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


void turk_algo(t_stack **a, t_stack **b)
{
	int a_min_pos;
	int rev_flag;
	int a_size;

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
