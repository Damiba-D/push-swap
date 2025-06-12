/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotateoperations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamiba <ddamiba@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 18:16:34 by ddamiba           #+#    #+#             */
/*   Updated: 2025/06/09 18:23:40 by ddamiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate_a(t_list **a, int print_flag)
{
	t_list *temp;
	
	temp = *a;
	*a = (*a)->next;
	temp->next = NULL;
	ft_lstadd_back(a, temp);
	if (print_flag)
		write(1, "ra\n", 4);
}

void rotate_b(t_list **b, int print_flag)
{
	t_list *temp;
	
	temp = *b;
	*b = (*b)->next;
	temp->next = NULL;
	ft_lstadd_back(b, temp);
	if (print_flag)
		write(1, "rb\n", 4);
}

void rotate_a_b(t_list **a, t_list **b)
{
	rotate_a(a, 0);
	rotate_b(b, 0);
	write(1, "rr\n", 4);
}