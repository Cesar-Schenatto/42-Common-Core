/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaugust <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 23:21:59 by ceaugust          #+#    #+#             */
/*   Updated: 2024/12/12 04:17:54 by ceaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned long n, int is_up)
{
	const char	*base;

	if (is_up)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	return (ft_putnbr_base(n, base));
}
