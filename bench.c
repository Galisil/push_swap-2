#include "push_swap.h"
#include <stdlib.h>

void    tabs_init(bench_el *benchmark_tab)
{
    benchmark_tab[0] = init_new_bench_el("sa");
	benchmark_tab[1] = init_new_bench_el("sb");
	benchmark_tab[2] = init_new_bench_el("ss");
	benchmark_tab[3] = init_new_bench_el("pa");
	benchmark_tab[4] = init_new_bench_el("pb");
	benchmark_tab[5] = init_new_bench_el("ra");
	benchmark_tab[6] = init_new_bench_el("rb");
	benchmark_tab[7] = init_new_bench_el("rr");
	benchmark_tab[8] = init_new_bench_el("rra");
	benchmark_tab[9] = init_new_bench_el("rrb");
	benchmark_tab[10] = init_new_bench_el("rrr");
}

void    update_nb_op(char *operation, bench_el *benchmark_tab)
{
	int	i;

    if (!operation)
		return;
	i = 0;
	while (i < 11 && ft_strcmp(operation, benchmark_tab[i].name_op) != 0)
		i++;
	if (i > 10)
		return;
	benchmark_tab[i].nb_op++;
}

void	benchmark(t_stack *a, t_stack *b, data_verif *verif, bench_el *benchmark_tab)
{
	if (!verif)
		return ;
    tabs_init(benchmark_tab);
}