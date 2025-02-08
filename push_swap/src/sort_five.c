/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceaugust <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:55:34 by ceaugust          #+#    #+#             */
/*   Updated: 2025/02/08 19:46:12 by ceaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min_position(t_stack *stack)
{
	int		min;
	int		pos;
	t_node	*curr;

	min = find_min(stack);
	pos = 0;
	curr = stack->top;
	while (curr)
	{
		if (curr->value == min)
			break ;
		pos++;
		curr = curr->next;
	}
	return (pos);
}

static void	rotate_stack(t_push_swap *ps, int rotations, int direction)
{
	int	i;

	i = 0;
	while (i < rotations)
	{
		if (direction == 1)
			ra(ps);
		else
			rra(ps);
		i++;
	}
}

void	push_min_to_b(t_push_swap *ps)
{
	int	pos;
	int	rotations;
	int	direction;

	if (!ps || !ps->stack_a || ps->stack_a->size == 0)
		return ;
	pos = get_min_position(ps->stack_a);
	if (pos <= ps->stack_a->size / 2)
	{
		rotations = pos;
		direction = 1;
	}
	else
	{
		rotations = ps->stack_a->size - pos;
		direction = -1;
	}
	rotate_stack(ps, rotations, direction);
	pb(ps);
}

void	sort_five(t_push_swap *ps)
{
	if (!ps || !ps->stack_a || ps->stack_a->size != 5)
		return ;
	push_min_to_b(ps);
	push_min_to_b(ps);
	sort_three(ps);
	if (ps->stack_b->size == 2 && \
		ps->stack_b->top->value < ps->stack_b->top->next->value)
		sb(ps);
	pa(ps);
	pa(ps);
}
