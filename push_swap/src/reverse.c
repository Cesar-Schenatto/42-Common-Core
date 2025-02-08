/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaugust <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:32:52 by ceaugust          #+#    #+#             */
/*   Updated: 2025/02/08 20:15:56 by ceaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack *stack)
{
	t_node	*current;
	t_node	*prev;

	if (!stack || stack->size < 2)
		return ;
	current = stack->top;
	prev = NULL;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	current->next = stack->top;
	stack->top = current;
}

void	rra(t_push_swap *ps)
{
	if (ps)
	{
		reverse_rotate(ps->stack_a);
		write(1, "rra\n", 4);
	}
}

void	rrb(t_push_swap *ps)
{
	if (ps)
	{
		reverse_rotate(ps->stack_b);
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_push_swap *ps)
{
	if (ps)
	{
		reverse_rotate(ps->stack_a);
		reverse_rotate(ps->stack_b);
		write(1, "rrr\n", 4);
	}
}
