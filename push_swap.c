/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamiba <ddamiba@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:35:14 by ddamiba           #+#    #+#             */
/*   Updated: 2025/06/18 18:07:07 by ddamiba          ###   ########.fr       */
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
	if (check_duplicates(stack_a))
		return(write(2, "Error\n", 7));
	turk_algo(&stack_a, &stack_b);
	print_list(stack_a);
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