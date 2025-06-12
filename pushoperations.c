/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushoperations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamiba <ddamiba@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:49:54 by ddamiba           #+#    #+#             */
/*   Updated: 2025/06/09 15:00:15 by ddamiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_a(t_list **a, t_list **b)
{
	t_list *newnode;
	
	if ((*b)->content == NULL)
		return ;
	newnode = *b;
	*b = (*b)->next;
	ft_lstadd_front(a, newnode);
	write(1, "pa\n", 3);
}

void push_b(t_list **a, t_list **b)
{
	t_list *newnode;
	
	if ((*a)->content == NULL)
		return ;
	newnode = *a;
	*a = (*a)->next;
	ft_lstadd_front(b, newnode);
	write(1, "pb\n", 3);
}