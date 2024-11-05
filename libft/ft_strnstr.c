/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaugust <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:07:03 by ceaugust          #+#    #+#             */
/*   Updated: 2024/10/30 21:08:39 by ceaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t n;

	if (*little == '\0')
		return ((char *)big);
	
	n = ft_strlen(little);
	if (len < n)
		return (NULL);
	while(*big && len >= n)
	{
		if (*big == *little && ft_strncmp(big, little, n) == 0)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}

/*int main (void)
{
	char buffer[] = "to say the things";
	char buffer2[] = "he truly feels";
	ft_putstr_fd(ft_strnstr(buffer, buffer2, 20), 1);
	return 0;
}*/