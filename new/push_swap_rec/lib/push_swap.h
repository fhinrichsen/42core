/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 21:31:12 by fhinrich          #+#    #+#             */
/*   Updated: 2023/05/03 09:30:56 by fhinrich         ###   ########.fr       */
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
void	validation_error(char **arguments_s);
//stack_build
void	read_two_arguments(char *argv);
void	read_n_arguments(char **arguments_s, int argc);
t_stack	*build_stack(int *start, int *end);
//validation
void	valid_int(char **arguments_s, int created_at_runtime);
void	unique_ints(int *arg_i, int *end);
//int handling
int		ft_strtoint(const char *str);
t_stack *handle_input(char **arguments_s, int argc, int created);
void	check_min_max(long long val, int sign);
//stack operations
t_stack *init_stack();
t_stack *fill_stack_a(t_stack *stack, int *start, int *end);
void	lonely_number(t_stack *stack, int *end);
//node operations
void print_list(t_node *head);
t_node	*new_node(int value);
void	update_node_value(t_node *my_node, int new_val);
t_node	*add_end_node(int val, t_node *top, t_node *prev);

//freeing
void	free_stack(t_stack *stack, int err_no);
void	free_int_helper(int *start);
void free_list(t_node *head);
#endif