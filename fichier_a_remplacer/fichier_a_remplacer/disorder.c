#include "push_swap.h"

float compute_disorder(t_stack *a)
{
  t_node *i;
  t_node *p;
  int mstk;
  int pairs;

  i = a->start;
  mstk = 0;
  while(i)
  {
    p = i->next;
    while(p)
    {
      if (i->valeur > p->valeur)
        mstk++;
      p = p->next;
    }
    i = i->next;
  }

  if (a->size < 2)
    return (0.0);
  pairs = a->size * (a->size - 1) / 2;
  return ((float)mstk / pairs);
}