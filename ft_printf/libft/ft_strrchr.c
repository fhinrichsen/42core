/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:34:10 by fhinrich          #+#    #+#             */
/*   Updated: 2023/02/14 16:45:10 by fhinrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, int c)
{
	char	*buffer;
	int		len;

	buffer = str;
	len = ft_strlen(buffer);
	if (c == '\0')
		return (&buffer[len]);
	while (&buffer[len] != str)
	{
		if (buffer[len] == (char)c)
			return (&buffer[len]);
		len--;
	}
	if (buffer[len] == (char)c)
		return (&buffer[len]);
	return (NULL);
}
