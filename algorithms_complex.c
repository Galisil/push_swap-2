#include "push_swap.h"

//(index >> bit) & 1
void	bit_by_bit(t_stack *a, t_stack *b, int size)
{
	int		i;
	int		j;
    int     max_bits;
	t_node	*cursor;

    max_bits = 0;
    while ((size - 1) >> max_bits)
        max_bits++;
        i = 0;
	while (i < max_bits)
	{
        j = 0;
        cursor = a->start;
		while (j < size)
		{
			if (((cursor->index >> i) & 1) == 1)
                ft_ra(a);
            else 
                ft_pb(a, b);
            (cursor->index) >> 1;
            j++;
		}
        while (b->start)
            ft_pa(a, b);
        i++;
	}
}

void	algo_complex(t_stack *a, t_stack *b, int size)
{
	t_node *cursor;

	compute_index(a, size);
	cursor = a->start;
	while (cursor->next != NULL)
	{
		printf("cursor ->index = %d, value = %d\n", cursor->index,
				cursor->valeur);
		cursor = cursor->next;
	}
	printf("cursor ->index = %d, value = %d\n", cursor->index, cursor->valeur);
    bit_by_bit(a, b, size);
    cursor = a->start;
	while (cursor->next != NULL)
	{
		printf("cursor ->index = %d, value = %d\n", cursor->index,
				cursor->valeur);
		cursor = cursor->next;
	}
	printf("cursor ->index = %d, value = %d\n", cursor->index, cursor->valeur);
}