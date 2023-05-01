#include <limits.h>
#include "push_swap.h"

int *strarrtointarr(char **arguments_s, int argc)
{
	int i;
	int	*arguments_i;

	arguments_i = malloc(argc * sizeof(int *));
	i = 0;
	while (arguments_s[i] != NULL)
	{
		arguments_i[i] = ft_strtoint(arguments_s[i]);
		i++;
	}
	arguments_i[i] = '\0';
	return(arguments_i);
}

int ft_strtoint(const char *str)
{
	long val;
	int sign;
	int digit;
	int *re;

	sign = 1;
	val = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9') 
	{
		digit = *str - '0';
		val = val * 10 + digit;
		if (val > INT_MAX || val < INT_MIN)
			ft_error(0);
		str++;
	}
	re = malloc(1 * sizeof(int));
	*re = (int) val * sign;
	return (*re);
}