#include "push_swap.h"
#include <stdio.h>

//test algo_simple
// int	main(int argc, char **argv)
// {
// 	t_stack a;
// 	t_stack b;
// 	t_node *tmp;
// 	//data_verif verif;

// 	ft_create_stack(argv, &a, argc);
// 	b.start = NULL;
// 	b.end = NULL;
// 	b.size = 0;

// 	algo_simple(&a, &b);

// 	printf("stack rangÃ©e : \n");
// 	tmp = a.start;
// 	while (tmp)
// 	{
// 		printf("%ld", tmp->valeur);
// 		if (tmp->next != NULL)
// 			printf(", ");
// 		tmp = tmp->next;
// 	}
// }

//test algo_medium
// int	main(int argc, char **argv)
// {
// 	t_stack a;
// 	t_stack b;
// 	t_node *tmp;
// 	data_verif verif;

// 	ft_create_stack(argv, &a, argc);
// 	b.start = NULL;
// 	b.end = NULL;
// 	b.size = 0;

// 	algo_medium(&a, &b);

// 	printf("stack rangÃ©e : \n");
// 	tmp = a.start;
// 	while (tmp)
// 	{
// 		printf("%ld", tmp->valeur);
// 		if (tmp->next != NULL)
// 			printf(", ");
// 		tmp = tmp->next;
// 	}

// 	ft_stack_clear(&a);
// 	ft_data_clear(&verif);
// 	return (0);
// }

//test algo_complex
// int	main(int argc, char **argv)
// {
// 	t_stack a;
// 	t_stack b;
// 	t_node *tmp;
// 	data_verif verif;

// 	ft_create_stack(argv, &a, argc);
// 	b.start = NULL;
// 	b.end = NULL;
// 	b.size = 0;

// 	algo_complex(&a, &b);

// 	printf("stack rangÃ©e : \n");
// 	tmp = a.start;
// 	while (tmp)
// 	{
// 		printf("%ld", tmp->valeur);
// 		if (tmp->next != NULL)
// 			printf(", ");
// 		tmp = tmp->next;
// 	}

// 	ft_stack_clear(&a);
// 	ft_data_clear(&verif);
// 	return (0);
// }

void	display_bench(data_verif verif, bench_el *benchmark_tab)
{
	int	i;

	printf("disorder = %.1f\n", verif.disorder);
	i = 0;
	while (verif.bench == 1 && i < 11)
	{
		printf("%s, nb_op = %d\n",
				benchmark_tab[i].name_op,
				benchmark_tab[i].nb_op);
		i++;
	}
}

//test algo_adaptive
int	main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	t_node		*tmp;
	data_verif	verif;
	bench_el	*benchmark_tab;

	ft_create_stack(argv, &a, argc);
	b.start = NULL;
	b.end = NULL;
	b.size = 0;
	ft_validation(argc, argv, &verif, &a);
	if (verif.bench == 1)
	{
		benchmark_tab = malloc(sizeof(bench_el) * 11);
		if (!benchmark_tab)
			return (-1);
		benchmark(&a, &b, &verif, benchmark_tab);
	}
	tmp = a.start;
	algo_adaptive(&a, &b, &verif, benchmark_tab);
	//montrer les nombres tries
	printf("stack rangÃ©e : \n");
	tmp = a.start;
	while (tmp)
	{
		printf("%ld", tmp->valeur);
		if (tmp->next != NULL)
			printf(", ");
		tmp = tmp->next;
	}
	printf("\n");
	//////
	printf("strategy used = %s\n", verif.strategy);
	if (verif.bench == 1)
		display_bench(verif, benchmark_tab);
	return (0);
}