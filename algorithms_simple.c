#include "push_swap.h"
#include <stdio.h>

/* int	find_min(t_stack *a)
{
	int		min;
	t_node	*cursor;

	cursor = a->start;
	min = cursor->valeur;
	while (cursor->next != NULL)
	{
		if (cursor->next && (min > cursor->next->valeur))
			min = cursor->next->valeur;
		cursor = cursor->next;
	}printf("min = %d\n", min);
	return (min);
}*/

int find_min_pos(t_stack *a)
{
    t_node *cur;
    int min;
    int pos;
    int min_pos;

    cur = a->start;
    min = cur->valeur;
    pos = 0;
    min_pos = 0;

    while (cur)
    {
        if (cur->valeur < min)
        {
            min = cur->valeur;
            min_pos = pos;
        }
        cur = cur->next;
        pos++;
    }
    return (min_pos);
}

void	algo_simple(t_stack *a, t_stack *b)
{
	int		index;
    int     min;
	t_node	*cursor;

	if (!a || !a->start || !b)
		return ;
    min = find_min(a);
	cursor = a->start;
	index = 1;
	while ((cursor->next != NULL) && cursor->valeur != min)
    {
        cursor = cursor->next;
        index++;
    }
    while (index > 1)
    {
	    ft_ra(a);
        index--;
    }
    ft_pb(a, b);
}

// int main(int argc, char **argv)
// {
//     (void)argc;

//     int i;

//     i = 1;
//     printf("AVANT\n");
//     while (argv[i])
//     {
//         printf("argv[i] = %d\n", ft_atoi(argv[i]));
//         i++;
//     }
//     i = 1;
//     printf("APRES\n");
//     algo_simple(a, b);
//     while (argv[i])
//     {
//         printf("argv[i] = %d\n", ft_atoi(argv[i]));
//         i++;
//     }
// }