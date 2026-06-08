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
    int i;
    int val;

    a = malloc(sizeof(t_stack));
    b = malloc(sizeof(t_stack));
    if (!a || !b)
        return (1);
    i = 1;
    while (i < argc)
    {
        val = ft_atoi(argv[i]);
        node = ft_new_node(val);
        if (i == 1)
            ft_add_front(a, node);
        else
            ft_add_back(a, node);
        i++;
    }
    printf("DISORDER_METRIC = %lf\n", compute_disorder_tab(a, argc));
    return 0;
}