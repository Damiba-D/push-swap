/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamiba <ddamiba@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:46:09 by ddamiba           #+#    #+#             */
/*   Updated: 2025/07/07 14:35:09 by ddamiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	ft_count_numbers(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_error(int argc, char **argv)
{
	int		i;
	int		num1;
	long	num2;

	i = 0;
	if (!is_valid_number(argv[i]))
		i++;
	if (!is_valid_number(argv[i]))
		return (-1);
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

int	check_duplicates(t_stack *stack)
{
	t_stack	*temp1;
	t_stack	*temp2;

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

int	parsing(int argc, char **argv, t_stack **stack_a)
{
	int	was_split;

	was_split = 0;
	if (argc == 2)
	{
		argc = ft_count_numbers(argv[1], ' ');
		argv = ft_split(argv[1], ' ');
		was_split = 1;
	}
	if (check_error(argc, argv) || (!argc && was_split))
	{
		if (was_split)
			ft_free_arr(argv);
		return (-1);
	}
	populate_stack(argc, argv, stack_a);
	if (was_split)
		ft_free_arr(argv);
	if (check_duplicates(*stack_a))
	{
		ft_stackclear(stack_a);
		return (-1);
	}
	return (0);
}
