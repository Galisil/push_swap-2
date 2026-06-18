#include "push_swap.h"
#include <stdio.h>

void	compute_index(t_stack *a, int size)
{
	int		min;
	int		index;
	t_node	*cursor;
	t_node	*last_min_find;

	index = 0;
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

void	push_to_b(t_stack *a, t_stack *b, int size, int nb_chunks)
{
	int	chunk_size;
	int	min_index;
	int	max_index;
	int	nb_pushes;
	int	j;

	chunk_size = (size / nb_chunks) + 1;
	min_index = 0;
	max_index = chunk_size;
	while (a->start)
	{
		nb_pushes = 0;
		while (nb_pushes < chunk_size && a->start)
		{
			if (a->start->index <= max_index)
			{
				ft_pb(a, b);
				nb_pushes++;
			}
			else
				ft_ra(a);
			//voir pour utiliser aussi rb et rra
		}
		min_index += chunk_size;
		max_index += chunk_size;
	}
	//printf("b->start = %d\n", b->start->valeur);
}

// int find_max_pos(t_stack *b)
// {
//     t_node *cur;
//     int max;
//     int pos;
//     int max_pos;

//     cur = b->start;
//     max = cur->valeur;
//     pos = 1;
//     max_pos = 1;
//     while (cur)
//     {
//         if (cur->valeur < max)
//         {
//             max = cur->valeur;
//             max_pos = pos;
//         }
//         cur = cur->next;
//         pos++;
//     }
//     return (max_pos);
// }

void	algo_medium(t_stack *a, t_stack *b, int size)
{
	int i = 0;      // sert juste pr printf
	t_node *cursor; //pareil, a supprimer

	// cursor = a->start;
	// compute_index(a, size);
	// while (cursor->next != NULL)
	// {
	// 	printf("cursor->index = %d\n", cursor->index);
	// 	cursor = cursor->next;
	// }
	// printf("dernier cursor->index = %d\n", cursor->index);
	if (size <= 100)
		push_to_b(a, b, size, 5);
	else if (size > 100 && size <= 500)
		push_to_b(a, b, size, 11);
	else
		push_to_b(a, b, size, 20);
	cursor = b->start;
	if (!cursor)
	{
		printf("b est vide\n");
		return ;
	}
	compute_index(b, size);
	//while juste pour le test
	while (cursor->next != NULL)
	{
		printf("cursor->index = %d\n", cursor->index);
		cursor = cursor->next;
	}
	printf("dernier cursor->index = %d\n", cursor->index);
	//compute_index(b, size);
}