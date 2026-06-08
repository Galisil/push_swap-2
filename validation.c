/*fonctions a implementer
-lire args (fournis en input)(argv)
-verifier que chaque valeur est un digit
-detecter doublons
-gerer les erreurs (?)
/

#include <stdio.h>

int    ft_strlen(const chars)
{
    int    i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

// int     is_digit(char *stack) //OK
// {
//     int i;
//     int is_neg;

//     i = 0;
//     is_neg = 0;
//     while (stack[i])
//     {printf("stack[i] == %c\n", stack[i]);
//         if (stack[i] == '-')
//             is_neg += 1;
//         if (is_neg > 1)
//             return (1);
//         if ((stack[i] < '0' || stack[i] > '9') && stack[i] != '-')
//             return (1);
//         i++;
//         }
//     return (0);
// }

int is_duplicata(char stack, int argc)
{
    int    i;
    int j;
    int k;
    //int len_i;
    int len_stack_j;

    i = 0;
    while (i < argc - 1)
    {
        //len_i = ft_strlen(stack[i]);
        j = i + 1;
        len_stack_j = ft_strlen(stack[j]);
        printf("stack[j] = %s\n", stack[j]);
        while (stack[j])
        {
            k = 0;
            while (stack[i][k] == stack[j][k])
                k++;
        }
    }
    return (0);
}

// int main(int argc, char argv)
// {//test is_digit
//     (void)argc;
//     if (argc < 3)
//         return (1);
//     int i;

//     i = 1;
//     while (i < argc)
//     {
//         if (is_digit(argv[i]) == 1)
//         {
//             printf("le nb %s n'est pas valide ntm\n", argv[i]);
//             return (1);
//         }
//         i++;
//     }
//     printf("tous les nbs sont valides\n");
//     return 0;
// }

int main(int argc, char **argv)
{//test is_duplicata
    (void)argc;
    if (argc < 3)
        return (1);
    int i;

    i = 1;
    if (is_duplicata(argv, argc) == 1)
    {
        printf("there is at least one duplicata in the inputs");
        return (1);
    }
    printf("There is no duplicata in your shit");
    printf("tous les nbs sont valides\n");
    return 0;
}