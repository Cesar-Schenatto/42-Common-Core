/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaugust <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 23:01:34 by ceaugust          #+#    #+#             */
/*   Updated: 2024/12/12 04:28:51 by ceaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpointer(void *ptr)
{
	int	len;

	if (!ptr)
		return (write(1, "(nil)", 5));
	len = 0;
	len += ft_putstr("0x");
	len += ft_putnbr_base((unsigned long)ptr, "0123456789abcdef");
	return (len);
}
