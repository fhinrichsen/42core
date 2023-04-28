/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhinrich <fhinrich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 23:16:11 by fhinrich          #+#    #+#             */
/*   Updated: 2023/02/24 13:01:47 by fhinrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef MAX_FD
#  define MAX_FD 10240
# endif

# include <stdlib.h>
# include <unistd.h>

char	*gnl_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
size_t	gnl_strlen(const char *s);
char	*get_current_line(char *buffer);
char	*free_current_line(char *buffer);
char	*gnl_read(int fd, char *buffer);
char	*gnl_strchr(char *s, int c);
void	*gnl_memcpy(void *dst, const void *src, size_t n);
char	*gnl_strdup(const char *s1);
#endif