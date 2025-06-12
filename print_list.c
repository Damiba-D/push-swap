/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamiba <ddamiba@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:18:18 by ddamiba           #+#    #+#             */
/*   Updated: 2025/06/09 12:58:00 by ddamiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_list(t_list *list)
{
	while(list)
	{
		if(list->content != NULL)
			ft_printf("%s\n", (char *)(list->content));
		list = list->next;
	}
}