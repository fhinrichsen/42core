/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:46:55 by fhinrich          #+#    #+#             */
/*   Updated: 2023/04/29 15:49:31 by fhinrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned long		i;
	unsigned char		*buffer;
	const unsigned char	*buffer2;

	if (dest == NULL && src == NULL)
		return (NULL);
	buffer2 = src;
	buffer = dest;
	i = 0;
	while (i < n)
	{
		buffer[i] = buffer2[i];
		i++;
	}
	return (buffer);
}
