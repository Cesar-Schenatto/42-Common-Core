/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaugust <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:22:22 by ceaugust          #+#    #+#             */
/*   Updated: 2025/02/08 19:32:46 by ceaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_push_swap *ps)
{
	t_node	*node;

	if (ps && ps->stack_b->size > 0)
	{
		node = pop(ps->stack_b);
		if (node)
		{
			push(ps->stack_a, node);
			write(1, "pa\n", 3);
		}
	}
}

void	pb(t_push_swap *ps)
{
	t_node	*node;

	if (ps && ps->stack_a->size > 0)
	{
		node = pop(ps->stack_a);
		if (node)
		{
			push(ps->stack_b, node);
			write(1, "pb\n", 3);
		}
	}
}
