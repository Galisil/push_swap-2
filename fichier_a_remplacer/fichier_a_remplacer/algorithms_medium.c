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
				ft_ra(a, 0);
			else
				ft_rra(a, 0);
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
	max = cur->index;
	pos = 0;
	max_pos = 0;
	while (cur)
	{
		if (cur->index > max)
		{
			max = cur->index;
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
	//int	size_b;

	//size_b = b->size;
	while (b->start)
	{
		max_pos = find_max_pos(b);
		while (max_pos > 0)
		{
			if (max_pos <= b->size / 2)
				ft_rb(b, 0);
			else
				ft_rrb(b, 0);
			max_pos = find_max_pos(b);
		}
		ft_pa(a, b);
	}
}

void	algo_medium(t_stack *a, t_stack *b)
{
	t_node	*cursor;
	int		a_size;

	a_size = a->size;
	if (a_size <= 100)
		push_to_b(a, b, 5);
	else if (a_size > 100 && a_size <= 500)
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
	compute_index(b, b->size);
	algo_simple_cpy(a, b);
}
