/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaugust <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 06:32:51 by ceaugust          #+#    #+#             */
/*   Updated: 2024/10/29 19:59:59 by ceaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)s1;
	s = (unsigned char *)s2;
	while (n && *d == *s)
	{
		d++;
		s++;
		n--;
	}
	if (n)
		return (*d - *s);
	else
		return (0);
}
/*int main (void)
{
	char buffer[] = "I was";
	char buffer2[] = "I wbs";
	ft_putnbr_fd(ft_memcmp(buffer, buffer2, 4), 1);
}*/
