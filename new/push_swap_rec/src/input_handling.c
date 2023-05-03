/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 21:52:20 by fhinrich          #+#    #+#             */
/*   Updated: 2023/05/03 17:31:22 by fhinrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "push_swap.h"

t_stack *handle_input(char **arguments_s, int argc, int created)
{
	int	i;
	int	*arguments_i;
	int	*end;
	int	*error;
	t_stack *stack;

	error = malloc(sizeof(int *));
	*error = 0;
	arguments_i = malloc(argc * sizeof(int));
	if (!arguments_i)
		validation_error(arguments_s);
	i = -1;
	while (arguments_s[++i] != NULL)
		arguments_i[i] = ft_strtoint(arguments_s[i], error);
	if (error)
	{
		free(error);
		if (created)
			validation_error(arguments_s);
		validation_error(0);
	}
	if (created)
		validation_error2(arguments_s);
	end = &arguments_i[i - 1];
	unique_ints(arguments_i, end);
	stack = build_stack(arguments_i, end);
	return (stack);
}

int	ft_strtoint(const char *str, int *error)
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
		if (!check_min_max(val, sign, error))
			return(0);
		str++;
	}
	return ((re = (int) val * sign));
}

int	check_min_max(long long val, int sign, int *error)
{
	if (sign == -1)
	{
		if ((val * sign) < INT32_MIN)
		{
			*error = *error + 1;
			return (FALSE);
		}
	}
	else if (val > INT32_MAX)
		{
			*error = *error + 1;
			return (FALSE);
		}
	return (TRUE);
}
