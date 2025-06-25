/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacknew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamiba <ddamiba@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:53:55 by ddamiba           #+#    #+#             */
/*   Updated: 2025/06/25 16:07:30 by ddamiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_stacknew(int content)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->content = content;
	stack->next = NULL;
	return (stack);
}

/* int main()
{
	t_list *lst = ft_lstnew("Hello World!");
	printf("%s\n", (char *)lst->content);
	if (lst->next)
		printf("Not NULL");
	return 0;
} */
