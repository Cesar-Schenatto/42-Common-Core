#include "push_swap.h"

void	sort_four(t_push_swap *ps)
{
	if (!ps || !ps->stack_a || ps->stack_a->size != 4)
		return;
	push_min_to_b(ps); // Remove smallest
	sort_three(ps);    // Sort the remaining three elements in A
	pa(ps);
}
