/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaugust <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:44:26 by ceaugust          #+#    #+#             */
/*   Updated: 2024/11/05 17:45:11 by ceaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		++i;
	}
}

/*void leo(unsigned int i, char *c)
{
    if (i % 2 == 0)  
        *c = ft_toupper(*c);
}

int main()
{
    char str[] = "Brings I'll be there!";
    ft_striteri(str, leo);
    ft_putstr_fd(str, 1);
    return 0;
}*/
