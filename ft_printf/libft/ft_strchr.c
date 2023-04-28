/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:54:57 by fhinrich          #+#    #+#             */
/*   Updated: 2023/02/14 16:43:15 by fhinrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*buffer;

	buffer = (char *)str;
	if (c != '\0')
	{
		while (*buffer != ((char) c) && *buffer != '\0')
			buffer++;
	}
	else
	{
		while (*buffer)
			buffer++;
		return (buffer);
	}
	if (*buffer == ((char) c))
		return (buffer);
	return (NULL);
}
