/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:50:43 by fhinrich          #+#    #+#             */
/*   Updated: 2023/02/14 16:42:36 by fhinrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t length)
{
	const unsigned char	*buffer1;
	const unsigned char	*buffer2;

	buffer1 = (const unsigned char *) s1;
	buffer2 = (const unsigned char *) s2;
	if (length != 0)
	{
		while (length-- != 0)
		{
			if (*buffer1++ != *buffer2++)
				return (*(--buffer1) - *(--buffer2));
		}
	}
	return (0);
}
