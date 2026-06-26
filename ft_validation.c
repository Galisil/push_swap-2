#include "push_swap.h"

void ft_validation(int argc, char **argv, data_verif *verif, t_stack *a)
{
    int i;
    long int result;
    i = 1;
    ft_extract_flag(argv, verif);
    //if(is_duplicata(argv, argc) == 0)
    //{
        while(i < argc)
        {
            if(argv[i][1] != '-')
            {
                if (is_digit(argv[i]) != 0)
                    put_error();
                else 
                {
                    result = ft_atoi(argv[i]);
                    if(result > 2147483647 || result < -2147483648)
                        put_error();
                    //ft_add_back(a, (ft_new_node(result))); duplique la pile a, on create deja la stack dans le main avec create_stack
                }
            }
            i++;
        }
    //}
    //else
      //  put_error();
}

void ft_extract_flag(char **argv, data_verif *verif)
{
    int i;

    i = 1;
    while (argv[i])
        {
            if(argv[i][0] == '-' && argv[i][1] == '-')
            {
                if(ft_strcmp(argv[i], "--simple") == 0)
                    verif->strategy = "SIMPLE";
                else if(ft_strcmp(argv[i], "--medium") == 0)
                    verif->strategy = "MEDIUM";
                else if(ft_strcmp(argv[i], "--complex") == 0)
                    verif->strategy = "COMPLEX";
                else if(ft_strcmp(argv[i], "--adaptive") == 0)
                    verif->strategy = "ADAPTIVE";
                else if(ft_strcmp(argv[i], "--bench") == 0)
                    verif->bench = 1;
                else
                    put_error();
            }
            i++;
        }
}

int    is_duplicata(char **argv, int argc)
{
    int    i;
    int    j;

    i = 1;
    while (i < argc - 1)
    {
        j = i + 1;
        while (j < argc)
        {
            if((argv[i][1] != '-'  && argv[j][1] != '-'))
            {
                    if(ft_atoi(argv[i]) == ft_atoi(argv[j]))
                        return (1);
            }
            j++;
        }
        i++;
    }
    return (0);
}