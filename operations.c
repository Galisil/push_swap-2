#include "push_swap.h"

void ft_ra(t_stack *a)
{
    int tmp;

    if(a->size >= 2)
    {
        write(1, "ra\n", 3);
        tmp = a->start->valeur;
        ft_remove_front(a);
        ft_add_back(a, ft_new_node(tmp));
    }
}


void ft_rb(t_stack *b)
{
    int tmp;

    if(b->size >= 2)
    {
        write(1, "rb\n", 3);
        tmp = b->start->valeur;
        ft_remove_front(b);
        ft_add_back(b, ft_new_node(tmp));
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
    int tmp;

    if(a->size >= 2)
    {
        write(1, "rra\n", 4);
        tmp = a->end->valeur;
        ft_remove_last(a);
        ft_add_front(a, ft_new_node(tmp));
    }
}

void ft_rrb(t_stack *b)
{
    int tmp;

    if(b->size >= 2)
    {
        write(1, "rrb\n", 4);
        tmp = b->end->valeur;
        ft_remove_last(b);
        ft_add_front(b, ft_new_node(tmp));
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
    int tmp;

    if (b->size > 0)
    {
        write(1, "pa\n", 3);
        tmp = b->start->valeur;
        ft_remove_front(b);
        ft_add_front(a, ft_new_node(tmp));
    }
}

void ft_pb(t_stack *a, t_stack *b)
{
    int tmp;

    if (a->size > 0)
    {
        write(1, "pb\n", 3);
        tmp = a->start->valeur;
        ft_remove_front(a);
        ft_add_front(b, ft_new_node(tmp));
    }
}

void    sa(t_stack *a)
{
    int  tmp;

    if (!a || !a->start || !a->start->next)
        return;
    write(1, "sa\n", 3);
    tmp = a->start->valeur;
    a->start->valeur = a->start->next->valeur;
    a->start->next->valeur = tmp;
}

void    sb(t_stack *b)
{
    int  tmp;

    if (!b || !b->start || !b->start->next)
        return;
    write(1, "sb\n", 3);
    tmp = b->start->valeur;
    b->start->valeur = b->start->next->valeur;
    b->start->next->valeur = tmp;
}

void    ss(t_stack *a, t_stack *b)
{
    sa(a);
    sb(b);
}