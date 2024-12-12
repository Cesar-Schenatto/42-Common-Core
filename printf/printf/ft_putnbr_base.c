/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaugust <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 22:51:15 by ceaugust          #+#    #+#             */
/*   Updated: 2024/12/12 07:06:31 by ceaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long n, const char *base)
{
	int				len;
	unsigned long	base_len;

	len = 0;
	base_len = 0;
	while (base[base_len])
		base_len++;
	if (n == 0)
		return (ft_putchar(base[0]));
	if (n >= base_len)
		len += ft_putnbr_base(n / base_len, base);
	len += ft_putchar(base[n % base_len]);
	return (len);
}
