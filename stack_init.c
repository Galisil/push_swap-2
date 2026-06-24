#include "push_swap.h"

t_node *ft_new_node(int val)
{
    t_node *new_node;

    new_node = malloc(sizeof(t_node));
    if (!new_node)
        return NULL;
    new_node->valeur = val;
    new_node->index = -1;
    new_node->next = NULL;
    new_node->prev = NULL;
    
    return (new_node);
}

void ft_stack_clear(t_stack *stack)
{
    while (stack->size > 1)
    {
        stack->end = stack->end->prev;
        free(stack->end->next);
        stack->size--;
    }
    free(stack->start);
    stack->start = NULL;
    stack->end = NULL;
    stack->size = 0;
}

void ft_data_clear(data_verif *verif)
{
    verif->bench = 0;
    verif->disorder = 0;
    verif->strategy = NULL;
}

void init_structs(t_stack *a, t_stack *b, data_verif *verif)
{
    a->start = NULL;
    a->size = 0;
    a->end = NULL;
    b->start = NULL;
    b->size = 0;
    b->end = NULL;
    verif->strategy = NULL;
    verif->bench = 0;
    verif->disorder = 0;
}
