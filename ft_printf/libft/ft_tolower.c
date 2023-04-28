/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:34:29 by fhinrich          #+#    #+#             */
/*   Updated: 2023/02/14 16:45:26 by fhinrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int C)
{
	if (C > 64 && C < 91)
		return (C + 32);
	return (C);
}
