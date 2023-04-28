/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:52:52 by fhinrich          #+#    #+#             */
/*   Updated: 2023/04/27 13:51:59 by fhinrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/pipex.h"

int	make_child(char **argv, t_data storage, char **envp, int n_child)
{
	pid_t	parent;
	int		status;

	parent = fork();
	if (parent < 0)
		ft_perror("fork: ", 3);
	else if (parent == 0)
	{
		child(argv, storage, envp, n_child);
	}
	else
	{
		storage.child_id[n_child] = parent;
		waitpid(storage.child_id[n_child], &status, WNOHANG);
		n_child++;
		return (n_child);
	}
	return (n_child);
}

void	child(char **argv, t_data storage, char **envp, int n_child)
{
	char	**my_cmd;
	char	*cmd_path;
	char	*temp;

	my_cmd = ft_split(argv[(n_child + 2)], ' ');
	cmd_path = find_path(my_cmd, envp);
	temp = cmd_path;
	ft_pipex_dup2(storage, n_child);
	quick_execute(argv[n_child + 2], envp);
	if (execve(temp, my_cmd++, envp) == -1)
		perror("execve failed");
	free(cmd_path);
	exit(0);
}

void	ft_pipex_dup2(t_data storage, int n_child)
{
	if (n_child == 0)
	{
		if (dup2(storage.infile, STDIN_FILENO) == -1)
			ft_perror("No such file", 1);
		if (dup2(storage.pipe[READ_END], STDOUT_FILENO) == -1)
			ft_perror("dup2: ", 1);
		close(storage.pipe[WRITE_END]);
		return ;
	}
	else
	{
		if (dup2(storage.pipe[WRITE_END], STDIN_FILENO) == -1)
			ft_perror("No such file", 1);
		if (dup2(storage.outfile, STDOUT_FILENO) == -1)
			ft_perror("dup2: ", 1);
		close(storage.pipe[READ_END]);
		return ;
	}
}
