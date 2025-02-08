/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaugust <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:16:06 by ceaugust          #+#    #+#             */
/*   Updated: 2025/02/08 20:31:38 by ceaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push_value_to_stack(char *value_str, t_stack *stack, \
char **values, int count)
{
	int		value;
	t_node	*new_node;

	if (!is_valid_integer(value_str))
	{
		ft_free(values, count);
		free_stack(stack);
		return (1);
	}
	value = ft_atoi(value_str);
	new_node = create_node(value);
	if (!new_node)
	{
		ft_free(values, count);
		free_stack(stack);
		return (1);
	}
	push(stack, new_node);
	return (0);
}

int	parse_values(char *str, t_stack *stack)
{
	char	**values;
	int		count;
	int		i;

	values = ft_split(str, ' ');
	if (!values)
		return (1);
	count = 0;
	while (values[count])
		count++;
	i = count - 1;
	while (i >= 0)
	{
		if (push_value_to_stack(values[i], stack, values, count))
			return (1);
		i--;
	}
	ft_free(values, count);
	return (0);
}

int	parse_input(int ac, char **av, t_stack *stack)
{
	int		i;
	char	*str;
	size_t	len;

	if (ac < 2 || !stack)
		return (1);
	i = ac - 1;
	while (i >= 1)
	{
		if (av[i][0] == '"' || av[i][0] == '\'')
		{
			str = av[i] + 1;
			len = ft_strlen(str);
			if (len > 0 && str[len - 1] == av[i][0])
				str[len - 1] = '\0';
			if (parse_values(str, stack))
				return (1);
		}
		else
			if (parse_values(av[i], stack))
				return (1);
		i--;
	}
	return (0);
}
