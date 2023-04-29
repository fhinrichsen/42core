/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:49:27 by fhinrich          #+#    #+#             */
/*   Updated: 2023/04/29 15:58:02 by fhinrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*sbuffer;
	const char	*send;
	char		*dbuffer;
	char		*dend;

	if (dest == NULL && src == NULL)
		return (NULL);
	dbuffer = dest;
	sbuffer = src;
	if (dbuffer < sbuffer)
	{
		while (n--)
			*(dbuffer++) = *(sbuffer++);
	}
	else
	{
		send = sbuffer + (n -1);
		dend = dbuffer + (n -1);
		while (n--)
			*(dend--) = *(send--);
	}
	return (dest);
}
