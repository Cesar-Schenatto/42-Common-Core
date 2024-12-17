/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaugust <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:26:35 by ceaugust          #+#    #+#             */
/*   Updated: 2024/12/17 12:17:44 by ceaugust         ###   ########.fr       */
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
			return (free_and_null(&buffer));
		if (bytes_read == 0)
			break ;
		temp[bytes_read] = '\0';
		buffer = append_buffer(buffer, temp);
		if (!buffer)
			return (NULL);
	}
	line = extract_line(buffer);
	buffer = trim_buffer(buffer);
	return (line);
}
