/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 00:26:26 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/04/21 01:51:07 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(char **buffer, char *line)
{
	char	*tmp;
	size_t	len;

	if (!**buffer || !*buffer)
		return (NULL);
	tmp = ft_strchr(*buffer, '\n');
	if (tmp)
	{
		len = tmp - *buffer + 1;
		line = ft_substr(*buffer, 0, len);
		if (!line)
			return (NULL);
		tmp = ft_strdup(*buffer + len);
		if (!tmp)
		{
			free(line);
			return (NULL);
		}
		free(*buffer);
		*buffer = tmp;
	}
	else
	{
		line = ft_strdup(*buffer);
		if (!line)
			return (NULL);
		free(*buffer);
		*buffer = NULL;
	}
	return (line);
}

static int	read_line(int fd, char **buffer)
{
	char	*tmp;
	char	*buf;
	int		bytes_read;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	bytes_read = read(fd, buf, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buf[bytes_read] = '\0';
		if (!*buffer)
			*buffer = ft_strdup(buf);
		else
		{	
			tmp = ft_strjoin(*buffer, buf);
			if (!tmp)
				return (-1);
			free(*buffer);
			*buffer = tmp;
		}
		if (ft_strchr(buf, '\n'))
			break ;
		bytes_read = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (NULL);
	bytes_read = read_line(fd, &buffer[fd]);
	if (bytes_read == -1)
		return (NULL);
	line = get_line(&buffer[fd], NULL);
	return (line);
}
