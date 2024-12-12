/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaugust <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:42:16 by ceaugust          #+#    #+#             */
/*   Updated: 2024/12/12 04:25:43 by ceaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	the_magic(va_list args, char type)
{
	if (type == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (type == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (type == 'd' || type == 'i')
		return (ft_putint(va_arg(args, int)));
	if (type == 'u')
		return (ft_putuint(va_arg(args, unsigned int)));
	if (type == 'x')
		return (ft_puthexa(va_arg(args, unsigned int), 0));
	if (type == 'X')
		return (ft_puthexa(va_arg(args, unsigned int), 1));
	if (type == 'p')
		return (ft_putpointer(va_arg(args, void *)));
	if (type == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			len += the_magic(args, str[++i]);
		}
		else
		{
			ft_putchar(str[i]);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}

/*#include <stdio.h> 

int main (void)
{
	int a = 69;
	int *ptr = &a;
    ft_printf("%c", 'c');
	ft_printf("\n");
	ft_printf("%s","I want to hurt you");
	ft_printf("\n pointer ");
	ft_printf(" %p %p ", 0, 0);
	ft_printf("\n hexa ");
	ft_printf("%x", 255);
	ft_printf("\n hexa again ");
	ft_printf("%X", 255);
	ft_printf("\n hexa again again  "); 
	ft_printf("%x", -255);
	ft_printf("\n unsinged int ");
	ft_printf("%u", 42);
	ft_printf("\n");

    return 0;
}
*/
