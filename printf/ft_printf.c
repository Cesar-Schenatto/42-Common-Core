/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaugust <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:42:16 by ceaugust          #+#    #+#             */
/*   Updated: 2024/12/03 20:58:42 by ceaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int The_Magic(va_list args, char type)
{
	if (type == 'c')
		return ft_putchar(va_arg(args, int));
	if (type == 's')
		return ft_putstr(va_arg(args, char *));
/*    if (type == 'd' || type == 'i')
    	return ft_putnbr_fd(va_arg(args, int), 1);
	if (type == 'u')
    	return ft_putunbr_fd(va_arg(args, unsigned int), 1);
	if (type == 'x') 
    	return ft_puthex_fd(va_arg(args, unsigned int), 1, 0);
	if (type == 'X')
        return ft_puthex_fd(va_arg(args, unsigned int), 1, 1);
    if (type == 'p')
		return ft_putpointer_fd(va_arg(args, void *), 1);
	if (type == '%')
    	return ft_putchar_fd('%', 1); */
    return (0);
    
}

int	ft_printf(const char *str, ...)
{
    va_list args;
    int     i = 0;
    int     len = 0;

    va_start(args, str);
    while (str[i])
    {
        if (str[i] == '%' && str[i + 1])
        {
            len += The_Magic(args, str[++i]); 
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


int main (void)
{
    ft_printf("%c", 'c');
	ft_printf("\n");
	ft_printf("%s","I want to hurt you");
    return 0;
}

