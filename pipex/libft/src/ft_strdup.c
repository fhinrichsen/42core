/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:48:25 by fhinrich          #+#    #+#             */
/*   Updated: 2023/01/18 10:54:58 by fhinrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*str;
	int		len;

	len = ft_strlen(s) + 1;
	str = malloc(len);
	if (!str)
		return (NULL);
	ft_memmove(str, s, len);
	return (str);
}
