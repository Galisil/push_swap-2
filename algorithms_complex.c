#include "push_swap.h"

//(index >> bit) & 1
void	bit_by_bit(t_stack *a, t_stack *b)
{
	int		i;
	int		j;
    int     max_bits;
	int		a_size;

    max_bits = 0;
	a_size = a->size;
    while ((a_size - 1) >> max_bits)
		max_bits++;
	printf("max_bits = %d\n", max_bits);
    i = 0;
	compute_index(a, a_size);
	while (i < max_bits)
	{
        j = 0;
		a_size = a->size;
		while (j < a_size)
		{
			if (((a->start->index >> i) & 1) == 1)
				ft_ra(a);
            else 
                ft_pb(a, b);
            j++;
		}
        while (b->start)
            ft_pa(a, b);
        i++;
	}
}

void	algo_complex(t_stack *a, t_stack *b)
{
	// t_node *cursor;

	// cursor = a->start;
	// while (cursor->next != NULL)
	// {
	// 	printf("cursor ->index = %d, value = %ld\n", cursor->index,
	// 			cursor->valeur);
	// 	cursor = cursor->next;
	// }
	//printf("cursor ->index = %d, value = %ld\n", cursor->index, cursor->valeur);
    bit_by_bit(a, b);
    // cursor = a->start;
	// while (cursor->next != NULL)
	// {
	// 	printf("cursor ->index = %d, value = %ld\n", cursor->index,
	// 			cursor->valeur);
	// 	cursor = cursor->next;
	// }
	// printf("cursor ->index = %d, value = %ld\n", cursor->index, cursor->valeur);
}