/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamiba <ddamiba@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:43:39 by ddamiba           #+#    #+#             */
/*   Updated: 2025/07/01 10:15:24 by ddamiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void populate_stack(int argc, char **argv, t_stack **stack)
{
	t_stack *temp_1;
	t_stack *temp_2;
	int i;

	i = 0;
	if (!is_valid_number(argv[i]))
		i++;
	if ((*stack) == NULL)
	{
		(*stack) = ft_stacknew(ft_atoi(argv[i]));
		i++;
	}
	temp_1 = *stack;
	while(i < argc)
	{
		temp_2 = ft_stacknew(ft_atoi(argv[i]));
		temp_1->next = temp_2;
		temp_1 = temp_1->next;
		i++;
	}
}
