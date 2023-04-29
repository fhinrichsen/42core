/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:01:49 by fhinrich          #+#    #+#             */
/*   Updated: 2023/04/29 15:51:19 by fhinrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*function)(unsigned int, char*))
{
	int	i;

	i = 0;
	while (s[i])
	{
		function(i, &s[i]);
	i++;
	}
}
