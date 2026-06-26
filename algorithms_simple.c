#include "push_swap.h"

int	find_min_pos(t_stack *a)
{
	t_node	*cur;
	int		min;
	int		pos;
	int		min_pos;

	cur = a->start;
	min = cur->valeur;
	pos = 1;
	min_pos = 1;
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

void	algo_simple(t_stack *a, t_stack *b, bench_el *benchmark_tab)
{
	int min_pos;

	while (a->start)
	{
		min_pos = find_min_pos(a);
		while (min_pos > 1)
		{
			ft_ra(a, 0);
			if (benchmark_tab)
				update_nb_op("ra", benchmark_tab);
			min_pos--;
		}
		ft_pb(a, b);
		if (benchmark_tab)
				update_nb_op("pb", benchmark_tab);
	}
	while (b->start)
	{
		ft_pa(a, b);
		if (benchmark_tab)
				update_nb_op("pa", benchmark_tab);
	}
}