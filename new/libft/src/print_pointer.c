/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:13:04 by fhinrich          #+#    #+#             */
/*   Updated: 2023/04/29 19:13:25 by fhinrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_point_len(unsigned	long num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

static void	ft_put_point(unsigned long num)
{
	if (num >= 16)
	{
		ft_put_point(num / 16);
		ft_put_point(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}

int	ft_print_ptr(void *address)
{
	int				printed;
	unsigned long	num;

	printed = 0;
	num = (unsigned long) address;
	printed += write(1, "0x", 2);
	if (address == NULL)
	{
		printed += write(1, "0", 1);
		return (3);
	}
	ft_put_point(num);
	return (printed + ft_point_len(num));
}
