#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_node
{
    int valeur;
    struct s_node *prev;
    struct s_node *next;
}   t_node;

typedef struct s_stack
{
    struct s_node *start;
    int             size;
    struct s_node   *end;
}   t_stack;

t_node *ft_new_node(int val);
void ft_stack_clear(t_stack *stack);

void ft_add_front(t_stack *stack, t_node *node);
void ft_add_back(t_stack *stack, t_node *node);
t_node *ft_remove_front(t_stack *stack);
t_node *ft_remove_last(t_stack *stack);
void ft_create_stack(int *val, t_stack *stack, int size);

void ft_ra(t_stack *a);
void ft_rb(t_stack *b);
void ft_rr(t_stack *a, t_stack *b);
void ft_rra(t_stack *a);
void ft_rrb(t_stack *b);
void ft_rrr(t_stack *a, t_stack *b);
void ft_pa(t_stack *a, t_stack *b);
void ft_pb(t_stack *a, t_stack *b);
void sa(t_stack *a);
void sb(t_stack *b);
void ss(t_stack *a, t_stack *b);

int ft_strlen(const char *s);
int ft_atoi(char *str);
int *put_value(int o, char **nbr);
int is_digit(char *stack);
int is_duplicata(char **stack, int argc);

void put_error(void);

float compute_disorder_lst(t_stack *a, int lst_size);
float compute_disorder_tab(t_stack *a, int lst_size);

void    algo_simple(t_stack *a, t_stack *b);

int main(int argc, char **argv);

#endif