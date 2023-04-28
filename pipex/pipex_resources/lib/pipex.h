/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:39:54 by fhinrich          #+#    #+#             */
/*   Updated: 2023/04/27 13:54:40 by fhinrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "../../libft/lib/libft.h"
# define READ_END 1
# define WRITE_END 0

//put your function headers here
typedef struct s_data {
	int		infile;
	int		outfile;
	int		pipe[2];
	pid_t	child_id[2];
	char	**cmd_to_execute;
}	t_data;

//errors
void	ft_perror(char *message, int exit_code);
t_data	build_storage(char **argv);
t_data	init_file_storage(void);
t_data	in_out_fds(char **argv, t_data storage);
int		make_child(char **argv, t_data storage, char **envp, int n_child);
void	child(char **argv, t_data storage, char **envp, int n_child);
void	ft_pipex_dup2(t_data storage, int n_child);
char	*find_path(char **my_cmd, char **envp);
char	*make_path(char	*potential_path, char **my_cmd);
char	*get_cmd_path(char **envp);
void	quick_execute(char *command, char **envp);

#endif