/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_and_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:55:48 by fhinrich          #+#    #+#             */
/*   Updated: 2023/04/27 15:44:50 by fhinrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/pipex.h"

t_data	build_storage(char **argv)
{
	t_data	storage;

	storage = init_file_storage();
	storage = in_out_fds(argv, storage);
	pipe(storage.pipe);
	if (storage.pipe[0] == -1 || storage.pipe[1] == -1)
		ft_perror("pipe: ", 2);
	return (storage);
}

t_data	init_file_storage(void)
{
	t_data	storage;

	storage.infile = -1;
	storage.outfile = -1;
	storage.pipe[0] = -1;
	storage.pipe[1] = -1;
	storage.child_id[0] = -1;
	storage.child_id[1] = -1;
	storage.cmd_to_execute = 0;
	return (storage);
}

t_data	in_out_fds(char **argv, t_data storage)
{
	storage.outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0000644);
	if (storage.outfile < 0)
		ft_perror("open outfile: ", 127);
	storage.infile = open(argv[1], O_RDONLY);
	if (storage.infile < 0)
		ft_perror("open infile: ", 127);
	return (storage);
}
