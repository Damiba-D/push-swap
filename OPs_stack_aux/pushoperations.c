/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushoperations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamiba <ddamiba@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:49:54 by ddamiba           #+#    #+#             */
/*   Updated: 2025/07/04 21:10:13 by ddamiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_a(t_stack **a, t_stack **b)
{
	t_stack	*newnode;

	if (ft_stacksize(*b) == 0)
		return ;
	newnode = *b;
	*b = (*b)->next;
	ft_stackadd_front(a, newnode);
	write(1, "pa\n", 3);
}

void	push_b(t_stack **a, t_stack **b)
{
	t_stack	*newnode;

	if (ft_stacksize(*a) == 0)
		return ;
	newnode = *a;
	*a = (*a)->next;
	ft_stackadd_front(b, newnode);
	write(1, "pb\n", 3);
}
