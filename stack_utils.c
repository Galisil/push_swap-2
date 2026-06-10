#include "push_swap.h"

void ft_add_front(t_stack *stack, t_node *node)
{
    if (stack->start == NULL)
    {
        stack->start = node;
        stack->end = node;
        node->prev = NULL;
        node->next = NULL;
        stack->size++;
    }
    else
    {
        node->next = stack->start;
        node->prev = NULL;
        stack->start->prev = node;
        stack->start = node;
        stack->size++;
    }
}

void ft_add_back(t_stack *stack, t_node *node)
{
    if (stack->end == NULL)
        ft_add_front(stack, node);
    else
    {
        stack->end->next = node;
        node->prev = stack->end;
        node->next = NULL;
        stack->end = node;
        stack->size++;
    }
}

t_node *ft_remove_front(t_stack *stack)
{
    if(stack->start == NULL)
        return NULL;
    t_node *tmp;

    tmp = stack->start;
    if (stack->start->next == NULL)
    {
        stack->start = NULL;
        stack->end = NULL;
        stack->size = 0;
    }
    else
    {
        stack->start = stack->start->next;
        stack->start->prev = NULL;
        stack->size--;
    }
    tmp->next = NULL;
    tmp->prev = NULL;
    return tmp;
}

t_node *ft_remove_last(t_stack *stack)
{
    if (stack->end == NULL)
        return NULL;
    t_node *tmp;
    if (stack->start == stack->end)
    {
        tmp = ft_remove_front(stack);
        return tmp;
    }
    else
    {            
            tmp = stack->end;
            stack->end = stack->end->prev;
            stack->end->next = NULL;
            tmp->next = NULL;
            tmp->prev = NULL;
            stack->size--;
            return tmp;
    }
}

void ft_create_stack(char **argv, t_stack *stack, int size)
{
    int i;
    int val;
    t_node  *node;

    stack->size = 0;
    stack->end = NULL;
    stack->start = NULL;
    i = 1;
    if (!argv)
        return;
    while (i < size)
    {
        val = ft_atoi(argv[i]);
        node = ft_new_node(val);
        if (i == 1)
            ft_add_front(stack, node);
        else
            ft_add_back(stack, node);
        i++;
    }
}