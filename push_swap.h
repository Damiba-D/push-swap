/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamiba <ddamiba@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:46:21 by ddamiba           #+#    #+#             */
/*   Updated: 2025/06/23 17:31:23 by ddamiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include "libft/get_next_line/get_next_line.h"
int check_error(int argc, char **argv);
int check_duplicates(t_list *stack);
void populate_list(int argc, char **argv, t_list *list);
void print_list(t_list *list);
void swap_a(t_list **a, int print_flag);
void swap_b(t_list **b, int print_flag);
void swap_a_b(t_list **a, t_list **b);
void push_a(t_list **a, t_list **b);
void push_b(t_list **a, t_list **b);
void rotate_a(t_list **a, int print_flag);
void rotate_b(t_list **b, int print_flag);
void rotate_a_b(t_list **a, t_list **b);
void revrot_a(t_list **a, int print_flag);
void revrot_b(t_list **b, int print_flag);
void revrot_a_b(t_list **a, t_list **b);
t_list	*find_min(t_list *stack);
t_list	*find_max(t_list *stack);
int find_min_pos(t_list *stack);
int	find_max_pos(t_list *stack);
int a_is_sorted(t_list *a);
void sort_lst_3(t_list **a);
void sort_to_b(t_list **a, t_list **b);
void turk_algo(t_list **a, t_list **b);




#endif