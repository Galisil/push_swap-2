#include "push_swap.h"
#include <stdlib.h>

// void    tabs_init(char ***name_op, int **nb_op)
// {
//     int i;

//     *name_op = malloc(sizeof(char *) * 12);
//     *nb_op = malloc (sizeof(int) * 11);
// 	if (!name_op || !nb_op)
// 		return ;
//     i = 0;
//     while (i < 12)
//     {
//         (*nb_op)[i] = 0;
//         i++;
//     }
// 	(*name_op)[0] = "sa";
// 	(*name_op)[1] = "sb";
// 	(*name_op)[2] = "ss";
// 	(*name_op)[3] = "pa";
// 	(*name_op)[4] = "pb";
// 	(*name_op)[5] = "ra";
// 	(*name_op)[6] = "rb";
// 	(*name_op)[7] = "rr";
// 	(*name_op)[8] = "rra";
// 	(*name_op)[9] = "rrb";
// 	(*name_op)[10] = "rrr";
// 	(*name_op)[11] = NULL;
// }

void    tabs_init(bench_el **benchmark_tab)
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
	benchmark_tab[11] = NULL;
}

void    update_nb_op(char *operation, bench_el **benchmark_tab)
{
	int	i;

    if (!operation)
		return;
	i = 0;
	while (ft_strcmp(operation, benchmark_tab[i]->name_op) == 1)
		i++;
	if (i > 10)
		return;
	(*benchmark_tab[i]).nb_op++;
}

void	benchmark(t_stack *a, t_stack *b, data_verif *verif, bench_el **benchmark_tab)
{
	//char **name_op;
	//int *nb_op;
    //bench_el    *benchmark_tab;

	if (!verif)
		return ;
    //tabs_init(&name_op, &nb_op);
    tabs_init(benchmark_tab);
}