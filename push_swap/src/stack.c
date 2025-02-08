/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaugust <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 19:03:16 by ceaugust          #+#    #+#             */
/*   Updated: 2025/02/08 20:18:08 by ceaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

void	push(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return ;
	node->next = stack->top;
	stack->top = node;
	stack->size++;
}

t_node	*pop(t_stack *stack)
{
	t_node	*top_node;

	if (!stack || stack->size == 0)
		return (NULL);
	top_node = stack->top;
	stack->top = top_node->next;
	top_node->next = NULL;
	stack->size--;
	return (top_node);
}

int	stack_size(t_stack *stack)
{
	int		size;
	t_node	*current;

	current = stack->top;
	size = 0;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}
