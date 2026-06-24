#include "push_swap.h"

void     algo_adaptive(t_stack *a)
{
    data_verif data;

    data.disorder = compute_disorder(a);
    if (data.disorder < 0.2)
        data.strategy = "SIMPLE";
    else if (data.disorder >= 0.2 && data.disorder < 0.5)
        data.strategy = "MEDIUM";
    else if (data.disorder >= 0.5)
        data.strategy = "COMPLEX";
}