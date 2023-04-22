/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 00:26:26 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/04/22 18:45:30 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *buffer)
{
	char	*line;
	size_t	len;

	len = strlen_at(buffer, '\n');
	if (buffer[len] == '\n')
		len++;
	line = cpy_buffer(buffer, len);
	if (!line)
		return (NULL);
	return (line);
}

char	*get_remaining(char *buffer)
{
	char	*leftover;
	size_t	len;
	size_t	new_line;

	len = strlen_at(buffer, '\0');
	new_line = strlen_at(buffer, '\n');
	if (buffer[new_line] == '\n')
		new_line++;
	leftover = cpy_buffer(buffer + new_line, len - new_line + 1);
	if (!leftover)
		return (NULL);
	free(buffer);
	return (leftover);
}

char	*get_current_buffer(int fd, char *buffer)
{
	char	*current;
	ssize_t	bytes;

	bytes = 1;
	current = (char *)malloc(BUFFER_SIZE + 1);
	if (!current)
		return (NULL);
	while (bytes > 0 && !find_chr(buffer, '\n'))
	{
		bytes = read(fd, current, BUFFER_SIZE);
		if (bytes == 0)
			break ;
		if (bytes == -1)
		{
			free(current);
			return (NULL);
		}
		current[bytes] = '\0';
		buffer = merge_previous_and_current(buffer, current);
	}
	free(current);
	if (strlen_at(buffer, '\0') > 0)
		return (buffer);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = get_current_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_line(buffer);
	buffer = get_remaining(buffer);
	if (!buffer[0])
	{
		free (buffer);
		buffer = NULL;
	}
	return (line);
}
