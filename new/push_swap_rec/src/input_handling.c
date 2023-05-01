/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 21:52:20 by fhinrich          #+#    #+#             */
/*   Updated: 2023/05/01 22:18:25 by fhinrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "push_swap.h"

int	*str_arr_to_int_arr(char **arguments_s, int argc)
{
	int	i;
	int	*arguments_i;

	arguments_i = malloc(argc * sizeof(int *));
	if (!arguments_i)
		exit (30);
	i = 0;
	while (arguments_s[i] != NULL)
	{
		arguments_i[i] = ft_strtoint(arguments_s[i]);
		i++;
	}
	arguments_i[i] = '\0';
	return (arguments_i);
}

int	ft_strtoint(const char *str)
{
	long long	val;
	int			sign;
	int			*re;

	sign = 1;
	val = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' && ++str)
		sign = -1;
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		val = val * 10 + (*str - '0');
		check_min_max(val, sign);
		str++;
	}
	re = malloc(sizeof(int));
	if (!re)
		ft_error(0);
	return ((*re = (int) val * sign));
}

void	check_min_max(long long val, int sign)
{
	if (sign == -1)
	{
		if ((val * sign) < INT32_MIN)
			ft_error(0);
	}
	else if (val > INT32_MAX)
	{
		ft_error(0);
	}
	return ;
}
