#include "push_swap.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int *put_value(int o, char **nbr)
{
    int *val;
    int i;

    i = 0;
    val = malloc(sizeof(int) * (o - 1));
    if (!val)
        return NULL;
    while (i  < o - 1)
    {
        val[i] = ft_atoi(nbr[i + 1]);
        i++;
    }

    return val;
}

int	ft_atoi(char *str)
{
	int	sum;
	int	i;
	int	sign;

	i = 0;
	sum = 0;

	sign = 1;

	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		++i;

	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}

	while (str[i] >= '0' && str[i] <= '9')
	{
		sum = (sum * 10) + (str[i] - '0');
		i++;
	}
	return (sign * sum);
}

int     is_digit(char *stack)
{
    int i;
    int is_neg;

    i = 0;
    is_neg = 0;
    while (stack[i])
    {
        if (stack[i] == '-')
            is_neg += 1;
        if (is_neg > 1)
            return (1);
        if ((stack[i] < '0' || stack[i] > '9') && stack[i] != '-')
            return (1);
        i++;
        }
    return (0);
}

int is_duplicata(char **stack, int argc)
{
    int	i;
    int j;

    i = 1;
    while (i < argc - 1)
    {
        j = i + 1;
        while (j < argc)
        {
            if (ft_atoi(stack[i]) == ft_atoi(stack[j]))
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}