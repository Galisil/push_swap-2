#include "push_swap.h"

void	algo_adaptive(t_stack *a, t_stack *b)
{
	data_verif data;

	data.disorder = compute_disorder(a);
	printf("disorder = %.1f\n", data.disorder);
	if (data.disorder < 0.2)
	{
		data.strategy = "SIMPLE";
		algo_simple(a, b);
	}
	else if (data.disorder >= 0.2 && data.disorder < 0.5)
	{
		data.strategy = "MEDIUM";
		algo_medium(a, b);
	}
	else if (data.disorder >= 0.5)
	{
		data.strategy = "COMPLEX";
		algo_complex(a, b);
	}
}