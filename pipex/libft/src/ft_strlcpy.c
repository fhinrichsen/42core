/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:54:10 by fhinrich          #+#    #+#             */
/*   Updated: 2023/01/19 11:02:27 by fhinrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t		n;
	char		*d;
	const char	*s;

	s = src;
	d = dest;
	n = size;
	if (n != 0)
	{
		while (--n != 0)
		{
			*d++ = *s;
			if (*s++ == '\0')
				break ;
		}
	}
	if (n == 0)
	{
		if (size != 0)
			*d = '\0';
		while (*s++)
			;
	}
	return (s - src -1);
}
