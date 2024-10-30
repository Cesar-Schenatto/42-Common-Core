/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaugust <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:56:39 by ceaugust          #+#    #+#             */
/*   Updated: 2024/10/30 19:29:18 by ceaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((char)c == *s)
			return ((char *)s);
		s++;
	}
	if (!c)
		return ((char *)s);
	return (NULL);
}

/*int main (void)
{
	ft_putstr_fd(ft_strchr("I was made for loving you baby", 'w'), 1);
	return (0); 
}*/
