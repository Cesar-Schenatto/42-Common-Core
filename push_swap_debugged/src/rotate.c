#include "push_swap.h"

// Rotate a stack upwards
void rotate(t_stack *stack)
{
    if (!stack || stack->size < 2)
        return;
    
    // Save pointer to the first node.
    t_node *first = stack->top;
    // Update the top pointer.
    stack->top = first->next;
    // Isolate the first node.
    first->next = NULL;
    
    // Traverse to the last node.
    t_node *current = stack->top;
    while (current->next)
        current = current->next;
    
    // Append the first node at the bottom.
    current->next = first;
    // Note: Do not modify stack->size (it stays the same)
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

