/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamiba <ddamiba@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:46:09 by ddamiba           #+#    #+#             */
/*   Updated: 2025/06/23 17:41:01 by ddamiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_error(int argc, char **argv)
{
	int		i;
	int		num1;
	long	num2;
	
	i = 1;
	while (i < argc)
	{
		num1 = ft_atoi(argv[i]);
		num2 = ft_atol(argv[i]);
		if (num1 != num2)
			return (-1);
		i++;
	}
	return (0);
}

int check_duplicates(t_list *stack)
{
	t_list *temp1;
	t_list *temp2;
	
	while (stack)
	{
		temp1 = stack;
		temp2 = stack->next;
		while (temp2)
		{
			if (ft_atoi((char *)temp1->content) == ft_atoi((char *)temp2->content))
			{
				return (-1);
			}
			temp2 = temp2->next;
		}
		stack = stack->next;
	}
	return (0);
}
