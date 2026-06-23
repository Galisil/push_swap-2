#include "push_swap.h"

void ft_ra(t_stack *a)
{
    t_node  *node;

    if(a->size >= 2)
    {
        write(1, "ra\n", 3);
        node = a->start;
        ft_remove_front(a);
        ft_add_back(a, node);
    }
}


void ft_rb(t_stack *b)
{
    t_node  *node;

    if(b->size >= 2)
    {
        write(1, "rb\n", 3);
        node = b->start;
        ft_remove_front(b);
        ft_add_back(b, node);
    }
}

void ft_rr(t_stack *a, t_stack *b)
{
    if (a)
        ft_ra(a);
    if (b)
        ft_rb(b);
}

void ft_rra(t_stack *a)
{
    t_node  *node;

    if(a->size >= 2)
    {
        write(1, "rra\n", 4);
        node = a->end;
        ft_remove_last(a);
        ft_add_front(a, node);
    }
}

void ft_rrb(t_stack *b)
{
    t_node  *node;

    if(b->size >= 2)
    {
        write(1, "rrb\n", 4);
        node = b->end;
        ft_remove_last(b);
        ft_add_front(b, node);
    }
}

void ft_rrr(t_stack *a, t_stack *b)
{
    if (a)
        ft_rra(a);
    if (b)
        ft_rrb(b);
}

void ft_pa(t_stack *a, t_stack *b)
{
    t_node  *node;

    if (b->size > 0)
    {
        write(1, "pa\n", 3);
        node = b->start;
        ft_remove_front(b);
        ft_add_front(a, node);
    }
}

void ft_pb(t_stack *a, t_stack *b)
{
    t_node      *node;

    if (a->size > 0)
    {
        write(1, "pb\n", 3);
        node = a->start;
        ft_remove_front(a);
        ft_add_front(b, node);
    }
}

void    sa(t_stack *a)
{
    t_node  *node;

    if (!a || !a->start || !a->start->next)
        return;
    write(1, "sa\n", 3);
    node = a->start;
    a->start = a->start->next;
    a->start->next = node;
}

void    sb(t_stack *b)
{
    t_node  *node;

    if (!b || !b->start || !b->start->next)
        return;
    write(1, "sb\n", 3);
    node = b->start;
    b->start = b->start->next;
    b->start->next = node;
}

void    ss(t_stack *a, t_stack *b)
{
    sa(a);
    sb(b);
}