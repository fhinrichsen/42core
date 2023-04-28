/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:52:26 by fhinrich          #+#    #+#             */
/*   Updated: 2023/02/14 16:43:29 by fhinrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	char		*destbuffer;
	const char	*srcbuffer;
	size_t		destlen;
	size_t		n;

	destbuffer = dest;
	srcbuffer = src;
	n = size;
	while (*destbuffer != '\0' && n-- > 0)
		destbuffer++;
	destlen = destbuffer - dest;
	n = size - destlen;
	if (n == 0)
		return (destlen + ft_strlen(srcbuffer));
	while (*srcbuffer != '\0')
	{
		if (n != 1)
		{
			*destbuffer++ = *srcbuffer;
			n--;
		}
		srcbuffer++;
	}
	*destbuffer = '\0';
	return (destlen + (srcbuffer - src));
}
