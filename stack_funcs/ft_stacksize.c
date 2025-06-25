/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacksize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamiba <ddamiba@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:42:06 by ddamiba           #+#    #+#             */
/*   Updated: 2025/06/25 16:08:39 by ddamiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_stacksize(t_stack *stack)
{
	int		count;
	t_stack	*temp;

	if (stack == NULL)
		return (0);
	temp = stack;
	count = 1;
	while (temp->next != NULL)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

/* int main()
{
	t_list *lst1 = ft_lstnew("first");
	t_list *lst2 = ft_lstnew("second");
	t_list *lst3 = ft_lstnew("third");
	t_list *lst0 = ft_lstnew("zero");

	lst1->next = lst2;
	lst2->next = lst3;
	lst3->next = NULL;
	ft_lstadd_front(&lst1, lst0);
	printf("%d\n", ft_lstsize(lst0));
	while(lst0)
	{
		temp = lst0;
		lst0 = lst0->next;
		free(temp);
	}
	return 0;
} */