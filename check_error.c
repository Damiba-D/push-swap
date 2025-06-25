/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamiba <ddamiba@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:46:09 by ddamiba           #+#    #+#             */
/*   Updated: 2025/06/25 16:48:48 by ddamiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_error(int argc, char **argv)
{
	int		i;
	int		j;
	int		num1;
	long	num2;
	
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
				return (-1);
			j++;
		}
		num1 = ft_atoi(argv[i]);
		num2 = ft_atol(argv[i]);
		if (num1 != num2)
			return (-1);
		i++;
	}
	return (0);
}

int check_duplicates(t_stack *stack)
{
	t_stack *temp1;
	t_stack *temp2;
	
	while (stack)
	{
		temp1 = stack;
		temp2 = stack->next;
		while (temp2)
		{
			if (temp1->content == temp2->content)
			{
				return (-1);
			}
			temp2 = temp2->next;
		}
		stack = stack->next;
	}
	return (0);
}
