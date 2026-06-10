#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    (void)argc;
    if (argc < 3)
        return (1);
    t_stack *a;
    t_stack *b;
    t_node  *node;
    t_node  *tmp;
    int i;

    a = malloc(sizeof(t_stack));
    b = malloc(sizeof(t_stack));
    if (!a || !b)
        return (1);
    ft_create_stack(argv, a, argc);
    ft_create_stack(NULL, b, argc);

    //test algo_simple
    tmp = a->start;
    while (tmp)
    {
        printf("valeur node = %d\n", tmp->valeur);
        tmp = tmp->next;
    }
    algo_simple(a, b);
    tmp = a->start;
    printf("\nAPRES\n");
    while (tmp)
    {
        printf("valeur node = %d\n", tmp->valeur);
        tmp = tmp->next;
    }
    return 0;
}