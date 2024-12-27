/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaugust <ceaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 10:00:38 by ceaugust          #+#    #+#             */
/*   Updated: 2024/12/27 12:45:10 by ceaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h> 

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_twentyfive
{
	char		*dest;
	const char	*src1;
	size_t		len1;
	const char	*src2;
	size_t		len2;
}	t_twentyfive;

//main function

char	*get_next_line(int fd);

// Utility functions 

char	*appender(char *buffer, const char *temp);
char	*extractor(char *buffer);
char	*trimmer(char *buffer);
int		find_newline(const char *buffer);
void	rock_and_roll(char **ptr);

#endif
