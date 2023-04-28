/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:00:37 by fhinrich          #+#    #+#             */
/*   Updated: 2023/02/14 16:43:02 by fhinrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static char	*fill_int_arr(char *buffer, long nb, int sign)
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
	if (sign == (-1))
		*(--buffer) = '-';
	return (buffer);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	buffer[11];
	char	*start;
	int		sign;
	long	nb;

	if (n < 0)
	{
		sign = (-1);
		nb = (long)n * sign;
	}
	else
	{
		sign = 1;
		nb = (long)n * sign;
	}
	start = fill_int_arr(&buffer[11], nb, sign);
	write(fd, start, &buffer[11] - start);
}
