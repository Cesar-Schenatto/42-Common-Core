#include "push_swap.h"

void pa(t_push_swap *ps)
{
    if (ps && ps->stack_b->size > 0)
    {
        t_node *node = pop(ps->stack_b);  // Pop the top node from stack_b
        if (node)
        {
            push(ps->stack_a, node);  // Push the node onto stack_a
            write(1, "pa\n", 3);
        }
    }
}

void pb(t_push_swap *ps)
{
    if (ps && ps->stack_a->size > 0)
    {
        t_node *node = pop(ps->stack_a);  // Pop the top node from stack_a
        if (node)
        {
            push(ps->stack_b, node);  // Push the node onto stack_b
            write(1, "pb\n", 3);
        }
    }
}
