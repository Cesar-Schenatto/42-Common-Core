/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaugust <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:26:35 by ceaugust          #+#    #+#             */
/*   Updated: 2024/12/21 11:30:11 by ceaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		temp[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!find_newline(buffer))
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			rock_and_roll(&buffer);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		temp[bytes_read] = '\0';
		buffer = appender(buffer, temp);
		if (!buffer)
			return (NULL);
	}
	line = extractor(buffer);
	buffer = trimmer(buffer);
	return (line);
}
