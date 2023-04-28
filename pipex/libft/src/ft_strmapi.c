/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:02:30 by fhinrich          #+#    #+#             */
/*   Updated: 2023/01/19 11:04:57 by fhinrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*function)(unsigned int, char))
{
	int		i;
	size_t	len;
	char	*buffer;

	len = ft_strlen(s);
	buffer = malloc(len + 1);
	if (!buffer)
		return (NULL);
	i = 0;
	while (s[i])
	{
	buffer[i] = function(i, s[i]);
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}
