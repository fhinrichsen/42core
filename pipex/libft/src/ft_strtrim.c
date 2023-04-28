/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:49:58 by fhinrich          #+#    #+#             */
/*   Updated: 2023/01/18 10:50:39 by fhinrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*buffer;
	const char	*last;

	while (*s1)
	{
		if (ft_strchr(set, *s1) == NULL)
			break ;
		s1++;
	}
	buffer = s1;
	last = NULL;
	while (*buffer)
	{
		if (ft_strchr(set, *buffer) == NULL)
			last = buffer;
		buffer++;
	}
	return (ft_substr(s1, 0, (size_t)(last - s1) + 1));
}
