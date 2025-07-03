/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamiba <ddamiba@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:15:57 by ddamiba           #+#    #+#             */
/*   Updated: 2025/07/03 19:17:05 by ddamiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void set_rot_dir(int *node_i, int *rev_flag, int stack_size)
{
	if (*node_i > stack_size / 2)
	{
		*rev_flag = 1;
		*node_i = stack_size - *node_i;
	}
}