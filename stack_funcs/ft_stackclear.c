/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackclear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamiba <ddamiba@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:20:45 by ddamiba           #+#    #+#             */
/*   Updated: 2025/06/25 16:01:23 by ddamiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_stackclear(t_stack **stack)
{
	t_stack	*temp;

	if (*stack == NULL)
		return ;
	temp = *stack;
	while (*stack != NULL)
	{
		temp = *stack;
		*stack = (*stack)->next;
		ft_stackdelone(temp);
	}
}

/* static void del_content(void *content)
{
	free(content);
}

int main()
{
	t_list *temp;
	t_list *lst1 = ft_lstnew(ft_strdup("first"));
	t_list *lst2 = ft_lstnew(ft_strdup("second"));
	t_list *lst3 = ft_lstnew(ft_strdup("third"));
	t_list *lst4 = ft_lstnew(ft_strdup("fourth"));

	lst1->next = lst2;
	lst2->next = lst3;
	lst3->next = lst4;
	ft_lstclear(&lst2, del_content);
	while(lst1)
	{
		temp = lst1;
		printf("%s\n", (char *)temp->content);
		lst1 = lst1->next;
		free(temp);
	}
	return 0;
} */