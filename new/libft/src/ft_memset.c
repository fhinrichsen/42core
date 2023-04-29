/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:51:27 by fhinrich          #+#    #+#             */
/*   Updated: 2023/04/29 15:57:45 by fhinrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned long	i;
	unsigned char	*buffer;

	buffer = s;
	i = 0;
	while (i < n)
	{
		buffer[i] = c;
		i++;
	}
	return (buffer);
}
