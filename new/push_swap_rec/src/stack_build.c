/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_build.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 21:34:32 by fhinrich          #+#    #+#             */
/*   Updated: 2023/05/01 21:34:33 by fhinrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	read_two_arguments(char *argv)
{
	int		*arguments_i;
	int		count;
	char	**arguments_s;

	count = 0;
	arguments_s = ft_split(argv, ' ');
	valid_int(arguments_s, TRUE);
	while (arguments_s[count] != NULL)
		count++;
	arguments_i = str_arr_to_int_arr(arguments_s, count);
	unique_ints(arguments_i);
}

void	read_n_arguments(char **arguments_s, int argc)
{
	int	*arguments_i;

	valid_int(arguments_s, FALSE);
	arguments_i = str_arr_to_int_arr(arguments_s, argc);
	unique_ints(arguments_i);
	return ;
}
