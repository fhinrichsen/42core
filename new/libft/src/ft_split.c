/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:00:44 by fhinrich          #+#    #+#             */
/*   Updated: 2023/05/03 15:44:26 by fhinrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *string, char delim)
{
	size_t	count;
	int		index;

	index = 0;
	count = 0;
	while (string[index] != '\0')
	{
		while (string[index] == delim)
			index++;
		if (string[index] != delim && string[index] != '\0')
			count++;
		while (string[index] != delim && string[index] != '\0')
			index++;
	}
	return (count);
}

char	**ft_split(char *tosplit, char delim)
{
	char	**splitted;
	size_t	array_pos;
	size_t	len;

	if (!tosplit)
		return (0);
	array_pos = 0;
	splitted = malloc(sizeof(char *) * (count_words(tosplit, delim) + 1));
	if (!splitted)
		return (0);
	while (*tosplit)
	{
		if (*tosplit != delim)
		{
			len = 0;
			while (*tosplit && *tosplit != delim && ++len)
				++tosplit;
			splitted[array_pos++] = ft_substr(tosplit - len, 0, len);
		}
		else
			tosplit++;
	}
	splitted[array_pos] = 0;
	return (splitted);
}
