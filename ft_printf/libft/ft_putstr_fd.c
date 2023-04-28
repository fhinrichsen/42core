/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:52:15 by fhinrich          #+#    #+#             */
/*   Updated: 2023/02/14 16:43:05 by fhinrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_putstr_fd(char *s, int fd)
{
	char	*str;

	str = s;
	while (*str)
	{
		ft_putchar_fd(*str, fd);
		str++;
	}
	return (ft_strlen(s));
}
