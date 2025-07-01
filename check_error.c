/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamiba <ddamiba@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:46:09 by ddamiba           #+#    #+#             */
/*   Updated: 2025/07/01 09:27:56 by ddamiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_valid_number(char *str)
{
	int i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '-' || str[i] == '+')
			i++;
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int check_error(int argc, char **argv)
{
	int		i;
	int		num1;
	long	num2;
	
	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
			return (-1);
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
