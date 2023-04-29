/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:49:18 by fhinrich          #+#    #+#             */
/*   Updated: 2023/04/29 15:49:21 by fhinrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t length)
{
	unsigned char	*buffer;
	size_t			n;

	n = 0;
	buffer = (unsigned char *) s;
	while (n < length)
	{
		if (buffer[n] == (unsigned char) c)
			return ((void *) &buffer[n]);
		n++;
	}
	return (NULL);
}
