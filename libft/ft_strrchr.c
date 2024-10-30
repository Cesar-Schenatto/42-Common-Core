/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaugust <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:19:20 by ceaugust          #+#    #+#             */
/*   Updated: 2024/10/30 19:29:36 by ceaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i)
	{
		if (s[i] == (char)c)
			return ((char *)&(s[i]));
		i--;
	}
	if (!c)
		return ((char *)s);
	return (NULL);
}

/*int main (void)
{
	ft_putstr_fd(ft_strrchr("i did it My Way", 'i'), 1);
	return (0);
}*/
