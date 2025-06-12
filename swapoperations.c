/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapoperations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamiba <ddamiba@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 15:28:13 by ddamiba           #+#    #+#             */
/*   Updated: 2025/06/09 17:39:06 by ddamiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_a(t_list **a, int print_flag)
{
	t_list *temp;

	if ((*a)->next == NULL || (*a)->content == NULL)
		return ;
	temp = (*a)->next;
	(*a)->next = (*a)->next->next;
	ft_lstadd_front(a, temp);
	if (print_flag)
		write(1, "sa\n", 3);
}

void swap_b(t_list **b, int print_flag)
{
	t_list *temp;

	if ((*b)->next == NULL || (*b)->content == NULL)
		return ;
	temp = (*b)->next;
	(*b)->next = (*b)->next->next;
	ft_lstadd_front(b, temp);
	if (print_flag)
		write(1, "sb\n", 3);
}

void swap_a_b(t_list **a, t_list **b)
{
	swap_a(a, 0);
	swap_b(b, 0);
	write(1, "ss\n", 3);
}