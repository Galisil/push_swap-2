#include "push_swap.h"
#include <stdio.h>

// On peut voir l’algo comme :

// phase 1 (A → B)

// “je range grossièrement les valeurs par zones”

// phase 2 (B → A)

// “je reconstruis un tri parfait en choisissant toujours le bon élément”
// A = chaos initial
// B = sac de valeurs regroupées
// A final = ordre reconstruit

void	compute_index(t_stack *a)
{
    int min;
    int index;
    t_node  *cursor;

	index = 0;
    cursor = a->start;
    min = cursor->valeur;
	while (cursor->next != NULL)
    {
        cursor->index = index;
        cursor = cursor->next;
        index++;
    }
    cursor->index = index;
}

void    compute_pos(t_stack *a, int chunk_size, int index)
{
    int i;
    int pos;
    int min;
    t_node  *cursor;
    t_node  *start;

    pos = 0;
    cursor = a->start;
    min = cursor->valeur;
    while (cursor->index < index)
        cursor = cursor->next;
    start = cursor;
    while (pos < chunk_size)
    {
        cursor = start;
        i = 0;
        while (i < chunk_size)
        {printf("ntm\n");
            if (cursor->valeur < min)
            {
                min = cursor->valeur;
                cursor->pos_in_chunk = pos;
            }
            cursor = cursor->next;
            i++;
        }
        pos++;
    }
}

void	algo_medium(t_stack *a, t_stack *b, int size)
{
    int min_rank;
    int max_rank;
    int i = 0;
    t_node  *cursor;

    cursor = a->start;
    compute_index(a);
    // while (i < size - 1)
    // {
    //     if (cursor->next != NULL)
    //         cursor = cursor->next;
    //     i++;
    // }
    compute_pos(a, 10, 10);
    i = 0;
    while (i < size - 1)
    {
        printf("cursor->pos_in_chunk = %d, val = %d\n", cursor->pos_in_chunk, cursor->valeur);
        if (cursor->next != NULL)
            cursor = cursor->next;
        i++;
    }
    //if (size <= 100) : 5-7 chunks
    //if (size >= 100 et <=500) : 8 a 20 chunks
    //if (size > 500) : 20 a 50 chunks
    //taille d’un chunk = n / nb_chunks
}