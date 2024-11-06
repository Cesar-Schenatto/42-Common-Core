/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaugust <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 03:53:27 by ceaugust          #+#    #+#             */
/*   Updated: 2024/10/27 04:47:52 by ceaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	c = (unsigned char)c;
	while (n && *str != c)
	{
		n--;
		str++;
	}
	if (n)
		return ((void *)str);
	else
		return (0);
}
/*int main (void)
{
	char buffer[] = "Hit them with the whole tidal waves";
	char c ='i';
	ft_putendl_fd(ft_memchr(buffer, c, 38), 1);
	return 0;
}*/
