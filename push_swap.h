/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamiba <ddamiba@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:46:21 by ddamiba           #+#    #+#             */
/*   Updated: 2025/06/09 18:18:06 by ddamiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include "libft/get_next_line/get_next_line.h"
int check_error(int argc, char **argv);
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



#endif