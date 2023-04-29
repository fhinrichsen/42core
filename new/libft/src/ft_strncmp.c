/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:29:30 by fhinrich          #+#    #+#             */
/*   Updated: 2023/04/29 15:51:52 by fhinrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*buffer1;
	const unsigned char	*buffer2;
	int					diff;

	buffer1 = (const unsigned char *)s1;
	buffer2 = (const unsigned char *)s2;
	if (n == 0)
		return (0);
	n--;
	while (*buffer1 == *buffer2 && n && *buffer2 && *buffer1)
	{
		buffer2++;
		buffer1++;
		n--;
	}
	diff = *(buffer1) - *(buffer2);
	return (diff);
}
