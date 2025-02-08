#include "push_swap.h"

/* ************************************************************************** */
/*                                                                            */
/*                            PARSE.C                                         */
/*                                                                            */
/*   This file contains functions for processing the command-line           */
/*   arguments and filling stack A with nodes in the intended order.        */
/*   The intended behavior is that the first number provided is at the top   */
/*   of stack A.                                                            */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>  // For debug prints

/*
** parse_values:
**  - Splits the string 'str' (which may contain multiple numbers separated
**    by spaces) into tokens.
**  - For each token, checks validity, converts it to an int, creates a node,
**    and pushes it onto stack A.
**
** To preserve the order, we iterate the tokens in reverse so that when push()
** (which inserts at the top) is called, the original order is preserved.
*/
int	parse_values(char *str, t_stack *stack)
{
	char	**values;
	int		count;
	int		i;
	int		value;
	t_node	*new_node;

	values = ft_split(str, ' ');
	if (!values)
		return (1);
	count = 0;
	while (values[count])
		count++;
	// Iterate tokens from last to first.
	i = count - 1;
	while (i >= 0)
	{
		printf("Parsing value: %s\n", values[i]);
		if (!is_valid_integer(values[i]))
		{
			printf("Invalid integer: %s\n", values[i]);
			ft_free(values, count);
			free_stack(stack);
			return (1);
		}
		value = ft_atoi(values[i]);
		printf("Converted value: %d\n", value);
		new_node = create_node(value);
		if (!new_node)
		{
			ft_free(values, count);
			free_stack(stack);
			return (1);
		}
		push(stack, new_node);
		print_stack(stack, "A");
		i--;
	}
	ft_free(values, count);
	return (0);
}

/*
** parse_input:
**  - Processes command-line arguments and fills stack A.
**
** To ensure that the first input argument becomes the top of stack A,
** we process the arguments in reverse order (from av[ac-1] down to av[1]).
*/
int	parse_input(int ac, char **av, t_stack *stack)
{
	int	i;

	if (ac < 2 || !stack)
		return (1);
	i = ac - 1;
	while (i >= 1)
	{
		printf("Processing argument: %s\n", av[i]);
		// Handle quoted argument if needed.
		if (av[i][0] == '"' || av[i][0] == '\'')
		{
			char *str = av[i] + 1;
			size_t len = ft_strlen(str);
			if (len > 0 && str[len - 1] == av[i][0])
				str[len - 1] = '\0';
			printf("Quoted argument after removing quotes: %s\n", str);
			if (parse_values(str, stack))
				return (1);
		}
		else
		{
			if (parse_values(av[i], stack))
				return (1);
		}
		i--;
	}
	return (0);
}

