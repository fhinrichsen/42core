/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 21:52:20 by fhinrich          #+#    #+#             */
/*   Updated: 2023/05/03 10:13:31 by fhinrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "push_swap.h"

t_stack *handle_input(char **arguments_s, int argc, int created)
{
	int	i;
	int	*arguments_i;
	int	*end;
	t_stack *stack;

	arguments_i = malloc(argc * sizeof(int));
	if (!arguments_i)
		exit (30);
	i = 0;
	while (arguments_s[i] != NULL)
	{
		arguments_i[i] = ft_strtoint(arguments_s[i]);
		if (created)
			free(arguments_s[i]);
		i++;
	}
	end = &arguments_i[i - 1];
	unique_ints(arguments_i, end);
	stack = build_stack(arguments_i, end);
	return (stack);
}

int	ft_strtoint(const char *str)
{
	long long	val;
	int			sign;
	int			re;

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
	return ((re = (int) val * sign));
}

void	check_min_max(long long val, int sign)
{
	if (sign == -1)
	{
		if ((val * sign) < INT32_MIN)
			ft_error(0, 29);
	}
	else if (val > INT32_MAX)
	{
		ft_error(0, 28);
	}
	return ;
}
