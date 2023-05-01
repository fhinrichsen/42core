#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include "../../libft/lib/libft.h"
//put your function headers here

typedef struct s_node
{
    int value;
    struct s_node *prev;
    struct s_node *next;
} t_node;

typedef struct s_stack
{
    t_node *a_top;
    t_node *b_top;
    int a_size;
    int b_size;
} t_stack;

//errors
// 20 validation
/*
20 valid int i did not create
21 self created
*/
void ft_error(t_stack *stack);
void free_stack(t_stack *stack);
void validation_error(char **arguments_s);
//stack_build
void read_two_arguments(char *argv);
void read_n_arguments(char **arguments);
//validation
void valid_int(char **arguments_s, int created_at_runtime);

#endif