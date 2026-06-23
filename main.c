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
int	main(int argc, char **argv)
{
	t_stack a;
	t_stack b;
	t_node *tmp;
	data_verif verif;

	ft_create_stack(argv, &a, argc);
	b.start = NULL;
	b.end = NULL;
	b.size = 0;

	algo_complex(&a, &b);

	printf("stack rangÃ©e : \n");
	tmp = a.start;
	while (tmp)
	{
		printf("%ld", tmp->valeur);
		if (tmp->next != NULL)
			printf(", ");
		tmp = tmp->next;
	}

	ft_stack_clear(&a);
	ft_data_clear(&verif);
	return (0);
}



// //verif index
// 	tmp = a.start;
// 	while (tmp->next)
// 	{
// 		printf("index de %ld = %d\n", tmp->valeur, tmp->index);
// 		tmp = tmp->next;
// 	}
// 	printf("index de %ld = %d\n", tmp->valeur, tmp->index);