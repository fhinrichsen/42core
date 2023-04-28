/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:44:57 by fhinrich          #+#    #+#             */
/*   Updated: 2023/02/14 16:48:31 by fhinrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"
//put your function headers here
int		ft_printf(const char *StringToPrint, ...);
int		ft_print_hex(unsigned int num, const char format);
int		ft_printchar(int c);
int		ft_printstr(char *str);
void	ft_putstr(char *str);
int		ft_printnbr(int n);
int		ft_printpercent(void);
int		ft_formats(va_list list_of_arguments, const char format);
int		ft_print_unsigned(unsigned int n);
int		ft_print_ptr(void *address);
#endif