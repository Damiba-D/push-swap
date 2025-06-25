/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamiba <ddamiba@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:43:39 by ddamiba           #+#    #+#             */
/*   Updated: 2025/06/25 16:36:13 by ddamiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void populate_stack(int argc, char **argv, t_stack *list)
{
	t_stack *temp;
	int i;

	i = 2;
	while(i < argc)
	{
		temp = ft_stacknew(ft_atoi(argv[i]));
		list->next = temp;
		list = list->next;
		i++;
	}
}
