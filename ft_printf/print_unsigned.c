/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:14:26 by fhinrich          #+#    #+#             */
/*   Updated: 2023/02/14 16:49:31 by fhinrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	countdigit(long nb)
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

char	*ft_unitoa(unsigned int n)
{
	char	*buffer;
	long	len;

	len = countdigit(n);
	buffer = malloc(len + 1 * sizeof(char));
	if (!buffer)
		return (NULL);
	buffer[len] = '\0';
	while (len-- != 0)
	{
		buffer[len] = (n % 10) + '0';
		n /= 10;
	}
	return (buffer);
}

int	ft_print_unsigned(unsigned int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_unitoa(n);
	len = ft_printstr(num);
	free(num);
	return (len);
}
