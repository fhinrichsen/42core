/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:59:55 by fhinrich          #+#    #+#             */
/*   Updated: 2023/04/27 16:12:18 by fhinrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/pipex.h"

char	*find_path(char **my_cmd, char **envp)
{
	char	*path_var;
	char	**all_paths;
	char	*temp;
	char	*path_to_bin;
	int		i;

	path_to_bin = NULL;
	path_var = get_cmd_path(envp);
	all_paths = ft_split(path_var, ':');
	i = 0;
	while (all_paths[i] != NULL)
	{
		temp = make_path(all_paths[i], my_cmd);
		if (access(temp, X_OK) == 0)
		{
			path_to_bin = malloc((ft_strlen(temp)) * sizeof(char));
			path_to_bin = temp;
			break ;
		}
		free(temp);
		i++;
	}
	if (path_to_bin == NULL)
		ft_perror("No file with -x rights: ", 3);
	return (path_to_bin);
}

char	*make_path(char *potential_path, char **my_cmd)
{
	char	*try_this_one;
	char	*temp;

	temp = ft_strjoin(potential_path, "/");
	try_this_one = ft_strjoin(temp, my_cmd[0]);
	free(temp);
	return (try_this_one);
}

char	*get_cmd_path(char **envp)
{
	char	*path_var;
	int		i;

	i = 0;
	path_var = NULL;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path_var = envp[i] + 5;
			break ;
		}
		i++;
	}
	return (path_var);
}

void	quick_execute(char *command, char **envp)
{
	char	*argv[4];

	if (!ft_strchr(command, '\'') && !ft_strchr(command, '\"'))
		return ;
	argv[0] = "pipex";
	argv[1] = "-c";
	argv[2] = command;
	argv[3] = 0;
	if (execve("/bin/bash", argv, envp))
		perror("execve failed");
}
