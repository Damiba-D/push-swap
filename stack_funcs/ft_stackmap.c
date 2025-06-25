/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamiba <ddamiba@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:19:37 by ddamiba           #+#    #+#             */
/*   Updated: 2025/06/25 16:28:30 by ddamiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_stackmap(t_stack *stack, int (*f)(int))
{
	t_stack	*temp2;
	t_stack	*newstack;

	if (stack == NULL || f == NULL)
		return (NULL);
	temp2 = NULL;
	while (stack)
	{
		newstack = (t_stack *)malloc(sizeof(t_stack));
		if (newstack == NULL)
		{
			ft_stackclear(&temp2);
			return (NULL);
		}
		newstack->content = f(stack->content);
		newstack->next = NULL;
		ft_stackadd_back(&temp2, newstack);
		stack = stack->next;
	}
	return (temp2);
}

/* static void del_content(void *content)
{
	free(content);
}

static void *map_toupper(void *content)
{
	if (*((char *)content) >= 'a' && *((char *)content) <= 'z')
		*((char *)content) -= 32;
	return (content);
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
	temp = ft_lstmap(lst1, map_toupper, del_content);
	while(temp)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}
	ft_lstclear(&temp, del_content);
	ft_lstclear(&lst1, del_content);
	return 0;
} */
