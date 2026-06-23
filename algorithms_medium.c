/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_medium.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julimare <julimare@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 15:18:06 by julimare          #+#    #+#             */
/*   Updated: 2026/06/19 15:18:11 by julimare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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

void	push_to_b(t_stack *a, t_stack *b, int nb_chunks)
{
	int	chunk_size;
	int	min_index;
	int	max_index;
	int	nb_pushes;
	int	a_size;

	a_size = a->size;
	chunk_size = (a_size / nb_chunks) + 1;
	min_index = 0;
	max_index = chunk_size;
	while (a->start)
	{
		nb_pushes = 0;
		while (nb_pushes < chunk_size && a->start)
		{
			a_size = a->size;
			if (a->start->index <= max_index)
			{
				ft_pb(a, b);
				nb_pushes++;
			}
			else if (a->start->index <= a_size / 2)
				ft_ra(a);
			else
				ft_rra(a);
		}
		min_index += chunk_size;
		max_index += chunk_size;
	}
}

int	find_max_pos(t_stack *b)
{
	t_node	*cur;
	int		max;
	int		pos;
	int		max_pos;

	cur = b->start;
	max = cur->valeur;
	pos = 0;
	max_pos = 0;
	while (cur)
	{
		if (cur->valeur > max)
		{
			max = cur->valeur;
			max_pos = pos;
		}
		cur = cur->next;
		pos++;
	}
	return (max_pos);
}

void	algo_simple_cpy(t_stack *a, t_stack *b)
{
	int	max_pos;
	int	size_b;

	while (b->start)
	{
		max_pos = find_max_pos(b);
		while (max_pos > 0)
		{
			size_b = b->size;
			if (max_pos <= size_b / 2)
				ft_rb(b);
			else
				ft_rrb(b);
			max_pos--;
		}
		ft_pa(a, b);
	}
}

void	algo_medium(t_stack *a, t_stack *b, int size)
{
	t_node	*cursor;

	if (size <= 100)
		push_to_b(a, b, 5);
	else if (size > 100 && size <= 500)
		push_to_b(a, b, 11);
	else
		push_to_b(a, b, 20);
	cursor = b->start;
	if (!cursor)
	{
		printf("b est vide\n");
		return ;
	}
	while (cursor)
	{
		cursor->index = -1;
		cursor = cursor->next;
	}
	compute_index(b, size);
	algo_simple_cpy(a, b);
}
