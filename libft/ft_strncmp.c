/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaugust <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 19:36:26 by ceaugust          #+#    #+#             */
/*   Updated: 2024/10/30 21:00:43 by ceaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return 0;
	size_t i;

	i = 0;
	while (i < n && s1[i] && s1[i] == s2[i])
		i++;
	if (i == n)
		return 0;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*int main (void)
{
	char buffer[] = "nyaa";
	char buffer2[] = "nyea";
	ft_putnbr_fd(ft_strncmp(buffer, buffer2, 6), 1);
	return 0;
}*/
