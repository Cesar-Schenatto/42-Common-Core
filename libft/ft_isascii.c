/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaugust <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:57:04 by ceaugust          #+#    #+#             */
/*   Updated: 2024/10/22 21:08:06 by ceaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

/*int main (void) 
{
	int i = 125;
	while (i < 130)
	{
		ft_putnbr_fd(ft_isascii(i), 1);
		i++;	
	}
	return 0;
}*/
