/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 21:35:42 by fhinrich          #+#    #+#             */
/*   Updated: 2023/05/01 21:35:43 by fhinrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	if (argc == 1)
		ft_error(0);
	if (argc == 2)
		read_two_arguments(argv[1]);
	else
		read_n_arguments((argv + 1), argc);
	return (0);
}
