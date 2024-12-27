/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaugust <ceaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:17:57 by ceaugust          #+#    #+#             */
/*   Updated: 2024/12/27 12:09:39 by ceaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


void twentyfivelines (twentyfive args)
{
    size_t  i;
    size_t  j;

    i = 0;
    while(i < args.len1)
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

char *appender(char *buffer, const char *temp)
{
    size_t buffer_len = 0;
    size_t temp_len = 0;
    char *new_buffer;
    
	while (buffer && buffer[buffer_len])
		buffer_len++;
	while (temp && temp[temp_len])
		temp_len++;
    new_buffer = malloc(buffer_len + temp_len + 1);
    if (!new_buffer)
        return NULL;
    twentyfive args = { new_buffer, buffer, buffer_len, temp, temp_len };
    twentyfivelines(args);
	rock_and_roll(&buffer);
	return (new_buffer);
}

char *extractor(char *buffer)
{
    size_t i = 0;
    char *line;

    if (!buffer || !*buffer)
        return NULL;
    while (buffer[i] && buffer[i] != '\n')
        i++;
    line = malloc((buffer[i] == '\n' ? i + 2 : i + 1) + 1);
    if (!line)
        return NULL;
    size_t j = 0;
    while (j < i)
    {
        line[j] = buffer[j];
        j++;
    }
    if (buffer[i] == '\n')
        line[j++] = '\n';
    line[j] = '\0';
    return line;
}

char *trimmer(char *buffer)
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
        return (rock_and_roll(&buffer), NULL);
    j = 0;
    while (buffer[i])
        new_buffer[j++] = buffer[i++];
    new_buffer[j] = '\0';
    rock_and_roll(&buffer);
    return (new_buffer);
}
