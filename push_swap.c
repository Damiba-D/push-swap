/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamiba <ddamiba@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:35:14 by ddamiba           #+#    #+#             */
/*   Updated: 2025/07/03 15:57:22 by ddamiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_arr(char **arr)
{
	int i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr[i]);
	free(arr);
}

int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;
	int was_split;

	was_split = 0;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		argc = ft_count_numbers(argv[1], ' ');
		argv = ft_split(argv[1], ' ');
		was_split = 1;
	}
	if (check_error(argc, argv))
	{
		if (was_split)
			ft_free_arr(argv);
		return(write(2, "Error\n", 7));
	}
	stack_a = NULL;
	stack_b = NULL;
	populate_stack(argc, argv, &stack_a);
	if (was_split)
		ft_free_arr(argv);
	if (check_duplicates(stack_a))
	{
		ft_stackclear(&stack_a);
		return(write(2, "Error\n", 7));
	}
	turk_algo(&stack_a, &stack_b);
/*  	if (a_is_sorted(stack_a))
		ft_printf("A IS SORTED!\n"); */
	//print_stack(stack_a);
	ft_stackclear(&stack_a);
	ft_stackclear(&stack_b);
}
