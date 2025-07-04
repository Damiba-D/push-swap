/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapoperations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamiba <ddamiba@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 15:28:13 by ddamiba           #+#    #+#             */
/*   Updated: 2025/07/04 21:13:18 by ddamiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a(t_stack **a, int print_flag)
{
	t_stack	*temp;

	if ((*a)->next == NULL || ft_stacksize(*a) == 1)
		return ;
	temp = (*a)->next;
	(*a)->next = (*a)->next->next;
	ft_stackadd_front(a, temp);
	if (print_flag)
		write(1, "sa\n", 3);
}

void	swap_b(t_stack **b, int print_flag)
{
	t_stack	*temp;

	if ((*b)->next == NULL || ft_stacksize(*b) == 1)
		return ;
	temp = (*b)->next;
	(*b)->next = (*b)->next->next;
	ft_stackadd_front(b, temp);
	if (print_flag)
		write(1, "sb\n", 3);
}

void	swap_a_b(t_stack **a, t_stack **b)
{
	swap_a(a, 0);
	swap_b(b, 0);
	write(1, "ss\n", 3);
}
