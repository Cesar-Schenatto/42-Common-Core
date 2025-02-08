/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaugust <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:02:29 by ceaugust          #+#    #+#             */
/*   Updated: 2025/02/08 20:18:38 by ceaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_free(char **splitted, size_t i)
{
	while (i--)
		free(splitted[i]);
	free(splitted);
	return (NULL);
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	current = stack->top;
	while (current)
	{
		next = current->next;
		free_node(current);
		current = next;
	}
	stack->top = NULL;
	stack->size = 0;
}

void	free_push_swap(t_push_swap *ps)
{
	if (ps)
	{
		if (ps->stack_a)
			free_stack(ps->stack_a);
		if (ps->stack_b)
			free_stack(ps->stack_b);
		free(ps->stack_a);
		free(ps->stack_b);
		free(ps);
	}
}
