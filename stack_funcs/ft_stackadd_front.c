/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackadd_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamiba <ddamiba@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:17:28 by ddamiba           #+#    #+#             */
/*   Updated: 2025/07/03 15:37:48 by ddamiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_stackadd_front(t_stack **stack, t_stack *new)
{
	if (new == NULL || stack == NULL)
		return ;
	if (*stack == NULL)
	{
		*stack = new;
		new->next = NULL;
		return ;
	}
	new->next = *stack;
	*stack = new;
}

/* int main()
{
	// t_list *temp;
	t_list **head = NULL;
	// t_list *lst1 = ft_lstnew("first");
	// t_list *lst2 = ft_lstnew("second");
	// t_list *lst3 = ft_lstnew("third");
	t_list *lst0 = ft_lstnew("zero");

	// lst1->next = lst2;
	// lst2->next = lst3;
	// lst3->next = NULL;
	ft_lstadd_front(head, lst0);
	printf("bom dia???\n");
	printf("%s\n", (char *)(*head)->content);
	// printf("%s\n", (char *)lst0->next);
	// printf("%s\n", (char *)lst0->next->next->next->content);
	// while(lst0)
	// {
	// 	temp = lst0;
	// 	lst0 = lst0->next;
	// 	free(temp);
	// }
	return 0;
} */