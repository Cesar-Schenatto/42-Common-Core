/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaugust <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:23:12 by ceaugust          #+#    #+#             */
/*   Updated: 2024/10/22 19:36:33 by ceaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

/*int main (void)
{
	ft_putnbr_fd(ft_isalnum(20), 1);
	ft_putnbr_fd(ft_isalnum(55), 1);
	ft_putnbr_fd(ft_isalnum(98), 1);
	return 0;
}*/
