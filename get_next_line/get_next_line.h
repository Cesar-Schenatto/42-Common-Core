/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaugust <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 10:00:38 by ceaugust          #+#    #+#             */
/*   Updated: 2024/12/15 10:14:00 by ceaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h> 

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

//main function

char	*get_next_line(int fd);

// Utility functions 

char	*append_buffer(char *buffer, const char *temp);
char	*extract_line(char *buffer);
char	*trim_buffer(char *buffer);
int		find_newline(const char *buffer);
void	free_and_null(char **ptr);

#endif
