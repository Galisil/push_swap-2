#include "push_swap.h"
#include <stdio.h>

// int main(int argc, char **argv)
// {
//     t_stack a;
//     t_stack b;
//     t_node *tmp;
//     data_verif verif;

//     init_structs(&a, &b, &verif);
//     ft_validation(argc, argv, &verif, &a);

//     tmp = a.start;
//     while (tmp)
//     {
//         printf("%ld,\n", tmp->valeur);
//         tmp = tmp->next;
//     }
//     algo_simple(&a, &b);
//     tmp = a.start;
//     while (tmp)
//     {
//         printf("%ld,\n", tmp->valeur);
//         tmp = tmp->next;
//     }
//     ft_stack_clear(&a);
//     ft_data_clear(&verif);
//     return 0;
// }

#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    t_stack a;
    t_stack b;
    t_node *tmp;
    data_verif verif;

    init_structs(&a, &b, &verif);
    ft_validation(argc, argv, &verif, &a);

    printf("stack avant changement :\n");
    tmp = a.start;
    while (tmp)
    {
        printf("%ld", tmp->valeur);
        if(tmp->next != NULL)
            printf(", ");
        tmp = tmp->next;
    }
    printf("\n");

    printf("algo simple mouvements :\n");
    algo_simple(&a, &b);

    printf("stack rangÃ©e : \n");
    tmp = a.start;
    while (tmp)
    {
        printf("%ld", tmp->valeur);
        if(tmp->next != NULL)
            printf(", ");
        tmp = tmp->next;
    }

    ft_stack_clear(&a);
    ft_data_clear(&verif);
    return 0;
}