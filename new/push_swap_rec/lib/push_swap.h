/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 21:31:12 by fhinrich          #+#    #+#             */
/*   Updated: 2023/05/23 17:03:06 by fhinrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "../../libft/lib/libft.h"
//put your function headers here

# define FALSE 0
# define TRUE 1

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*a_top;
	t_node	*b_top;
	int		a_size;
	int		b_size;
}	t_stack;

//errors
//20 validation
//30 malloc fail
void	ft_error(t_stack *stack, int err_no);
void	free_split_error(char **arguments_s);
void	free_split_win(char **arguments_s);
//stack_build
t_stack	*read_two_arguments(char *argv);
t_stack	*read_n_arguments(char **arguments, int argc);
t_stack	*build_stack(int *start, int *end);
//validation
void	valid_int(char **arguments_s, int created_at_runtime);
void	unique_ints(int *arg_i, int *end);
void	any_empty_s(char **string_arr);
int		count_args(char **string_arr);
int		*in_range(char **string_arr, int count, int created);
//int handling
int		check_min_max(long long val);
int		ft_atoll(const char *str, int *error);
//stack operations
t_stack	*init_stack(void);
t_stack	*fill_stack_a(t_stack *stack, int *start, int *end);
void	normalize_ints(t_stack *stack);
void	find_min(int new_value, int min, t_stack *stack, t_node	*current);
//node operations
void	print_list(t_node *head);
t_node	*new_node(int value);
void	update_node_value(t_node *my_node, int new_val);
t_node	*add_end_node(int val, t_node *top, t_node *prev);
//operations

//freeing
void	free_stack(t_stack *stack, int err_no);
void	free_list(t_node *head);

int		count_args(char **string_arr);

t_node	*ft_pop(t_node **list);
void	ft_push(t_node **list, t_node *push_this);
void	ft_rotate(int direction, t_node **list);
void	is_sorted(t_stack *stack);
void	ft_swap(t_node **list, char stack_literal);
#endif