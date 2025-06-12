/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotoperations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamiba <ddamiba@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:51:50 by ddamiba           #+#    #+#             */
/*   Updated: 2025/06/09 18:14:14 by ddamiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void revrot_a(t_list **a, int print_flag)
{
	t_list *temp1;
	t_list *temp2;
	
	temp1 = ft_lstlast(*a);
	temp2 = (*a);
	while (temp2->next->next != NULL)
		temp2 = temp2->next;
	temp2->next = NULL;
	ft_lstadd_front(a, temp1);
	if (print_flag)
		write(1, "rra\n", 4);
}

void revrot_b(t_list **b, int print_flag)
{
	t_list *temp1;
	t_list *temp2;
	
	temp1 = ft_lstlast(*b);
	temp2 = (*b);
	while (temp2->next->next != NULL)
		temp2 = temp2->next;
	temp2->next = NULL;
	ft_lstadd_front(b, temp1);
	if (print_flag)
		write(1, "rrb\n", 4);
}

void revrot_a_b(t_list **a, t_list **b)
{
	revrot_a(a, 0);
	revrot_b(b, 0);
	write(1, "rrr\n", 4);
}