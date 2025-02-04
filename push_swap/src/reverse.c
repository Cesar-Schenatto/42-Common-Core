#include "push_swap.h"

// Reverse rotate a stack (last element becomes the top)
void reverse_rotate(t_stack *stack)
{
    if (!stack || stack->size < 2)
        return;

    t_node *current = stack->top;
    t_node *prev = NULL;

    // Traverse to the last element
    while (current->next)
    {
        prev = current;
        current = current->next;
    }

    prev->next = NULL;      // Detach the last element
    current->next = stack->top;  // Point it to the top
    stack->top = current;   // Update the top
}

// Reverse rotate stack_a
void rra(t_push_swap *ps)
{
    if (ps)
        {
        reverse_rotate(ps->stack_a);
        write(1, "rra\n", 4);
        }
}

// Reverse rotate stack_b
void rrb(t_push_swap *ps)
{
    if (ps)
    {
        reverse_rotate(ps->stack_b);
        write(1, "rrb\n", 4);
    }
}

// Reverse rotate both stack_a and stack_b
void rrr(t_push_swap *ps)
{
    if (ps)
    {
        reverse_rotate(ps->stack_a);
        reverse_rotate(ps->stack_b);
        write(1, "rrr\n", 4);
    }
}
