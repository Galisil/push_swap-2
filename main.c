#include "push_swap.h"
#include <stdio.h>

// int main(int argc, char **argv)
// {
//     t_stack a;
//     t_stack b;
//     t_node *tmp;
//     data_verif verif;

//     init_structs(&a, &b, &verif);
//     ft_validation(argc, argv, &verif, &a);

//     tmp = a.start;
//     while (tmp)
//     {
//         printf("%ld,\n", tmp->valeur);
//         tmp = tmp->next;
//     }
//     algo_simple(&a, &b);
//     tmp = a.start;
//     while (tmp)
//     {
//         printf("%ld,\n", tmp->valeur);
//         tmp = tmp->next;
//     }
//     ft_stack_clear(&a);
//     ft_data_clear(&verif);
//     return (0);
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

// 	algo_medium(&a, &b, argc);

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

	algo_complex(&a, &b, argc);

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