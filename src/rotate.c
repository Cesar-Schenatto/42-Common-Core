/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaugust <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:36:56 by ceaugust          #+#    #+#             */
/*   Updated: 2025/02/08 19:34:26 by ceaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*current;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	stack->top = first->next;
	first->next = NULL;
	current = stack->top;
	while (current->next)
		current = current->next;
	current->next = first;
}

void	ra(t_push_swap *ps)
{
	if (ps)
	{
		rotate(ps->stack_a);
		write(1, "ra\n", 3);
	}
}

void	rb(t_push_swap *ps)
{
	if (ps)
	{
		rotate(ps->stack_b);
		write(1, "rb\n", 3);
	}
}

void	rr(t_push_swap *ps)
{
	if (ps)
	{
		rotate(ps->stack_a);
		rotate(ps->stack_b);
		write(1, "rr\n", 3);
	}
}
