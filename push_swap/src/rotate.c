#include "push_swap.h"

// Rotate a stack upwards
void rotate(t_stack *stack)
{
    if (!stack || stack->size < 2)
        return;

    t_node *first = pop(stack);  // Remove the top element
    t_node *current = stack->top;

    // Traverse to the bottom of the stack
    while (current->next)
        current = current->next;

    current->next = first;  // Add the first element to the bottom
    first->next = NULL;     // Update its next pointer
}

// Rotate stack_a upwards
void ra(t_push_swap *ps)
{
    if (ps)
    {
        rotate(ps->stack_a);
        write(1, "ra\n", 3);
    }
}

// Rotate stack_b upwards
void rb(t_push_swap *ps)
{
    if (ps)
    {
        rotate(ps->stack_b);
        write(1, "rb\n", 3);
    }
}

// Rotate both stack_a and stack_b upwards
void rr(t_push_swap *ps)
{
    if (ps)
    {
        rotate(ps->stack_a);
        rotate(ps->stack_b);
        write(1, "rr\n", 3);
    }
}

