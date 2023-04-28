/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 23:19:41 by fhinrich          #+#    #+#             */
/*   Updated: 2023/02/24 13:02:51 by fhinrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

size_t	gnl_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*gnl_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[gnl_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

void	*gnl_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	if ((dst == src) || n == 0)
		return (dst);
	if (!dst && !src)
		return (0);
	d = (char *)dst;
	s = (const char *)src;
	while (n--)
		d[n] = s[n];
	return (dst);
}

char	*gnl_strdup(const char *s1)
{
	char	*cpy;
	size_t	len;

	len = gnl_strlen(s1) + 1;
	cpy = malloc(sizeof(char) * len);
	if (!cpy)
		return (free(cpy), NULL);
	cpy = gnl_memcpy(cpy, s1, len);
	return (cpy);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*joined_str;
	size_t	index1;
	size_t	index2;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		if (s1)
			s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (free(s1), NULL);
	joined_str = malloc((gnl_strlen(s1) + gnl_strlen(s2) + 1) * sizeof(char));
	if (!joined_str)
		return (NULL);
	index1 = -1;
	index2 = 0;
	while (s1[++index1] != '\0')
		joined_str[index1] = s1[index1];
	while (s2[index2] != '\0')
		joined_str[index1++] = s2[index2++];
	joined_str[gnl_strlen(s1) + gnl_strlen(s2)] = '\0';
	return (free(s1), joined_str);
}
