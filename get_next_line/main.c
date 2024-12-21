/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaugust <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 09:47:47 by ceaugust          #+#    #+#             */
/*   Updated: 2024/12/21 11:13:11 by ceaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h> //open
#include <stdio.h>
#include <stdlib.h> //exit
#include "get_next_line.h"

int main (void) 
{
	int fd;
	char *line;
	int i = 1;

	fd = open("file.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("oh no");
		return 1;
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("lime %i:  %s", i, line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
