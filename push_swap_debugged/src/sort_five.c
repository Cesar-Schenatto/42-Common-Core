#include "push_swap.h"

void	push_min_to_b(t_push_swap *ps)
{
	int		min;
	int		pos;
	int		i;
	int		rotations;
	int		direction;
	t_node	*curr;

	if (!ps || !ps->stack_a || ps->stack_a->size == 0)
		return;
	min = find_min(ps->stack_a);
	pos = 0;
	curr = ps->stack_a->top;
	while (curr)
	{
		if (curr->value == min)
			break;
		pos++;
		curr = curr->next;
	}
	if (pos <= ps->stack_a->size / 2)
	{
		rotations = pos;
		direction = 1;  // Use ra
	}
	else
	{
		rotations = ps->stack_a->size - pos;
		direction = -1; // Use rra
	}
	i = 0;
	while (i < rotations)
	{
		if (direction == 1)
			ra(ps);
		else
			rra(ps);
		i++;
	}
	pb(ps);
}

void	sort_five(t_push_swap *ps)
{
	if (!ps || !ps->stack_a || ps->stack_a->size != 5)
		return;
	push_min_to_b(ps); // Remove smallest
	push_min_to_b(ps); // Remove second smallest
	sort_three(ps);    // Sort the remaining three elements in A
	// Ensure B is in descending order (largest on top) so that pa restores proper order.
	if (ps->stack_b->size == 2 && ps->stack_b->top->value < ps->stack_b->top->next->value)
		sb(ps);
	pa(ps);
	pa(ps);
}
