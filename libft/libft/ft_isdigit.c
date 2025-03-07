/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaugust <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:38:03 by ceaugust          #+#    #+#             */
/*   Updated: 2024/10/22 18:53:57 by ceaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/*int main (void)
{
	int i = 48; 
	while (i < 58)
	{
		ft_putnbr_fd(ft_isdigit(i), 1);
		i++;
	}
	return 0;
}*/
