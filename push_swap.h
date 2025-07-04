/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamiba <ddamiba@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:46:21 by ddamiba           #+#    #+#             */
/*   Updated: 2025/07/04 21:28:02 by ddamiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include "libft/get_next_line/get_next_line.h"

// Stack def & basic funcs
typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}	t_stack;
void			ft_stackadd_back(t_stack **stack, t_stack *new);
void			ft_stackadd_front(t_stack **stack, t_stack *new);
void			ft_stackclear(t_stack **stack);
void			ft_stackdelone(t_stack *stack);
void			ft_stackiter(t_stack *stack, void (*f)(int));
t_stack			*ft_stacklast(t_stack *stack);
t_stack			*ft_stackmap(t_stack *stack, int (*f)(int));
t_stack			*ft_stacknew(int content);
int				ft_stacksize(t_stack *stack);

//Parsing
int				check_error(int argc, char **argv);
int				check_duplicates(t_stack *stack);
int				is_valid_number(char *str);
unsigned int	ft_count_numbers(char const *s, char c);
void			ft_free_arr(char **arr);
int				parsing(int argc, char **argv, t_stack **stack_a);

//Stack aux funcs & operations
void			populate_stack(int argc, char **argv, t_stack **stack);
void			print_stack(t_stack *stack);
void			push_a(t_stack **a, t_stack **b);
void			push_b(t_stack **a, t_stack **b);
void			swap_a(t_stack **a, int print_flag);
void			swap_b(t_stack **b, int print_flag);
void			swap_a_b(t_stack **a, t_stack **b);
void			rotate_a(t_stack **a, int print_flag);
void			rotate_b(t_stack **b, int print_flag);
void			rotate_a_b(t_stack **a, t_stack **b);
void			revrot_a(t_stack **a, int print_flag);
void			revrot_b(t_stack **b, int print_flag);
void			revrot_a_b(t_stack **a, t_stack **b);

//Calculations
t_stack			*find_min(t_stack *stack);
int				find_min_pos(t_stack *stack);
t_stack			*find_max(t_stack *stack);
int				find_max_pos(t_stack *stack);
int				find_node_index(t_stack *stack, int node_value);
int				to_top_cost(t_stack *stack, int node_index);
int				find_total_cost(t_stack *a, t_stack *b);
int				find_target_node(t_stack *a, t_stack *b);
int				find_cheapest_node(t_stack *a, t_stack *b);
void			set_curr_cost(int *curr, int next, int *pos, int i);

//Sorting aux funcs
int				a_is_sorted(t_stack *a);
int				b_is_sorted(t_stack *b);
void			set_rot_dir(int *node_i, int *rev_flag, int stack_size);

//Movement funcs
void			a_bring_node_to_top(t_stack **stack, \
int node_index, int rev_flag);
void			b_bring_node_to_top(t_stack **stack, \
int node_index, int rev_flag);
void			bring_nodes_to_top(t_stack **a, \
t_stack **b, int a_n_i, int b_n_i);

//Algo funcs
void			sort_stack_3(t_stack **a);
void			sort_to_b(t_stack **a, t_stack **b);
void			turk_algo(t_stack **a, t_stack **b);

#endif