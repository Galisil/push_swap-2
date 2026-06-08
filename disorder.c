#include "push_swap.h"

float compute_disorder_lst(t_stack *a, int lst_size)
{
  t_node *i;
  t_node *j;
  int mistakes = 0;
  int total_pairs;

  if (!a || !a->start || !a->start->next)
      return (0);

  total_pairs = lst_size - 2;
  i = a->start;
  j = i->next;
  while (j)
  {
    if (i->valeur > j->valeur)
      mistakes++;
    i = i->next;
    j = j->next;
  }
  return ((float)mistakes / total_pairs);
}

float compute_disorder_tab(t_stack *a, int lst_size)
{
  int i;
  int j;
  t_node  *tmp1;
  t_node  *tmp2;
  int mistakes = 0;
  int total_pairs;

  if (!a || !a->start || !a->start->next)
      return (0);

  total_pairs = lst_size - 2;
  i = a->start->valeur;
  j = a->start->next->valeur;
  tmp1 = a->start;
  tmp2 = a->start->next;
  while (tmp2->next != NULL)
  {
    if (i > j)
      mistakes++;
    tmp1 = tmp2;
    tmp2 = tmp2->next;
    i = tmp1->valeur;
    j = tmp2->valeur;
  }
  return ((float)mistakes / total_pairs);
}