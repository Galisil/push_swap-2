#include "libft.h"

float compute_disorder(int *stack)
{
  //int stack_len = lstsize();
  int i = 0;
  int j = 0;
  int mistakes = 0;
  int total_pairs = 0;
  while (i < 5/*remplacer par stack_len*/)
      total_pairs += 1;
  if (stack[i] > stack[j])
    mistakes += 1;
  return (mistakes / total_pairs);
}

#include <stdio.h>
int main(void)
{
  int a = 4;
  int b = -7;
  int c = 0;
  int d = 89;
  int e = 156;
  int f = 2;
  int g = -10;
  int h = 30;

  t_list  *lst = NULL;
  t_list  *nb1 = ft_lstnew(&a, sizeof(int));
  t_list  *nb2 = ft_lstnew(&b, sizeof(int));
  t_list  *nb3 = ft_lstnew(&c, sizeof(int));
  t_list  *nb4 = ft_lstnew(&d, sizeof(int));
  t_list  *nb5 = ft_lstnew(&e, sizeof(int));
  t_list  *nb6 = ft_lstnew(&f, sizeof(int));
  t_list  *nb7 = ft_lstnew(&g, sizeof(int));
  t_list  *nb8 = ft_lstnew(&h, sizeof(int));

  ft_lstadd_front(&lst, nb1);
  ft_lstadd_front(&lst, nb2);
  ft_lstadd_front(&lst, nb3);
  ft_lstadd_front(&lst, nb4);
  ft_lstadd_front(&lst, nb5);
  ft_lstadd_front(&lst, nb6);
  ft_lstadd_front(&lst, nb7);
  ft_lstadd_front(&lst, nb8);

  t_list *tmp = lst;

    while (tmp)
    {
        printf("%ls\n", (int *)tmp->content);
        tmp = tmp->next;
    }
  /*
  int stack_a[5] = {1, 2, 3, 4, 5};
  int stack_b[5] = {1, 3, 0, -6, 166};
  int stack_c[6] = {9, 8, 7, 6, 5, 4};
  
  printf("stack A = %f\n", compute_disorder(stack_a));
  printf("stack A = %f\n", compute_disorder(stack_b));
  printf("stack A = %f\n", compute_disorder(stack_c));
  //*/
}