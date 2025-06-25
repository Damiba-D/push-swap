/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamiba <ddamiba@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:35:14 by ddamiba           #+#    #+#             */
/*   Updated: 2025/06/25 21:59:11 by ddamiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;
	t_stack *temp;
	
	if (!argv[1] || argc < 3)
		return (0);
	if (check_error(argc, argv))
		return(write(2, "Error\n", 7));
	stack_a = ft_stacknew(ft_atoi(argv[1]));
	stack_b = NULL;
	populate_stack(argc, argv, stack_a);
	if (check_duplicates(stack_a))
		return(write(2, "Error\n", 7));
	turk_algo(&stack_a, &stack_b);
	print_stack(stack_a);
	print_stack(stack_b);
	while(stack_a)
	{
		temp = stack_a;
		stack_a = stack_a->next;
		free(temp);
	}
	while(stack_b)
	{
		temp = stack_b;
		stack_b = stack_b->next;
		free(temp);
	}
	return (0);
}