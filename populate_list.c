/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamiba <ddamiba@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:43:39 by ddamiba           #+#    #+#             */
/*   Updated: 2025/06/04 16:21:22 by ddamiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void populate_list(int argc, char **argv, t_list *list)
{
	t_list *temp;
	int i;

	i = 2;
	while(i < argc)
	{
		temp = ft_lstnew(argv[i]);
		list->next = temp;
		list = list->next;
		i++;
	}
}
