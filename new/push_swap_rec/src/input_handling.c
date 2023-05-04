/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 21:52:20 by fhinrich          #+#    #+#             */
/*   Updated: 2023/05/04 19:04:38 by fhinrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "push_swap.h"

int	ft_atoll(const char *str, int *error)
{
	long long	val;
	int			sign;

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
		if (check_min_max(val))
		{
			*error = 1;
			return(0);
		}	
		str++;
	}
	return ((val * sign));
}

int	check_min_max(long long val)
{
	if (val < INT32_MAX && val > INT32_MIN)
		return(FALSE);
	return (TRUE);
}
