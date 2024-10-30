/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaugust <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:20:34 by ceaugust          #+#    #+#             */
/*   Updated: 2024/10/30 18:51:50 by ceaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	copylimit;
	size_t	i;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (size == 0)
		return (srclen);
	if (dstlen >= size)
		return (srclen + size);
	copylimit = size - dstlen - 1;
	i = 0;
	while (src[i] != '\0' && i < copylimit)
	{
		dst[i + dstlen] = src[i];
		i++;
	}
	dst[i + dstlen] = '\0';
	return (dstlen + srclen);
}

/*int main (void)
{
	char s1[] = "hi";
	char s2[] = "!!";
	ft_putnbr_fd(ft_strlcat(s1, s2, 19), 1);
	ft_putstr_fd(s1, 1);
	return 0;

}*/
