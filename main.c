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
    int j;
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

//test algo_simple
    j = 1;
    printf("AVANT\n");
    while (argv[j])
    {
        printf("argv[j] = %d\n", ft_atoi(argv[j]));
        j++;
    }
    j = 1;
    printf("APRES\n");
    algo_simple(a, b);
    while (argv[j])
    {
        printf("argv[i] = %d\n", ft_atoi(argv[j]));
        j++;
    }
    return 0;
}