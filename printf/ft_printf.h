/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaugust <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:30:31 by ceaugust          #+#    #+#             */
/*   Updated: 2024/12/12 04:22:44 by ceaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h> 

int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putint(int n);
int	ft_puthexa(unsigned long n, int is_up);
int	ft_putpointer(void *ptr);
int	ft_putnbr_base(unsigned long n, const char *base);
int	ft_putuint(unsigned int n);

#endif
