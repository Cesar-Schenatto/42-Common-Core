/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaugust <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 20:36:55 by ceaugust          #+#    #+#             */
/*   Updated: 2024/11/06 21:53:25 by ceaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fillstr(size_t size, int check, int n, char *ret)
{
	if (n == 0)
		ret[size - 1] = 48;
	while (check < (int)size)
	{
		ret[size - 1] = n % 10 + '0';
		n /= 10;
		size--;
	}
}

int	twentyfivelines(int n)
{
	int	size;

	size = 0;
	if (n == 0)
		size = 1;
	if (n < 0)
		size = 1;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	size_t	size;
	int		check;
	char	*ret;

	size = twentyfivelines(n);
	check = 0;
	ret = (char *)malloc((sizeof(char)) * ((size + 1)));
	if (!ret)
		return (NULL);
	ret[size] = 0;
	if (n == -2147483648)
	{
		ret[0] = '-';
		ret[1] = '2';
		n = 147483648;
		check = 2;
	}
	if (n < 0)
	{
		ret[0] = '-';
		n *= -1;
		check++;
	}
	fillstr(size, check, n, ret);
	return (ret);
}

/*int main (void) 
{
	ft_putstr_fd(ft_itoa(-2147483648), 1);
	return 0;
}*/
