/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaugust <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 10:00:38 by ceaugust          #+#    #+#             */
/*   Updated: 2024/12/21 11:16:04 by ceaugust         ###   ########.fr       */
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

char	*appender(char *buffer, const char *temp);
char	*extractor(char *buffer);
char	*trimmer(char *buffer);
int		find_newline(const char *buffer);
void	rock_and_roll(char **ptr);

#endif
