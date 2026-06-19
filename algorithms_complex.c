#include "push_swap.h"

//(index >> bit) & 1
void	bit_by_bit(t_stack *a, t_stack *b, int size)
{
	int		i;
	int		j;
	t_node	*cursor;

	i = 0;
	cursor = a->start;
	while (i < size)
	{
		while (j)
		{
			if (cursor->index >> i & 1)
                ft_ra(a);
            else 
                ft_pb(a, b);
            j++;
		}
        cursor = cursor->next;
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
    cursor = b->start;
    while (b->start)
        ft_pa(a, b);
    cursor = a->start;
	while (cursor->next != NULL)
	{
		printf("cursor ->index = %d, value = %d\n", cursor->index,
				cursor->valeur);
		cursor = cursor->next;
	}
	printf("cursor ->index = %d, value = %d\n", cursor->index, cursor->valeur);
}