/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaugust <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:35:19 by ceaugust          #+#    #+#             */
/*   Updated: 2025/02/08 19:36:17 by ceaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
}

void	sa(t_push_swap *ps)
{
	if (ps)
	{
		swap(ps->stack_a);
		write(1, "sa\n", 3);
	}
}

void	sb(t_push_swap *ps)
{
	if (ps)
	{
		swap(ps->stack_b);
		write(1, "sb\n", 3);
	}
}

void	ss(t_push_swap *ps)
{
	if (ps)
	{
		swap(ps->stack_a);
		swap(ps->stack_b);
		write(1, "ss\n", 3);
	}
}
