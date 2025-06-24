/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamiba <ddamiba@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 15:38:18 by ddamiba           #+#    #+#             */
/*   Updated: 2025/06/24 18:50:40 by ddamiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_min(t_list *stack)
{
	t_list	*temp;
	t_list	*min;

	min = stack;
	while (stack != NULL)
	{
		temp = stack->next;
		while (temp != NULL)
		{
			if (ft_atoi((char *)temp->content) < ft_atoi((char *)min->content))
				min = temp;
			temp = temp->next;
		}
		stack = stack->next;
	}
	return (min);
}

int	find_min_pos(t_list *stack)
{
	int		i;
	t_list	*min;

	min = find_min(stack);
	i = 0;
	while (ft_atoi((char *)stack->content) != ft_atoi((char *)min->content))
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

t_list	*find_max(t_list *stack)
{
	t_list	*temp;
	t_list	*max;

	max = stack;
	while (stack != NULL)
	{
		temp = stack->next;
		while (temp != NULL)
		{
			if (ft_atoi((char *)temp->content) > ft_atoi((char *)max->content))
				max = temp;
			temp = temp->next;
		}
		stack = stack->next;
	}
	return (max);
}

int	find_max_pos(t_list *stack)
{
	int		i;
	t_list	*max;

	max = find_max(stack);
	i = 0;
	while (ft_atoi((char *)stack->content) != ft_atoi((char *)max->content))
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int	a_is_sorted(t_list *a)
{
	while (a->next != NULL)
	{
		if (ft_atoi((char *)a->content) > ft_atoi((char *)a->next->content))
			return (0);
		a = a->next;
	}
	return (1);
}

int	b_is_sorted(t_list *b)
{
	while (b->next != NULL)
	{
		if (ft_atoi((char *)b->content) < ft_atoi((char *)b->next->content))
			return (0);
		b = b->next;
	}
	return (1);
}

void	sort_lst_3(t_list **a)
{
	int	pos1;
	int	pos2;
	int	pos3;

	pos1 = ft_atoi((char *)(*a)->content);
	pos2 = ft_atoi((char *)(*a)->next->content);
	pos3 = ft_atoi((char *)(*a)->next->next->content);
	if ((pos1 > pos2 && pos2 > pos3))
		return (rotate_a(a, 1), swap_a(a, 1));
	else if (pos1 < pos3 && pos2 > pos3)
		return (revrot_a(a, 1), swap_a(a, 1));
	else if (pos1 > pos2 && pos2 < pos3)
	{
		if (pos1 < pos3)
			return (swap_a(a, 1));
		else
			return (rotate_a(a, 1));
	}
	else if (pos1 < pos2 && pos2 > pos3)
		return (revrot_a(a, 1));
}

void del(void *content)
{
	if (content != NULL)
		content = NULL;
}

int find_target_node(t_list *a, t_list *b)
{
	int node_b;
	t_list *temp;

	node_b = ft_atoi((char *)b->content);
	while(a != NULL)
	{
		if (ft_atoi((char *)a->content) > node_b)
		{
			temp = ft_lstnew(a->content);
			break;
		}
		a = a->next;
	}
	a = a->next;
	while(a != NULL)
	{
		if (ft_atoi((char *)a->content) > node_b)
			ft_lstadd_back(&temp, a);
		a = a->next;
	}
	a = find_min(temp);
	ft_lstclear(&temp, del);
	return (ft_atoi((char *)a->content));
}

void sort_to_b(t_list **a, t_list **b)
{
	while (ft_lstsize(*a) > 3)
		push_b(a, b);
	sort_lst_3(a);
	ft_printf("%d\n", find_target_node(*a, *b));
}


void turk_algo(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) == 1)
		return ;
	else if (ft_lstsize(*a) == 2)
	{
		if (!a_is_sorted(*a))
			return (swap_a(a, 1));
		return ;
	}
	else if (ft_lstsize(*a) == 3)
		return (sort_lst_3(a));
	if (!a_is_sorted(*a))
	{
		push_b(a, b);
		push_b(a, b);
		sort_to_b(a, b); 
	}
}
