#include "push_swap.h"

long int	ft_atoi(char *str)
{
	long int	sum;
	int	i;
	int	sign;

	i = 0;
	sum = 0;

	sign = 1;

	while (str[i] == ' ' ||(str[i] >= 9 && str[i] <= 13))
		++i;

	if (str[i] == '-'|| str[i] == '+')
	{
		if (str[i] == '-')
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

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int     is_digit(char *stack)
{
    int i;
    int is_neg;

    i = 0;
    is_neg = 0;
    while (stack[i])
    {
        if (stack[i] == '-' || stack[i] == '+')
            is_neg += 1;
        if (is_neg > 1)
            return (1);
        if ((stack[i] < '0' || stack[i] > '9') && stack[i] != '-')
            return (1);
        i++;
        }
    return (0);
}
