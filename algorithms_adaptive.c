#include "push_swap.h"

void	algo_adaptive(t_stack *a, t_stack *b, data_verif *verif,
		bench_el *benchmark_tab)
{
	(*verif).disorder = compute_disorder(a);
	printf("disorder = %.1f\n", (*verif).disorder);
	if ((*verif).disorder < 0.2)
	{
		(*verif).strategy = "SIMPLE";
		algo_simple(a, b, benchmark_tab);
	}
	else if ((*verif).disorder >= 0.2 && (*verif).disorder < 0.5)
	{
		(*verif).strategy = "MEDIUM";
		algo_medium(a, b, benchmark_tab);
	}
	else if ((*verif).disorder >= 0.5)
	{
		(*verif).strategy = "COMPLEX";
		algo_complex(a, b, benchmark_tab);
	}
}