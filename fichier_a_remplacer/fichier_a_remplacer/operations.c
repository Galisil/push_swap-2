#include "push_swap.h"

void ft_ra(t_stack *a, int rr_oupas)
{
    t_node  *node;

    if(a->size >= 2)
    {
        node = a->start;
        ft_remove_front(a);
        ft_add_back(a, node);
        if(rr_oupas != 1)
            write(1, "ra\n", 3);
    }
}


void ft_rb(t_stack *b, int rr_oupas)
{
    t_node  *node;

    if(b->size >= 2)
    {
        node = b->start;
        ft_remove_front(b);
        ft_add_back(b, node);
        if(rr_oupas != 1)
            write(1, "rb\n", 3);
    }
}

void ft_rr(t_stack *a, t_stack *b)
{
    if (a)
        ft_ra(a, 1);
    if (b)
        ft_rb(b, 1);
    if (a && b)
        write(1, "rr\n", 3);
}

void ft_rra(t_stack *a, int rrr_oupas)
{
    t_node  *node;

    if(a->size >= 2)
    {
        node = a->end;
        ft_remove_last(a);
        ft_add_front(a, node);
        if (rrr_oupas != 1)
            write(1, "rra\n", 4);

    }
}

void ft_rrb(t_stack *b, int rrr_oupas)
{
    t_node  *node;

    if(b->size >= 2)
    {
        node = b->end;
        ft_remove_last(b);
        ft_add_front(b, node);
        if (rrr_oupas != 1)
            write(1, "rrb\n", 4);
    }
}

void ft_rrr(t_stack *a, t_stack *b)
{
    if (a)
        ft_rra(a, 1);
    if (b)
        ft_rrb(b, 1);
    if (a && b)
        write(1, "rrr\n", 4);
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

void    sa(t_stack *a, int ss_oupas)
{
    t_node  *node1;
    t_node  *node2;

    if(a->size > 1)
    {
        node1 = ft_remove_front(a);
        node2 = ft_remove_front(a);
        ft_add_front(a, node1);
        ft_add_front(a, node2);
        if (ss_oupas != 1)
            write(1, "sa\n", 3);
    }
}

void    sb(t_stack *b, int ss_oupas)
{
    t_node  *node1;
    t_node  *node2;

    if(b->size > 1)
    {
        node1 = ft_remove_front(b);
        node2 = ft_remove_front(b);
        ft_add_front(b, node1);
        ft_add_front(b, node2);
        if (ss_oupas != 1)
            write(1, "sb\n", 3);
    }
}

void    ss(t_stack *a, t_stack *b)
{
    if (a)
        sa(a, 1);
    if (b)
        sb(b, 1);
    if (a && b)
        write(1, "ss\n", 3);
}