/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaugust <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:50:10 by ceaugust          #+#    #+#             */
/*   Updated: 2024/10/23 20:25:23 by ceaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	int	i;
	int	r;
	int	f;

	i = 0;
	r = 0;
	f = 1;
	while (s[i] == 32 || s[i] == '\t' || s[i] == '\r'
		|| s[i] == '\n' || s[i] == '\f' || s[i] == '\v')
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			f *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		r = r * 10 + (s[i] - '0');
		i++;
	}
	return (f * r);
}
/*int main (void){
	
	char test[] = " \n \t \r \f -69";
	ft_putnbr_fd(ft_atoi(test), 1);
	return 0

}*/
