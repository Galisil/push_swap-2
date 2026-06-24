#include "push_swap.h"

void	compute_index(t_stack *a, int size)
{
	t_node	*cursor;
	t_node	*last_min_find;
	int		min;

	int(index) = 0;
	while (index < size)
	{
		cursor = a->start;
		while (cursor && cursor->index != -1)
			cursor = cursor->next;
		if (!cursor)
			return ;
		last_min_find = cursor;
		min = cursor->valeur;
		while (cursor)
		{
			if ((cursor->valeur < min) && cursor->index == -1)
			{
				last_min_find = cursor;
				min = last_min_find->valeur;
			}
			cursor = cursor->next;
		}
		last_min_find->index = index;
		index++;
	}
}