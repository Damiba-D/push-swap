/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamiba <ddamiba@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:35:14 by ddamiba           #+#    #+#             */
/*   Updated: 2025/06/09 18:24:32 by ddamiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;
	t_list *temp;
	
	if (!argv[1] || argc < 3)
		return (0);
	if (check_error(argc, argv))
		return(write(2, "Error\n", 7));
	stack_a = ft_lstnew(argv[1]);
	stack_b = ft_lstnew(NULL);
	populate_list(argc, argv, stack_a);
	rotate_a(&stack_a, 1);
	ft_printf("a\n");
	print_list(stack_a);
	ft_printf("b\n");
	print_list(stack_b);
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