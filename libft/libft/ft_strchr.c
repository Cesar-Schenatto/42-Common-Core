/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaugust <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:56:39 by ceaugust          #+#    #+#             */
/*   Updated: 2024/11/06 21:25:17 by ceaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (!*s)
			return (NULL);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return ((char *)s);
}

/*int main (void)
{
	ft_putstr_fd(ft_strchr("I was made for loving you baby", 'z'), 1);
	return (0); 
}*/

/*while(*s != (char)c)
{
	if(!*s)
	{
		return(NULL);
	}
	s++;
}
 return ((char *)s);*/
