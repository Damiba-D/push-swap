/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamiba <ddamiba@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:18:18 by ddamiba           #+#    #+#             */
/*   Updated: 2025/07/04 21:08:08 by ddamiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_stack(t_stack *stack)
{
	if (stack == NULL)
		return ;
	while (stack)
	{
		ft_printf("%d\n", stack->content);
		stack = stack->next;
	}
}
