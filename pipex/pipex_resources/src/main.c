/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:03:22 by fhinrich          #+#    #+#             */
/*   Updated: 2023/04/27 13:19:21 by fhinrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	storage;
	int		n_child;

	n_child = 0;
	if (argc != 5)
		ft_perror("Usage: pipex infile cmd1 cmd2 outfile\n", 1);
	storage = build_storage(argv);
	n_child = make_child(argv, storage, envp, n_child);
	n_child = make_child(argv, storage, envp, n_child);
	close(storage.infile);
	close(storage.outfile);
	close(storage.pipe[0]);
	close(storage.pipe[1]);
	return (0);
}
