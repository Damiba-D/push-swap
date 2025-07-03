/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamiba <ddamiba@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:02:12 by ddamiba           #+#    #+#             */
/*   Updated: 2025/07/03 21:04:32 by ddamiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
