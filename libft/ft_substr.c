/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaugust <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:21:18 by ceaugust          #+#    #+#             */
/*   Updated: 2024/11/05 17:28:59 by ceaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	slen;
	char	*ret;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return ((char *)"");
	if (len > slen - start)
		len = slen - start;
	ret = (char *)malloc(len + 1);
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s + start, len + 1);
	return (ret);
}

/*int main (void)
{
    ft_putstr_fd(ft_substr("\0", 4, 4), 1);
    return (0);
}*/
