/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 23:19:49 by fhinrich          #+#    #+#             */
/*   Updated: 2023/02/24 13:02:20 by fhinrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char	*get_next_line(int fd)
{
	char		*current_line;
	static char	*buffer[MAX_FD];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD)
		return (NULL);
	buffer[fd] = gnl_read(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	current_line = get_current_line(buffer[fd]);
	buffer[fd] = free_current_line(buffer[fd]);
	return (current_line);
}

char	*gnl_read(int fd, char *buffer)
{
	int		read_bytes;
	char	*temp_buffer;

	temp_buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp_buffer)
		return (NULL);
	read_bytes = 1;
	while (!gnl_strchr(buffer, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, temp_buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free(temp_buffer), free(buffer), NULL);
		temp_buffer[read_bytes] = '\0';
		buffer = gnl_strjoin(buffer, temp_buffer);
	}
	return (free(temp_buffer), buffer);
}

char	*get_current_line(char *buffer)
{
	int		i;
	char	*current_line;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	current_line = (char *)malloc((i + 2) * sizeof(char));
	if (!current_line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		current_line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		current_line[i++] = '\n';
	current_line[i] = '\0';
	return (current_line);
}

char	*free_current_line(char *buffer)
{
	char	*string_after_nl;
	int		index;

	index = 0;
	while (buffer[index] && buffer[index] != '\n')
		index++;
	if (!buffer[index])
		return (free(buffer), NULL);
	string_after_nl = gnl_strdup(buffer + index + 1);
	return (free(buffer), string_after_nl);
}
