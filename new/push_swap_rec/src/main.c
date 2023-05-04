/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 21:35:42 by fhinrich          #+#    #+#             */
/*   Updated: 2023/05/04 19:58:19 by fhinrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	if (argc == 1)
		exit(1);
	argv++;
	if (argc == 2)
	{
		any_empty_s(argv);
		read_two_arguments(*argv);
	}
	else
	{
		any_empty_s(argv);
		argc--;
		read_n_arguments(argv, argc);
	}
	return (0);
}
