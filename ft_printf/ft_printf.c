/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:42:54 by fhinrich          #+#    #+#             */
/*   Updated: 2023/02/14 16:49:06 by fhinrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *StringToPrint, ...)
{
	va_list		arguments;
	size_t		index;
	int			printed;

	index = 0;
	printed = 0;
	if (!StringToPrint)
		return (-1);
	va_start(arguments, StringToPrint);
	while (StringToPrint[index])
	{
		if (StringToPrint[index] == '%')
		{
			printed += ft_formats(arguments, StringToPrint[index + 1]);
			index++;
		}
		else
			printed += ft_printchar(StringToPrint[index]);
		index++;
	}
	va_end(arguments);
	return (printed);
}

int	ft_formats(va_list arguments, const char format)
{
	int	printed;

	printed = 0;
	if (format == 'c')
		printed += ft_printchar(va_arg(arguments, int));
	else if (format == 's')
		printed += ft_printstr(va_arg(arguments, char *));
	else if (format == 'p')
		printed += ft_print_ptr(va_arg(arguments, void *));
	else if (format == 'd' || format == 'i')
		printed += ft_printnbr(va_arg(arguments, int));
	else if (format == 'u')
		printed += ft_print_unsigned(va_arg(arguments, unsigned int));
	else if (format == 'x' || format == 'X')
		printed += ft_print_hex(va_arg(arguments, unsigned int), format);
	else if (format == '%')
		printed += write(1, "%", 1);
	return (printed);
}
