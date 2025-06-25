/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotateoperations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamiba <ddamiba@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 18:16:34 by ddamiba           #+#    #+#             */
/*   Updated: 2025/06/25 17:44:41 by ddamiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate_a(t_stack **a, int print_flag)
{
	t_stack *temp;
	
	temp = *a;
	*a = (*a)->next;
	temp->next = NULL;
	ft_stackadd_back(a, temp);
	if (print_flag)
		write(1, "ra\n", 4);
}

void rotate_b(t_stack **b, int print_flag)
{
	t_stack *temp;
	
	temp = *b;
	*b = (*b)->next;
	temp->next = NULL;
	ft_stackadd_back(b, temp);
	if (print_flag)
		write(1, "rb\n", 4);
}

void rotate_a_b(t_stack **a, t_stack **b)
{
	rotate_a(a, 0);
	rotate_b(b, 0);
	write(1, "rr\n", 4);
}