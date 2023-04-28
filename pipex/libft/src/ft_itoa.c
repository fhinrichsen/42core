/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:58:46 by fhinrich          #+#    #+#             */
/*   Updated: 2023/01/19 11:03:51 by fhinrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"
#include <stdlib.h>

size_t	countdigit(long nb)
{
	int	i;

	if (nb == 0)
		return (1);
	i = 0;
	while (nb)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

char	*fill_int_arr(char *buffer, long nb, int sign)
{
	if (nb == 0)
	{
		*(--buffer) = '0';
		return (buffer);
	}
	while (nb)
	{
		*(--buffer) = (nb % 10) + '0';
		nb /= 10;
	}
	if (sign)
		*(--buffer) = '-';
	return (buffer);
}

char	*ft_itoa(int n)
{
	char	*buffer;
	int		sign;
	size_t	ndigit;
	long	nb;

	if (n < 0)
	{
		sign = 1;
		nb = ((long)n) * (-1);
	}
	else
	{
		sign = 0;
		nb = (long)n;
	}
	ndigit = countdigit(nb) + sign;
	buffer = ft_calloc(ndigit + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	fill_int_arr(buffer + ndigit, nb, sign);
	return (buffer);
}
