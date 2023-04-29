/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:31:24 by fhinrich          #+#    #+#             */
/*   Updated: 2023/04/29 15:51:58 by fhinrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	lenneedle;
	int		n;
	int		found;

	found = 1;
	n = 0;
	lenneedle = ft_strlen(needle);
	if (!*needle)
		return ((char *)haystack);
	if (!*haystack || ft_strlen(haystack) < lenneedle)
		return (NULL);
	while (len && haystack[n + lenneedle - 1] != '\0')
	{
		if (len < lenneedle)
			break ;
		found = ft_strncmp(&haystack[n], needle, lenneedle);
		if (found == 0)
			break ;
		n++;
		len--;
	}
	if (found != 0)
		return (NULL);
	return ((char *)&haystack[n]);
}
