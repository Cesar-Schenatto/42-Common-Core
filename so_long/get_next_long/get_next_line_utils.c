/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaugust <ceaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:17:57 by ceaugust          #+#    #+#             */
/*   Updated: 2024/12/27 13:31:44 by ceaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	twentyfivelines(t_twentyfive args)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < args.len1)
	{
		args.dest[i] = args.src1[i];
		i++;
	}
	j = 0;
	while (j < args.len2)
	{
		args.dest[i + j] = args.src2[j];
		j++;
	}
	args.dest[i + j] = '\0';
}

int	find_newline(const char *buffer)
{
	int	i;

	i = 0;
	if (!buffer)
		return (0);
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*appender(char *buffer, const char *temp)
{
	size_t			buffer_len;
	size_t			temp_len;
	char			*new_buffer;
	t_twentyfive	args;

	buffer_len = 0;
	temp_len = 0;
	while (buffer && buffer[buffer_len])
		buffer_len++;
	while (temp && temp[temp_len])
		temp_len++;
	new_buffer = malloc(buffer_len + temp_len + 1);
	if (!new_buffer)
		return (buffer);
	args.dest = new_buffer;
	args.src1 = buffer;
	args.len1 = buffer_len;
	args.src2 = temp;
	args.len2 = temp_len;
	twentyfivelines(args);
	rock_and_roll(&buffer);
	return (new_buffer);
}

char	*extractor(char *buffer)
{
	size_t	i;
	char	*line;
	size_t	j;

	if (!buffer || !*buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		line = malloc(i + 2);
	else
		line = malloc(i + 1);
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = buffer[j];
		j++;
	}
	if (buffer[i] == '\n')
		line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

char	*trimmer(char *buffer)
{
	char	*new_buffer;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i++])
		return (rock_and_roll(&buffer), NULL);
	while (buffer[i + j])
		j++;
	new_buffer = malloc(j + 1);
	if (!new_buffer)
		return (NULL);
	j = 0;
	while (buffer[i])
		new_buffer[j++] = buffer[i++];
	new_buffer[j] = '\0';
	rock_and_roll(&buffer);
	return (new_buffer);
}
