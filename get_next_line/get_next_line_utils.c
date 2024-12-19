/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaugust <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:17:57 by ceaugust          #+#    #+#             */
/*   Updated: 2024/12/17 14:58:32 by ceaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_and_null(char **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

int	find_newline(const char buffer)
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

char	*append_buffer(char *buffer, const char *temp)
{
	char	*new_buffer;
	size_t	buffer_len;
	size_t	temp_len;
	size_t	i;
	size_t	j;

	buffer_len = 0;
	temp_len = 0;
	i = 0;
	j = 0;
	while (buffer && buffer[buffer_len])
		buffer_len++;
	while (temp && temp[temp_len])
		temp_len++;
	new_buffer = malloc(buffer_len + temp_len + 1);
	if (!new_buffer)
		return (NULL);
	while (i < buffer_len)
		new_buffer[i++] = buffer[i];
	while (j < temp_len)
		new_buffer[i + j++] = temp[j];
	new_buffer[i + j] = '\0';
	free_and_null(&buffer);
	return (new_buffer);
}

char	*extract_line(char *buffer)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!buffer || !*buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	while (i--)
		line[i] = buffer[i];
	if (buffer[i + 1] == '\n')
		line[i + 1] = '\n';
	line[i + 2] = '\0';
	return (line);
}

char *trim_buffer(char *buffer)
{
    char *new_buffer;
    size_t i;
	size_t;j

	i = 0;
	j = 0;
    if (!buffer)
        return (NULL);
    while (buffer[i] && buffer[i] != '\n')
        i++;
    if (!buffer[i++])
        return (free_and_null(&buffer), NULL);
    while (buffer[i + j])
        j++;
    new_buffer = malloc(j + 1);
    if (!new_buffer)
        return (free_and_null(&buffer), NULL);
    j = 0;
    while (buffer[i])
        new_buffer[j++] = buffer[i++];
    new_buffer[j] = '\0';
    free_and_null(&buffer);
    return (new_buffer);
}

