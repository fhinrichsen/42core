#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include "../../libft/lib/libft.h"
//put your function headers here

#define FALSE 0
#define TRUE 1
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
//30 malloc fail
void ft_error(t_stack *stack);
void free_stack(t_stack *stack);
void validation_error(char **arguments_s);
//stack_build
void read_two_arguments(char *argv);
void read_n_arguments(char **arguments_s, int argc);
//validation
void valid_int(char **arguments_s, int created_at_runtime);
void unique_ints(int *arg_i);
//int handling
int ft_strtoint(const char *str);
int *str_arr_to_int_arr(char **arguments_s, int argc);
#endif