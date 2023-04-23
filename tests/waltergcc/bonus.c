/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 01:08:27 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/04/23 12:14:09 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	main(void)
{
	int		fd;
	char	*line;
	char	titles[3][20] = {"poem.txt", "math.txt", "article.txt"};

	for (int i = 0; i < 3; i++)
	{
		printf("\nReading file %i...\n\n", i + 1);
		fd = open(titles[i], O_RDONLY);
		if (fd == -1)
		{
			perror("open");
			return (1);
		}
		line = get_next_line(fd);
		while (line)
		{
			printf("%s", line);
			free(line);
			line = get_next_line(fd);
		}
		close(fd);
	}
	return (0);
}
